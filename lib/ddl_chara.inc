<?php

require_once('ddl_object_base.inc');
require_once('item_manager.inc');

class ddl_chara extends ddl_object_base {


//public:
  // job
  public function get_job() { return $this->job_; }
  public function set_job($v) { $this->job_ = $v; }
  // gold
  public function get_gold() { return $this->gold_; }
  public function set_gold($v) { $this->gold_ = $v; }
  // exp
  public function get_exp() { return $this->exp_; }
  public function set_exp($v) { $this->exp_ = $v; }
  // name
  public function get_name() { return $this->name_; }
  public function set_name($v) { $this->name_ = $v; }
  // str
  public function get_str() { return $this->str_; }
  public function set_str($v) { $this->str_ = $v; }
  // dex
  public function get_dex() { return $this->dex_; }
  public function set_dex($v) { $this->dex_ = $v; }
  // luk
  public function get_luk() { return $this->luk_; }
  public function set_luk($v) { $this->luk_ = $v; }
  // int
  public function get_int() { return $this->int_; }
  public function set_int($v) { $this->int_ = $v; }
  // con
  public function get_con() { return $this->con_; }
  public function set_con($v) { $this->con_ = $v; }
  // pow
  public function get_pow() { return $this->pow_; }
  public function set_pow($v) { $this->pow_ = $v; }
  // item
  public function get_item() { return $this->item_; }
  public function set_item($v) { $this->item_ = $v; }
  // dice
  public function get_dice() { return $this->dice_; }
  public function set_dice($v) { $this->dice_ = $v; }
  // correction
  public function get_correction() { return $this->correction_; }
  public function set_correction($v) { $this->correction_ = $v; }

  // level
  public function get_level() { return $this->level_; }
  public function set_level($v) { $this->level_ = $v; }
  // item_data
  public function get_item_data() { return $this->item_data_; }
  public function set_item_data($v) { $this->item_data_ = $v; }
  // correction_base
  public function get_correction_base() { return $this->correction_base_; }
  public function set_correction_base($v) { $this->correction_base_ = $v; }
  // defense_point
  public function get_defense_point() { return $this->defense_point_; }
  public function set_defense_point($v) { $this->defense_point_ = $v; }


//
public function get_cookie_name() { return 'chara'; }
public function get_cookie_param_list() { return array('name','str','dex','luk','int','con','pow','item','damage','job','gold','exp',); }


// キャラ作成
public function create()
{
//print "PC create";

  // パラメタ決定
  $awk = array('str', 'dex', 'luk', 'int' ,'con' ,'pow');
  foreach($awk as $status) {
    $m = 'set_' . $status;
    $this->$m( $this->status_dice() );
  }

  // ダメージは作りたてなので０固定
  $this->set_damage(0);
  // その他固定系
  $this->set_job(0); // 一端、戦士一本やり
  $this->set_gold(0); // 手持ちはなし
  $this->set_exp(0); // 経験値も0


  // 装備アイテム決定
  // XXX 一端すげぇ雑にいくかねぇ？
  $item = array();
  if (1 === rand(0, 100)) {
    $item['w'] = rand(0, 12) + 1000;
  } else {
    $item['w'] = rand(0, 32);
  }

  if (1 === rand(0, 100)) {
    $item['a'] = rand(0, 2) + 1000;
  } else {
    $item['a'] = rand(0, 19);
  }

  if (1 === rand(0, 100)) {
    $item['i'] = rand(0, 4) + 1000;
  } else {
    $item['i'] = rand(0, 18);
  }

  //
  $this->set_item($item);

  // データの計算
  $this->calculate();
//var_dump($this);

  //
  return true;
}


// 基礎データからの算出
public function calculate()
{
  // レベルの算出
  $lv1 = (int)($this->get_str() / 10) + 1;
  $lv2 = (int)($this->get_dex() / 10) + 1;
  $lv3 = (int)($this->get_luk() / 10) + 1;
  //
  $l = ($lv1 > $lv2) ? $lv1 : $lv2;
  $l = ($l   > $lv3) ? $l   : $lv3;
  //
  $this->set_level($l);

  // アイテム情報の取得
  $item = $this->get_item();
  //
  $item_data = array();
  $item_data['w'] = item_manager::get_weapon($item['w']);
  $item_data['a'] = item_manager::get_armor($item['a']);
  $item_data['i'] = item_manager::get_item($item['i']);
  $this->set_item_data($item_data);

  // 個人修正の算出
  $c = 0;
  //$awk = array('str', 'dex', 'luk', 'int');
  $awk = array('str', 'dex', 'luk');
  foreach($awk as $s) {
    // 元値の把握
    $m = 'get_' . $s;
    $i = $this->$m();
    // プラス修正
    if (12 <= $i) {
      $c += ($i - 12);
    } else
    if (9 >= $i) {
      $c -= (9 - $i);
    }
  }
  // レベルを加算しておく
  $c += $this->get_level();

  //
  $this->set_correction_base($c);

  // 最終的な「ロール用数値」の算出
  // 個人修正の確認
  $correction = $this->get_correction_base();
  $dice = 0;
  $dp = 0;
  // ダイスのスケールアップ処理
  // XXX 「ほんのりとしたスケールアップ」に修正
  if (3 <= $correction) {
    /*
    $dice = (int)($correction / 3);
    $correction = $correction % 3;
    */
    $dice = (int)($correction / 6);
    $correction = $correction - ($dice * 3);
  }

  // 装備の確認
  $item_data = $this->get_item_data();
  foreach($item_data as $i) {
    // 攻撃力修正
    if ('' !== $i['damage']) {
      // 分割して
      list($a, $b) = explode('D', $i['damage']);

      // 足しこむ：武器の修正はスケールアップさせない
      $dice += $a;
      $correction += $b;
    }

    // 防御力修正
    if ('' !== $i['defense']) {
      $dp += $i['defense'];
    }
  }
  // 防御点は２倍
  // XXX あとで、職業チェックするかねぇ？
  $dp *= 2;

  // 設定
  $this->set_dice($dice);
  $this->set_correction($correction);
  $this->set_defense_point($dp);
}

public function set_to_conv($conv)
{
  // 単値を一気に
  $conv->monoDic('name', $this->get_name() );
  $conv->monoDic('str', $this->get_str() );
  $conv->monoDic('dex', $this->get_dex() );
  $conv->monoDic('luk', $this->get_luk() );
  $conv->monoDic('int', $this->get_int() );
  $conv->monoDic('con', $this->get_con() );
  $conv->monoDic('pow', $this->get_pow() );
  $conv->monoDic('damage', $this->get_damage() );
  $conv->monoDic('level', $this->get_level() );
  $conv->monoDic('correction_base', $this->get_correction_base() );
  $conv->monoDic('dice', $this->get_dice() );
  $conv->monoDic('correction', $this->get_correction() );
  $conv->monoDic('defense_point', $this->get_defense_point() );
  $conv->monoDic('job', $this->get_job() );
  $conv->monoDic('gold', $this->get_gold() );
  $conv->monoDic('exp', $this->get_exp() );

  // 職業：別箇所に切り出す？
  $job_names = array( '戦士' );
  $conv->monoDic('job_name', $job_names[$this->get_job()] );

  // 配列系、どうしよ？ 一端べたっといきますか
  $item_data = $this->get_item_data();
  $item = $this->get_item();
  //
  $awk = array('w' => 'weapon', 'a' => 'armor', 'i' => 'item');
  foreach($awk as $n => $v) {
    $conv->monoDic($v . '_name', $item_data[$n]['name']);
    $conv->monoDic($v . '_id', $item[$n]);
    //
    $s = $item_data[$n]['damage'];
    if ('' === $s) { $s = '-'; }
    $conv->monoDic($v . '_damage', $s);

    $s = $item_data[$n]['defense'];
    if ('' === $s) { $s = '-'; }
    $conv->monoDic($v . '_defense', $s);
  }
//var_dump($conv);

  // 消耗アイテム
  if (true === empty($item['ic'])) {
    $conv->monoDic('item_c_name', 'なし');
  } else {
require_once('item_manager.inc');
    //
    $s = array();
    foreach($item['ic'] as $i) {
      $wk = item_manager::get_item_consumable($i);
      $s[] = $wk['name'];
    }
//var_dump($s);
    //
    $conv->monoDic('item_c_name', implode(', ', $s) );
  }
}


// 内部用関数
// status用：「ぞろ目なら振り足し」な3D6
protected function status_dice()
{
  $i = 0;
  do {
    //
    $flg = false;
    //
    $d1 = mt_rand(1,6);
    $d2 = mt_rand(1,6);
    $d3 = mt_rand(1,6);
    //
    if ($d1 === $d2 and $d2 === $d3) {
      $flg = true;
    }
    //
    $i += $d1 + $d2 + $d3;
  } while($flg);
  //
  return $i;
}

//private:
private $name_;
private $str_;
private $dex_;
private $luk_;
private $int_;
private $con_;
private $pow_;
private $item_;
private $dice_;
private $correction_;
//
private $level_;
private $item_data_;
private $correction_base_;
private $defense_point_;
//
private $job_;
private $gold_;
private $exp_;

} // end of class

