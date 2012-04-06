<?php

abstract class ddl_object_base {

abstract public function get_cookie_name();
abstract public function get_cookie_param_list();
abstract public function calculate();

  // damage
  public function get_damage() { return $this->damage_; }
  public function set_damage($v) { $this->damage_ = $v; }



public function load()
{
  // Cookieから情報取得して
  if (false === isset($_COOKIE[$this->get_cookie_name()])) {
    return false;
  }

  // 値を取得
  $s = $_COOKIE[$this->get_cookie_name()];
//var_dump($s);
  $data = json_decode(base64_decode($s), true);
//var_dump($data);

  // setしてまわる
  foreach($this->get_cookie_param_list() as $name) {
    $m = 'set_' . $name;
    $this->$m($data[$name]);
  }

  // 基礎データをもとに算出
  $this->calculate();

  //
  return true;
}


public function save()
{
  //
  $data = array();

  // getしてまわって
  foreach($this->get_cookie_param_list() as $name) {
    $m = 'get_' . $name;
    $data[$name] = $this->$m();
//var_dump($name);
  }
//var_dump($data);

  // cookieに設定する
  $r = setcookie($this->get_cookie_name(), base64_encode(json_encode($data)), time() + 60*60*24*365);
//var_dump($this->get_cookie_name());
//var_dump(json_encode($data));
//var_dump($r);
}


public function delete()
{
  // cookieに設定する
  $r = setcookie($this->get_cookie_name(), '', time() + 60*60*24*365);
}


//private:
private $damage_;

} // end of class
