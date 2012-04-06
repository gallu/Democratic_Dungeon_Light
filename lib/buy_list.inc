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


class buy_list extends base_model_sample_front_base {


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
  //
  $chara_obj->set_to_conv($conv);

  // ƒ^ƒCƒv‚ð”cˆ¬
  $type = $req->find('type');
  $types = array(
    'weapon' => 1,
    'armor' => 1,
    'shield' => 1,
    'item' => 1,
    'item_consumable' => 1,
  );
  //
  if (false === isset($types[$type])) {
    $this->set_recursive_command('index');
    $this->recursive_on();
    return ;
  }

  //
  $m = "get_{$type}_saled_list";
  $list = item_manager::$m();
//var_dump($list);

  // list‚ð­‚µ®—
  $list_new = array();
  foreach($list as $no => $li) {
    $wk = array();
    foreach($li as $k => $v) {
      //
      if ('' === $v) {
        $v = '-';
      }
      $wk[$k] = $v;
    }
    //
    $wk['no'] = $no;
    $wk['type'] = $type;
//var_dump($wk);

    //
    $list_new[] = $wk;
  }

  //
  $conv->multiDic('item_loop', new simple_loop($list_new));

  //
  return ;
}

} // end of class

