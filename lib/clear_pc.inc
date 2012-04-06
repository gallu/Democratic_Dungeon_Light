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

class clear_pc extends base_model_sample_front_base {


//処理
public function execute() {
//print "Trap 1\n";

  //
  $req = $this->get_cgi_request();
  $conv = $this->get_conv();

  //
  $chara_obj = new ddl_chara();
  $chara_obj->delete();

  // XXX 多分、作り直し以外に遷移はないと思うんだが…
  $this->set_recursive_command('create_pc');
  $this->recursive_on();
}

} // end of class

