<?php


class item_manager {


static protected function _get($name, $id)
{
  // XXX
  if (2000 <= $id) {
    $name = $name . 'saled_';
  }

  if (false === isset(self::${$name}[$id])) {
    return array( 'name' => '存在しないなにか', 'damage' => '', 'defense' => '');
  }
  // else
  return self::${$name}[$id];
}

static public function get_weapon($id)
{
  return self::_get('weapon_', $id);
}

static public function get_armor($id)
{
  return self::_get('armor_', $id);
}

static public function get_item($id)
{
  return self::_get('item_', $id);
}

static public function get_item_consumable($id)
{
  return self::_get('item_consumable_', $id);
}

// お商売品の一覧
static public function get_weapon_saled_list() { return self::$weapon_saled_; }
static public function get_armor_saled_list() { return self::$armor_saled_; }
static public function get_item_saled_list() { return self::$item_saled_; }
static public function get_shield_saled_list() { return self::$shield_saled_; }
static public function get_item_consumable_saled_list() { return self::$item_consumable_saled_; }


//private
//武器
static private $weapon_ = array(
  array( 'name' => 'ナイフ', 'damage' => '2D', 'defense' => ''),
  array( 'name' => 'ダガー', 'damage' => '2D+1', 'defense' => ''),
  array( 'name' => '峨嵋刺', 'damage' => '2D+2', 'defense' => ''),
  array( 'name' => 'クックリ', 'damage' => '2D+3', 'defense' => ''),
  array( 'name' => 'カタール', 'damage' => '2D+4', 'defense' => ''),
  array( 'name' => '日月風火圏', 'damage' => '2D+5', 'defense' => ''),
  array( 'name' => 'ショートソード', 'damage' => '3D', 'defense' => ''),
  array( 'name' => 'ソード', 'damage' => '3D+3', 'defense' => ''),
  array( 'name' => 'ロングソード', 'damage' => '4D', 'defense' => ''),
  array( 'name' => 'バスタードソード', 'damage' => '5D', 'defense' => ''),
  array( 'name' => 'グレートソード', 'damage' => '6D+6', 'defense' => ''),
  array( 'name' => 'フランベルジュ', 'damage' => '6D+10', 'defense' => ''),
  array( 'name' => 'ハンドアックス', 'damage' => '3D', 'defense' => ''),
  array( 'name' => 'バトルアックス', 'damage' => '5D', 'defense' => ''),
  array( 'name' => 'グレートアックス', 'damage' => '7D', 'defense' => ''),
  array( 'name' => 'ハルバード', 'damage' => '7D+2', 'defense' => ''),
  array( 'name' => 'スピア', 'damage' => '3D+1', 'defense' => ''),
  array( 'name' => '流星錘', 'damage' => '3D+5', 'defense' => ''),
  array( 'name' => 'バトルハンマー', 'damage' => '3D', 'defense' => ''),
  array( 'name' => '金瓜錘', 'damage' => '3D+3', 'defense' => ''),
  array( 'name' => 'メイス', 'damage' => '4D', 'defense' => ''),
  array( 'name' => 'フレイル', 'damage' => '4D+4', 'defense' => ''),
  array( 'name' => 'ブラックジャック', 'damage' => '3D', 'defense' => ''),
  array( 'name' => 'ショートボウ', 'damage' => '2D+4', 'defense' => ''),
  array( 'name' => 'ボウ', 'damage' => '3D+6', 'defense' => ''),
  array( 'name' => 'コンジットボウ', 'damage' => '3D+10', 'defense' => ''),
  array( 'name' => '長弓', 'damage' => '4D+2', 'defense' => ''),
  array( 'name' => 'クロスボウ', 'damage' => '5D', 'defense' => ''),
  array( 'name' => 'クレインクインクロスボウ', 'damage' => '8D', 'defense' => ''),
  array( 'name' => '小太刀', 'damage' => '3D+3', 'defense' => ''),
  array( 'name' => '大太刀', 'damage' => '4D+4', 'defense' => ''),
  array( 'name' => '中脇差', 'damage' => '6D+6', 'defense' => ''),
  array( 'name' => '大脇差', 'damage' => '7D+7', 'defense' => ''),

'1000' =>
  array( 'name' => 'ふぁんがむんが', 'damage' => '15D+10', 'defense' => ''),
  array( 'name' => 'エクスカリぱー', 'damage' => '5D', 'defense' => ''),
  array( 'name' => 'エクスカリバー', 'damage' => '12D+10', 'defense' => ''),
  array( 'name' => 'ガラティン', 'damage' => '12D+10', 'defense' => ''),
  array( 'name' => 'グングニル', 'damage' => '18D', 'defense' => ''),
  array( 'name' => '岩融', 'damage' => '10D+25', 'defense' => ''),
  array( 'name' => 'ミョルニル', 'damage' => '18D', 'defense' => ''),
  array( 'name' => '如意金箍棒', 'damage' => '14D+10', 'defense' => ''),
  array( 'name' => '雷上動', 'damage' => '22D', 'defense' => ''),
  array( 'name' => '与一の弓', 'damage' => '18D', 'defense' => ''),
  array( 'name' => '天叢雲剣', 'damage' => '18D+36', 'defense' => ''),
  array( 'name' => '三鈷剣', 'damage' => '30D+30', 'defense' => ''),
  array( 'name' => '七支刀', 'damage' => '40D', 'defense' => ''),

);

static private $weapon_saled_ = array(
'2000' =>
  array( 'name' => 'バスタードソード', 'damage' => '5D', 'defense' => '', 'price' => '150'),
  array( 'name' => 'バトルハンマー', 'damage' => '6D', 'defense' => '', 'price' => '210'),
  array( 'name' => 'グレートアックス', 'damage' => '7D', 'defense' => '', 'price' => '300'),
  array( 'name' => 'クレインクインクロスボウ', 'damage' => '8D', 'defense' => '', 'price' => '600'),
  array( 'name' => '量産型如意金箍棒', 'damage' => '9D', 'defense' => '', 'price' => '800'),
  array( 'name' => '量産型岩融', 'damage' => '10D', 'defense' => '', 'price' => '1200'),
  array( 'name' => '量産型ミョルニル', 'damage' => '11D', 'defense' => '', 'price' => '1800'),
  array( 'name' => '量産型エクスカリバー', 'damage' => '12D', 'defense' => '', 'price' => '2400'),
  array( 'name' => '量産型与一の弓', 'damage' => '13D', 'defense' => '', 'price' => '3000'),
  array( 'name' => '量産型天叢雲剣', 'damage' => '14D', 'defense' => '', 'price' => '3600'),
  array( 'name' => '量産型グングニル', 'damage' => '15D', 'defense' => '', 'price' => '4200'),
  array( 'name' => 'ミョルニル改', 'damage' => '20D', 'defense' => '', 'price' => '10000'),
  array( 'name' => 'エクスカリバー改', 'damage' => '25D', 'defense' => '', 'price' => '15000'),
  array( 'name' => '量産型三鈷剣', 'damage' => '30D', 'defense' => '', 'price' => '20000'),
  array( 'name' => '量産型七支刀', 'damage' => '35D', 'defense' => '', 'price' => '25000'),
  array( 'name' => '七支刀', 'damage' => '40D', 'defense' => '', 'price' => '30000'),
  array( 'name' => '七支刀改', 'damage' => '50D', 'defense' => '', 'price' => '40000'),
  array( 'name' => '特化型ふぁんがむんが', 'damage' => '100D', 'defense' => '', 'price' => '9999999'),
);


// 鎧
static private $armor_ = array(
  array( 'name' => 'ローブ', 'damage' => '', 'defense' => '1'),
  array( 'name' => 'ハイドアーマー', 'damage' => '', 'defense' => '2'),
  array( 'name' => '軽量皮鎧', 'damage' => '', 'defense' => '3'),
  array( 'name' => '革鎧', 'damage' => '', 'defense' => '4'),
  array( 'name' => 'レザーアーマー', 'damage' => '', 'defense' => '5'),
  array( 'name' => 'リングメイル', 'damage' => '', 'defense' => '7'),
  array( 'name' => '鱗鎧', 'damage' => '', 'defense' => '8'),
  array( 'name' => 'スケールメール', 'damage' => '', 'defense' => '9'),
  array( 'name' => 'ラメラーアーマー', 'damage' => '', 'defense' => '9'),
  array( 'name' => 'ロリカハマタ', 'damage' => '', 'defense' => '10'),
  array( 'name' => 'コートオブプレート', 'damage' => '', 'defense' => '11'),
  array( 'name' => 'チェーンメイル', 'damage' => '', 'defense' => '12'),
  array( 'name' => '鎖帷子', 'damage' => '', 'defense' => '13'),
  array( 'name' => 'ロリカセグメンタタ', 'damage' => '', 'defense' => '14'),
  array( 'name' => 'ブリガンダイン', 'damage' => '', 'defense' => '15'),
  array( 'name' => 'ブレストプレート', 'damage' => '', 'defense' => '16'),
  array( 'name' => '重装鎧', 'damage' => '', 'defense' => '17'),
  array( 'name' => 'プレートアーマー', 'damage' => '', 'defense' => '18'),
  array( 'name' => 'フルプレート', 'damage' => '', 'defense' => '20'),
  array( 'name' => 'マクシミリアン', 'damage' => '', 'defense' => '23'),

'1000' =>
  array( 'name' => '薄金', 'damage' => '', 'defense' => '30'),
  array( 'name' => '楯無', 'damage' => '', 'defense' => '35'),
  array( 'name' => '避来矢', 'damage' => '', 'defense' => '40'),
);


static private $armor_saled_ = array(
'2000' =>
  array( 'name' => 'ブリガンダイン', 'damage' => '', 'defense' => '15', 'price' => '200'), 
  array( 'name' => 'フルプレート', 'damage' => '', 'defense' => '20', 'price' => '1000'), 
  array( 'name' => 'ミスリルチェイン', 'damage' => '', 'defense' => '25', 'price' => '5000'), 
  array( 'name' => '薄金', 'damage' => '', 'defense' => '30', 'price' => '10000'), 
  array( 'name' => '楯無', 'damage' => '', 'defense' => '35', 'price' => '15000'), 
  array( 'name' => '避来矢', 'damage' => '', 'defense' => '40', 'price' => '30000'), 
  array( 'name' => 'ミスリルプレート', 'damage' => '', 'defense' => '45', 'price' => '50000'), 
  array( 'name' => 'ドワーブンチェイン', 'damage' => '', 'defense' => '50', 'price' => '100000'), 
);

// 持ち物
static private $item_ = array(
  array( 'name' => '砥石', 'damage' => '0D+1', 'defense' => ''),
  array( 'name' => '毛布', 'damage' => '', 'defense' => ''),
  array( 'name' => '柔らかいブーツ', 'damage' => '', 'defense' => '1'),
  array( 'name' => 'マント', 'damage' => '', 'defense' => '1'),
  array( 'name' => '麻の下着', 'damage' => '', 'defense' => '1'),
  array( 'name' => '布製の帽子', 'damage' => '', 'defense' => '1'),
  array( 'name' => '飾り帯', 'damage' => '0D+1', 'defense' => ''),
  array( 'name' => '小さな鉄箱', 'damage' => '', 'defense' => ''),
  array( 'name' => 'マッチ', 'damage' => '', 'defense' => ''),
  array( 'name' => '火口箱', 'damage' => '', 'defense' => ''),
  array( 'name' => 'ランタン', 'damage' => '', 'defense' => ''),
  array( 'name' => 'インクと羽ペン', 'damage' => '', 'defense' => ''),
  array( 'name' => '麻のロープ', 'damage' => '', 'defense' => ''),
  array( 'name' => '羊皮紙', 'damage' => '', 'defense' => ''),
  array( 'name' => 'ろうそく', 'damage' => '0D+1', 'defense' => ''),
  array( 'name' => '水袋', 'damage' => '', 'defense' => ''),
  array( 'name' => '10フィート棒', 'damage' => '', 'defense' => ''),
  array( 'name' => '11フィート棒', 'damage' => '', 'defense' => ''),
  array( 'name' => 'くさび', 'damage' => '', 'defense' => ''),

'1000' =>
  array( 'name' => 'ペガサス', 'damage' => '2D+10', 'defense' => ''),
  array( 'name' => 'ゲイボルグ', 'damage' => '10D+2', 'defense' => ''),
  array( 'name' => '黄金のリンゴ', 'damage' => '3D+3', 'defense' => '5'),
  array( 'name' => 'イリヤの蜂蜜', 'damage' => '', 'defense' => '10'),
  array( 'name' => 'メディアの薬', 'damage' => '', 'defense' => '15'),
);

static private $shield_saled_ = array(
'2000' =>
  array( 'name' => '布手甲', 'damage' => '', 'defense' => '1', 'price' => '100'), 
  array( 'name' => 'ランタンシールド', 'damage' => '', 'defense' => '2', 'price' => '400'), 
  array( 'name' => 'バックラー', 'damage' => '', 'defense' => '3', 'price' => '1000'), 
  array( 'name' => '籐牌', 'damage' => '', 'defense' => '4', 'price' => '1400'), 
  array( 'name' => 'スパルタンシールド', 'damage' => '', 'defense' => '5', 'price' => '2000'), 
  array( 'name' => '団牌', 'damage' => '', 'defense' => '6', 'price' => '3000'), 
  array( 'name' => 'スクトゥム', 'damage' => '', 'defense' => '7', 'price' => '4000'), 
  array( 'name' => 'デュエリングシールド', 'damage' => '', 'defense' => '8', 'price' => '5500'), 
  array( 'name' => 'ナイトシールド', 'damage' => '', 'defense' => '9', 'price' => '7000'), 
  array( 'name' => 'タワーシールド', 'damage' => '', 'defense' => '10', 'price' => '9000'), 
);


// 消耗アイテム
static private $item_consumable_saled_ = array(
'2000' =>
  array( 'name' => '即席魔化1', 'function_string' => 'attack+1', 'price' => '10' ),
  array( 'name' => '即席魔化5', 'function_string' => 'attack+5', 'price' => '200' ),
  array( 'name' => '即席魔化10', 'function_string' => 'attack+10', 'price' => '500' ),
  array( 'name' => '即席魔化15', 'function_string' => 'attack+15', 'price' => '1200' ),
  array( 'name' => '即席魔化20', 'function_string' => 'attack+02', 'price' => '2000' ),
  array( 'name' => '即席魔化30', 'function_string' => 'attack+30', 'price' => '4000' ),
  array( 'name' => '即席魔化50', 'function_string' => 'attack+50', 'price' => '10000' ),
  array( 'name' => '龍毒1', 'function_string' => 'damage+1', 'price' => '10' ),
  array( 'name' => '龍毒5', 'function_string' => 'damage+5', 'price' => '200' ),
  array( 'name' => '龍毒10', 'function_string' => 'damage+7', 'price' => '500' ),
  array( 'name' => '龍毒25', 'function_string' => 'damage+8', 'price' => '3000' ),
  array( 'name' => '龍毒50', 'function_string' => 'damage+9', 'price' => '10000' ),
  array( 'name' => '龍毒100', 'function_string' => 'damage+10', 'price' => '50000' ),
  array( 'name' => 'イシスの薬1', 'function_string' => 'heal+1', 'price' => '1' ),
  array( 'name' => 'イシスの薬5', 'function_string' => 'heal+5', 'price' => '10' ),
  array( 'name' => 'イシスの薬20', 'function_string' => 'heal+20', 'price' => '100' ),
  array( 'name' => 'イシスの薬50', 'function_string' => 'heal+50', 'price' => '300' ),
  array( 'name' => 'イシスの薬100', 'function_string' => 'heal+100', 'price' => '500' ),
  array( 'name' => 'イシスの薬200', 'function_string' => 'heal+200', 'price' => '1000' ),
  array( 'name' => 'イシスの薬500', 'function_string' => 'heal+500', 'price' => '3000' ),
  array( 'name' => 'イシスの薬', 'function_string' => 'heal+99999', 'price' => '10000' ),
);

} // end of class
