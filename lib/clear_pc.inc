<?php

/***************************************************
 * �g�b�v���
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


//����
public function execute() {
//print "Trap 1\n";

  //
  $req = $this->get_cgi_request();
  $conv = $this->get_conv();

  //
  $chara_obj = new ddl_chara();
  $chara_obj->delete();

  // XXX �����A��蒼���ȊO�ɑJ�ڂ͂Ȃ��Ǝv���񂾂��c
  $this->set_recursive_command('create_pc');
  $this->recursive_on();
}

} // end of class
