<?php

require_once('ddl_object_base.inc');

class ddl_monster extends ddl_object_base {

//public:
  // mr
  public function get_mr() { return $this->mr_; }
  public function set_mr($v) { $this->mr_ = $v; }
  // name
  public function get_name() { return $this->name_; }
  public function set_name($v) { $this->name_ = $v; }

//
public function get_cookie_name() { return 'mons'; }
public function get_cookie_param_list() { return array('mr','name','damage'); }

// MR����v�Z����`
public function get_dice() { return (int)($this->get_mr() / 10) + 1; }
public function get_correction() { return (int)(($this->get_mr() - $this->get_damage()) / 2); }

// �\��
public function set_to_conv($conv)
{
  // �P�l����C��
  $conv->monoDic('name', $this->get_name() );
  $conv->monoDic('mr', $this->get_mr() );
  $conv->monoDic('damage', $this->get_damage() );
}

// XXX �c�g��Ȃ����Ȃ�
public function calculate() {}

//private:
private $mr_;
private $damage_;
private $name_;

} // end of class