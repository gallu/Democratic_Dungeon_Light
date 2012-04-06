<?php

require_once('view.inc');

class ddl_view extends view
{


protected function make_template_filename()
{
  // 必要なインスタンスげと
  $mobj = $this->get_model_obj();
//var_dump($mobj);

  if (true === $mobj->get_mobile()->is_mobile()) {
    return $mobj->get_config()->find('template_dir') . '/mobile/' . $mobj->get_tmp_filename();;
  }
  // else
  return parent::make_template_filename();
}

protected function output_extra($s) {
//var_dump($s);
  // 必要なインスタンスげと
  $mobj = $this->get_model_obj();
//var_dump($mobj);

  if (true === $mobj->get_mobile()->is_mobile()) {
    $s = mb_convert_encoding($s, 'SJIS-win', 'UTF-8');
  }

  return $s;
}



} // end of class
