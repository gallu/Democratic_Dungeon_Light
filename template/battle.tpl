<!DOCTYPE HTML>

<html lang="ja">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width,initial-scale=1.0, user-scalable=no" />
<meta name="format-detection" content="telephone=no"/>
<link rel="stylesheet" href="./css/base.css" type="text/css">
<title>Dungeons and Towers</title>
</head>

<body>
<div>
あなた(%%%pc_hp%%%/%%%pc_con%%%) vs %%%monster_name%%%(%%%mons_hp%%%/%%%mons_mr%%%)
</div>
$$$if_win$$$
勝利しました！！<br>
%%%add_exp%%%点の経験値を取得<br>
%%%add_gold%%%goldを取得<br>
$$$/if_win$$$

$$$if_lose$$$
敗北しました…<br>
「をを まけてしまうとは なさけない」<br>
$$$/if_lose$$$

$$$if_draw$$$
引き分けです。ドローです。<br>
%%%add_exp%%%点の経験値を取得<br>
%%%add_gold%%%goldを取得<br>
$$$/if_draw$$$

<hr>
<div>
%%%pc_dice_list%%%<br>
%%%mons_dice_list%%%
<div>
<hr>
$$$no_items$$$使おうとしてるアイテム、ないよ？<br>$$$/no_items$$$
$$$effect_attack$$$魔力が武器に力を与える!!<br>$$$/effect_attack$$$
$$$effect_damage$$$禍々しい毒が滴り落ちる…<br>$$$/effect_damage$$$
$$$effect_heal$$$傷が見る間に癒えていく!!<br>$$$/effect_heal$$$
%%%monster_name%%%に%%%mons_damage%%%点のダメージ！！(貫通%%%mons_malice_damage%%%点)<br>
あなたに%%%pc_damage%%%点のダメージ！！(貫通%%%pc_malice_damage%%%点)<br>
<hr>
$$$if_no_fin$$$
<a href="./">殴る！！</a><br>
魔法を使う<br>
$$$item_consumable_loop$$$
<a href="./?item_consumable=%%%no%%%">%%%name%%%を使う</a><br>
$$$/item_consumable_loop$$$
<br>
戦闘をリタイアする orz<br>
$$$/if_no_fin$$$
$$$if_fin$$$
<a href="./">topに戻る</a><br>
$$$/if_fin$$$


</body>
</html>

