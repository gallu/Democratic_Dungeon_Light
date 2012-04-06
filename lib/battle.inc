<?php


class battle
{

//public:
  // chara
  public function get_chara() { return $this->chara_; }
  public function set_chara($v) { $this->chara_ = $v; }
  //
  public function get_item_consumable() { return $this->item_consumable_; }
  public function set_item_consumable($v) { $this->item_consumable_ = $v; }
  // monster
  public function get_monster() { return $this->monster_; }
  public function set_monster($v) { $this->monster_ = $v; }

//
public function is_fin() { return (0 !== $this->flg_); }
//
public function is_win() { return (1 === $this->flg_); }
public function is_lose() { return (2 === $this->flg_); }
public function is_tie() { return (3 === $this->flg_); }

//
public function battle_main($conv)
{
  // アイテム関連
  // アイテム指定、ある？
  $item_consumable = $this->get_item_consumable();
  if ('' !== $item_consumable) {
//var_dump($item_consumable);
//print "ok\n";

    // アイテムを取り出す
    $items = $this->get_chara()->get_item();
//var_dump($items);

    // アイテム、ある？
    if ( false === isset($items['ic'][$item_consumable]) ) {
      // 指定されたアイテム、ないぽだよ？
      $conv->multiDic('no_items', new simple_put());
    }
    // アイテムあった～ ノ
    else {
require_once('item_manager.inc');

      // アイテムを把握
      $item_data = item_manager::get_item_consumable($items['ic'][$item_consumable]);
//var_dump($item_data);

      // 効果関数を把握
      $awk = explode(',', $item_data['function_string']);
      $effect = array();
      foreach($awk as $s) {
        // XXX 一端、プラスのみを想定
        list($n, $v) = explode('+', $s);
        $effect[$n] = $v;
        //
        $conv->multiDic('effect_' . $n, new simple_put());
      }
//var_dump($effect);

      // アイテムは消耗しておく
      unset($items['ic'][$item_consumable]);
      $items['ic'] = array_values($items['ic']);
      $this->get_chara()->set_item($items);
    }
  }

  // 治療
  if (true === isset($effect['heal'])) {
//print "head {$effect['heal']} point\n";
//var_dump($this->get_chara()->get_damage());
    $d = $this->get_chara()->get_damage() - $effect['heal'];
    if (0 > $d) {
      $d = 0;
    }
    // ダメージ値を入れなおす
    $this->get_chara()->set_damage($d);
//var_dump($this->get_chara()->get_damage());
  }


  // キャラ側ダイス振る
//var_dump($this->get_chara()->get_dice());
  $dice = $this->get_chara()->get_dice();
  if (true === isset($effect['attack'])) {
//print "attack +{$effect['attack']}\n";
    // ダイスを加算
    $dice += $effect['attack'];
  }
  $chara_dice = $this->dice($dice);
//var_dump($chara_dice);

  // モンス側ダイスふる
//var_dump($this->get_monster()->get_dice());
  $mons_dice = $this->dice($this->get_monster()->get_dice());
//var_dump($mons_dice);

  // ダメージ基本値取得
  $c_base = $chara_dice['total'] + $this->get_chara()->get_correction(); // PC側の基準値
  $m_base = $mons_dice['total'] + $this->get_monster()->get_correction(); // モンスター側の基準値
//var_dump($c_base);
//var_dump($m_base);

  //
  $c_damage = 0; // キャラクタがうけるべきダメージ
  $m_damage = 0; // モンスターがうけるべきダメージ

  if ($c_base >= $m_base) {
    // モンスター側にダメージ！！
    $m_damage = $c_base - $m_base;
  } else {
    // PC側にダメージ orz
    $c_damage = $m_base - $c_base - $this->get_chara()->get_defense_point();
    if (0 > $c_damage) {
      $c_damage = 0;
    }
  }
//var_dump($c_damage);
//var_dump($m_damage);

  // 悪意ダメージ加算：キャラ
  $c_damage += $mons_dice['malice'];
  // 悪意ダメージ加算：モンス
  $m_damage += $chara_dice['malice'];
//var_dump($c_damage);
//var_dump($m_damage);

  // 毒適用
  if (true === isset($effect['damage'])) {
//print "poison +{$effect['damage']}\n";
    // ダイスを加算
    $m_damage += $effect['damage'];
  }


  // ダメージ適用
  $this->get_chara()->set_damage( $this->get_chara()->get_damage() + $c_damage );
  $this->get_monster()->set_damage( $this->get_monster()->get_damage() + $m_damage );

  // 勝敗確認
  if ($this->get_monster()->get_damage() >= $this->get_monster()->get_mr()) {
    $this->flg_ += 1;
  }
  if ($this->get_chara()->get_damage() >= $this->get_chara()->get_con()) {
    $this->flg_ += 2;
  }

  // 終わった？
  if (1 === $this->flg_) {
    // 勝利したら経験値とお金
    $conv->multiDic('if_win', new simple_put());
    //
    $conv->monoDic('add_exp', $this->get_monster()->get_mr());
    $g = mt_rand(1, $this->get_monster()->get_mr());
    // 時々倍率
    if (1 === mt_rand(1, 64)) {
      $g *= 2;
    } else
    if (1 === mt_rand(1, 256)) {
      $g *= 10;
    } else
    if (1 === mt_rand(1, 65536)) {
      $g *= 1000;
    }
    $conv->monoDic('add_gold', $g);
    //
    $this->get_chara()->set_exp( $this->get_chara()->get_exp() + $this->get_monster()->get_mr());
    $this->get_chara()->set_gold( $this->get_chara()->get_gold() + $g);
  }
  if (2 === $this->flg_) {
    $conv->multiDic('if_lose', new simple_put());
  }
  if (3 === $this->flg_) {
    // ドローなら、半分だけもらえる
    $conv->multiDic('if_draw', new simple_put());
    //
    $exp = (int)($this->get_monster()->get_mr() / 2);
    $conv->monoDic('add_exp', $exp);
    $g = mt_rand(1, (int)($this->get_monster()->get_mr() / 2));
    $conv->monoDic('add_gold', $g);
    //
    $this->get_chara()->set_exp( $this->get_chara()->get_exp() + $exp);
    $this->get_chara()->set_gold( $this->get_chara()->get_gold() + $g);
  }

  //
  if (0 === $this->flg_) {
    $conv->multiDic('if_no_fin', new simple_put());
  } else {
    $conv->multiDic('if_fin', new simple_put());
  }


  // convに色々と値を入れておく
//var_dump( $this->get_chara() );
//var_dump( $this->get_monster() );

  //
  $s = implode(' ', $chara_dice['dice']);
  $s = str_replace('6', '<font color="#aa0000">6</font>', $s);
  $conv->monoDic_unsecure_raw('pc_dice_list', $s);
  //
  $s = implode(' ', $mons_dice['dice']);
  $s = str_replace('6', '<font color="#aa0000">6</font>', $s);
  $conv->monoDic_unsecure_raw('mons_dice_list', $s);

  //
  $conv->monoDic('monster_name', $this->get_monster()->get_name());
  $conv->monoDic('pc_damage', $c_damage);
  $conv->monoDic('mons_damage', $m_damage);
  $conv->monoDic('pc_malice_damage', $mons_dice['malice']);
  $conv->monoDic('mons_malice_damage', $chara_dice['malice']);
  //
  $conv->monoDic('pc_con', $this->get_chara()->get_con());
  $conv->monoDic('pc_hp', $this->get_chara()->get_con() - $this->get_chara()->get_damage());
  //
  $conv->monoDic('mons_mr', $this->get_monster()->get_mr());
  $conv->monoDic('mons_hp', $this->get_monster()->get_mr() - $this->get_monster()->get_damage());

  //
  return;
}

// return
//  'total' => ダイス目合計
//  'malice' => 悪意ダメージ数
//  'dice' => 全ダイスの目
protected function dice($num)
{
  //
  $ret = array();
  $ret['total'] = 0;
  $ret['malice'] = 0;
  $ret['dice'] = array();
  //
  for($i = 0; $i < $num; $i ++) {
    $d = mt_rand(1,6);
    $ret['total'] += $d;
    $ret['dice'][] = $d;
    //
    if (6 === $d) {
      $ret['malice'] ++;
    }
  }
  //
  return $ret;
}


//private
private $item_consumable_ = '';
private $chara_ = null;
private $monster_ = null;
private $flg_ = 0;

} // end of class
