<?php

/***************************************************
 *
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_sample_front_base.inc');
require_once('conv_util.inc');
require_once('item_manager.inc');
require_once('ddl_chara.inc');


class buy_fin extends base_model_sample_front_base {


//����
public function execute() {
//print "Trap 1\n";

  //
  $req = $this->get_cgi_request();
  $conv = $this->get_conv();

  //
  $chara_obj = new ddl_chara();
  if (false === $chara_obj->load()) {
    $this->set_recursive_command('_create_pc');
    $this->recursive_on();
    return ;
  }

  // �^�C�v�ƃA�C�e��no��c��
  $type = $req->find('type');
  $no = $req->find('no');
  // XXX �񔄕i���ۂ�
  if (2000 > $no) {
    $this->set_recursive_command('index');
    $this->recursive_on();
    return ;
  }

  //
  $m = "get_{$type}";
  $item = item_manager::$m($no);
//var_dump($item);

  // ���z���ݒ肳��Ă��Ȃ����NG
  if (false === isset($item['price'])) {
    $this->set_recursive_command('index');
    $this->recursive_on();
    return ;
  }

  // �莝���̋��z������Ȃ���΁u����Ȃ��v�\��
//var_dump($chara_obj->get_gold());
//var_dump($chara_obj);
//var_dump($item);
//var_dump($type);
//var_dump($no);
  if ($chara_obj->get_gold() < $item['price']) {
    $conv->multiDic('is_insufficient', new simple_put());
  } else {
    // ������������
    $chara_obj->set_gold( $chara_obj->get_gold() - $item['price']);
//$chara_obj->set_gold( $chara_obj->get_gold() + 500000);

    // �A�C�e���v�f���o����
    $chara_items = $chara_obj->get_item();

    // �����n�Ȃ瑕��������
    if ('weapon' === $type) {
      $chara_items['w'] = $no + 0;
    } else
    if ('armor' === $type) {
      $chara_items['a'] = $no + 0;
    }

    // �C���X�^���g�A�C�e���Ȃ�i�[
    if ('item_consumable' === $type) {
//print "ok\n";
//var_dump($chara_items);
      if (false === isset($chara_items['ic'])) {
        $chara_items['ic'] = array();
      }
//var_dump($chara_items);
//var_dump(count($chara_items['ic']));

      // ����l�m�F
      if (5 <= count($chara_items['ic'])) {
        // �����߂���
        // XXX �f�[�^�ۑ����Ȃ��Ⴂ��������
        // �G���[�o�͂��ďI��
        $conv->multiDic('is_orver_item_num', new simple_put());
        return ;
      }
      // else
      $chara_items['ic'][] = $no + 0;
      $chara_obj->set_item($chara_items);
//var_dump($chara_items);
    }

//var_dump($chara_items);
    // �ŁA�ۑ�
    $chara_obj->set_item($chara_items);
    //$chara_obj->calculate();
//var_dump($chara_obj);
    $chara_obj->save();

    //
    $conv->monoDic('item_name', $item['name']);
    $conv->multiDic('is_sufficient', new simple_put());
  }

  //
  return ;
}

} // end of class
