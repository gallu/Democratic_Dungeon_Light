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

class view_pc extends base_model_sample_front_base {


//ˆ—
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

  // •\Ž¦
  $chara_obj->set_to_conv($conv);

  //
  return ;
}

} // end of class

