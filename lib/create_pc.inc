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

class create_pc extends base_model_sample_front_base {


//処理
public function execute() {
//print "Trap 1\n";

  //
  $req = $this->get_cgi_request();
  $conv = $this->get_conv();

  //
  $chara_obj = new ddl_chara();
  $chara_obj->create();

  // 表示
  $chara_obj->set_to_conv($conv);

  // 問答無用で保存して
  $chara_obj->save();

  //
  return ;
}

} // end of class

