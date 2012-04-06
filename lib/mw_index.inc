<?php

/***************************************************
 * トップ画面
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
require_once('ddl_chara.inc');
require_once('ddl_monster.inc');


class mw_index extends base_model_sample_front_base {


//処理
public function execute() {
//print "Trap 1\n";

  //
  $req = $this->get_cgi_request();
  $conv = $this->get_conv();

  //
  $chara_obj = new ddl_chara();
  if (false === $chara_obj->load()) {
    $conv->multiDic('is_nochara', new simple_put());
    return ;
  }
  // else
  $conv->multiDic('is_chara', new simple_put());

  //
  $mons_obj = new ddl_monster();
  if (false === $mons_obj->load()) {
    // ふつ〜にテンプレート表示
    $s = $req->find_cookie('mr_base');
//var_dump($s);
    if ('' !== $s) {
      conv_util::monoDicSelected($conv, 'mr_base', $s);
    }

    //
    return ;
  }

  // else
require_once('battle.inc');
  $bobj = new battle();
  $bobj->set_chara($chara_obj);
  $bobj->set_monster($mons_obj);
  $bobj->set_item_consumable($req->find('item_consumable'));
  $r = $bobj->battle_main($conv);

  // アイテムの選択肢を作っておく
require_once('item_manager.inc');
  $items = $chara_obj->get_item();
  if (true === isset($items['ic'])) {
    $awk = $items['ic'];
    $data = array();
    foreach($awk as $no => $item_no) {
      $idata = item_manager::get_item_consumable($item_no);
      $wk = array();
      $wk['name'] = $idata['name'];
      $wk['no'] = $no;
      //
      $data[] = $wk;
    }
    $conv->multiDic('item_consumable_loop', new simple_loop($data));
  }

  //
  $this->set_tmp_filename('battle.tpl');

  //
  if (true === $bobj->is_fin()) {
    // モンスター情報を削除
    $mons_obj->delete();
    // ダメージ回復
    $chara_obj->set_damage(0);
  } else {
    // 状況をsave
    $mons_obj->save();
  }
  // キャラはいずれにしてもこのタイミングでsave
  $chara_obj->save();

  //
  return ;
}

} // end of class

