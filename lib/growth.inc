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
require_once('ddl_chara.inc');

class growth extends base_model_sample_front_base {


//処理
public function execute() {
//print "Trap 1\n";

  // 係数
  $growth_coefficient = 10;

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

  // パラメタの指定があったら成長判定
  $target_param = $req->find('tp');
//var_dump($target_param);

  $param_base = array('str' => 1, 'dex' => 1, 'luk' => 1, 'int' => 1, 'con' => 1, 'pow' => 1);
  if (true === isset($param_base[$target_param])) {
    //
    $get_m = 'get_' . $target_param;
    $set_m = 'set_' . $target_param;

    // 現在値把握
    $i = $chara_obj->$get_m();

    // 必要経験値の算出
    $need_exp = $i * $growth_coefficient;

    // 問題無ければ成長
    if ($chara_obj->get_exp() >= $need_exp) {
      // 経験値を減算
      $chara_obj->set_exp($chara_obj->get_exp() - $need_exp);

      // 対象能力値を加算
      $chara_obj->$set_m($chara_obj->$get_m() + 1);

      // 表示用に再計算
      $chara_obj->calculate();

      // 保存
      $chara_obj->save();

      //
      $conv->multiDic('growth_success', new simple_put());
    } else {
      // 経験値足りなければエラーメッセージ
      $conv->multiDic('growth_failure', new simple_put());

      //
      $conv->monoDic('need_exp', $need_exp);
    }
  }

  // 表示
  $chara_obj->set_to_conv($conv);

  // next経験点の追加
  $conv->monoDic('next_str', $chara_obj->get_str() * $growth_coefficient);
  $conv->monoDic('next_dex', $chara_obj->get_dex() * $growth_coefficient);
  $conv->monoDic('next_luk', $chara_obj->get_luk() * $growth_coefficient);
  $conv->monoDic('next_int', $chara_obj->get_int() * $growth_coefficient);
  $conv->monoDic('next_con', $chara_obj->get_con() * $growth_coefficient);
  $conv->monoDic('next_pow', $chara_obj->get_pow() * $growth_coefficient);

  //
  return ;
}

} // end of class

