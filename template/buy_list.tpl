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
<h1 style="font-size: 1.1em;">Democratic Dungeon Light</h1>
<big>現在手持ち <big>%%%gold%%%</big> gold</big><br>
現在武器：%%%weapon_name%%%(%%%weapon_damage%%%)<br>
現在防具：%%%armor_name%%%(%%%armor_defense%%%)<br>
<hr>
<a href="?c=buy_list&type=weapon">武器</a> |
<a href="?c=buy_list&type=armor">よろい</a> |
盾 |
アイテム |
<a href="?c=buy_list&type=item_consumable">消耗アイテム</a>


<hr>
<table border="1">
<!--
<tr>
  <th>アイテム名
  <th>攻撃力
  <th>防御力
  <th>お値段
  <th>
-->
$$$item_loop$$$
<tr>
  <td>%%%name%%%<br>
  %%%damage%%% / 
  %%%defense%%% / 
  %%%price%%%gold
  <td valign="middle" ><a href="./?c=buy_fin&type=%%%type%%%&no=%%%no%%%">購入する</a>
$$$/item_loop$$$
</table>


<hr>
・<a href="./">topに戻る</a><br>
</body>
</html>

