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


//処理
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

  // タイプとアイテムnoを把握
  $type = $req->find('type');
  $no = $req->find('no');
  // XXX 非売品っぽい
  if (2000 > $no) {
    $this->set_recursive_command('index');
    $this->recursive_on();
    return ;
  }

  //
  $m = "get_{$type}";
  $item = item_manager::$m($no);
//var_dump($item);

  // 金額が設定されていなければNG
  if (false === isset($item['price'])) {
    $this->set_recursive_command('index');
    $this->recursive_on();
    return ;
  }

  // 手持ちの金額が足りなければ「足りない」表示
//var_dump($chara_obj->get_gold());
//var_dump($chara_obj);
//var_dump($item);
//var_dump($type);
//var_dump($no);
  if ($chara_obj->get_gold() < $item['price']) {
    $conv->multiDic('is_insufficient', new simple_put());
  } else {
    // お金を引いて
    $chara_obj->set_gold( $chara_obj->get_gold() - $item['price']);
//$chara_obj->set_gold( $chara_obj->get_gold() + 500000);

    // アイテム要素取り出して
    $chara_items = $chara_obj->get_item();

    // 装備系なら装備させる
    if ('weapon' === $type) {
      $chara_items['w'] = $no + 0;
    } else
    if ('armor' === $type) {
      $chara_items['a'] = $no + 0;
    }

    // インスタントアイテムなら格納
    if ('item_consumable' === $type) {
//print "ok\n";
//var_dump($chara_items);
      if (false === isset($chara_items['ic'])) {
        $chara_items['ic'] = array();
      }
//var_dump($chara_items);
//var_dump(count($chara_items['ic']));

      // 上限値確認
      if (5 <= count($chara_items['ic'])) {
        // お金戻して
        // XXX データ保存しなきゃいいだけか
        // エラー出力して終了
        $conv->multiDic('is_orver_item_num', new simple_put());
        return ;
      }
      // else
      $chara_items['ic'][] = $no + 0;
      $chara_obj->set_item($chara_items);
//var_dump($chara_items);
    }

//var_dump($chara_items);
    // で、保存
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

