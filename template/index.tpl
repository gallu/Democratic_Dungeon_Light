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
多数決による地下迷宮。闘って育てるだけ、の簡易版です。
<hr>
2011/12/02：消耗アイテムが使えるようになりました!!<br>
2011/12/01：消耗アイテムが買えるようになりました！！。使うのもうちょっとまって orz

$$$is_chara$$$
<hr>
モンスターを選ぶ!!
<form action="./?c=choice_monster" method="post">
  <select name="mr_base">
    <option value="0" ***mr_base:0*** >MR:20くらいの敵</option> 
    <option value="1" ***mr_base:1*** >MR:40くらいの敵</option> 
    <option value="2" ***mr_base:2*** >MR:60くらいの敵</option> 
    <option value="3" ***mr_base:3*** >MR:80くらいの敵</option> 
    <option value="4" ***mr_base:4*** >MR:100くらいの敵</option> 
    <option value="5" ***mr_base:5*** >MR:120くらいの敵</option> 
    <option value="6" ***mr_base:6*** >MR:140くらいの敵</option> 
    <option value="7" ***mr_base:7*** >MR:160くらいの敵</option> 
    <option value="8" ***mr_base:8*** >MR:180くらいの敵</option> 
    <option value="9" ***mr_base:9*** >MR:200くらいの敵</option> 
    <option value="10" ***mr_base:10*** >MR:220くらいの敵</option> 
    <option value="11" ***mr_base:11*** >MR:240くらいの敵</option> 
    <option value="12" ***mr_base:12*** >MR:260くらいの敵</option> 
    <option value="13" ***mr_base:13*** >MR:280くらいの敵</option> 
    <option value="14" ***mr_base:14*** >MR:300くらいの敵</option> 
    <option value="15" ***mr_base:15*** >MR:320くらいの敵</option> 
    <option value="16" ***mr_base:16*** >MR:340くらいの敵</option> 
    <option value="17" ***mr_base:17*** >MR:360くらいの敵</option> 
    <option value="18" ***mr_base:18*** >MR:380くらいの敵</option> 
    <option value="19" ***mr_base:19*** >MR:400くらいの敵</option> 
    <option value="20" ***mr_base:20*** >MR:420くらいの敵</option> 
    <option value="21" ***mr_base:21*** >MR:440くらいの敵</option> 
    <option value="22" ***mr_base:22*** >MR:460くらいの敵</option> 
    <option value="23" ***mr_base:23*** >MR:480くらいの敵</option> 
    <option value="24" ***mr_base:24*** >MR:500くらいの敵</option> 
    <option value="25" ***mr_base:25*** >MR:520くらいの敵</option> 
    <option value="26" ***mr_base:26*** >MR:540くらいの敵</option> 
    <option value="27" ***mr_base:27*** >MR:560くらいの敵</option> 
    <option value="28" ***mr_base:28*** >MR:580くらいの敵</option> 
    <option value="29" ***mr_base:29*** >MR:600くらいの敵</option> 
    <option value="30" ***mr_base:30*** >MR:620くらいの敵</option> 
    <option value="31" ***mr_base:31*** >MR:640くらいの敵</option> 
    <option value="32" ***mr_base:32*** >MR:660くらいの敵</option> 
    <option value="33" ***mr_base:33*** >MR:680くらいの敵</option> 
    <option value="34" ***mr_base:34*** >MR:700くらいの敵</option> 
    <option value="35" ***mr_base:35*** >MR:720くらいの敵</option> 
    <option value="36" ***mr_base:36*** >MR:740くらいの敵</option> 
    <option value="37" ***mr_base:37*** >MR:760くらいの敵</option> 
    <option value="38" ***mr_base:38*** >MR:780くらいの敵</option> 
    <option value="39" ***mr_base:39*** >MR:800くらいの敵</option> 
    <option value="40" ***mr_base:40*** >MR:820くらいの敵</option> 
    <option value="41" ***mr_base:41*** >MR:840くらいの敵</option> 
    <option value="42" ***mr_base:42*** >MR:860くらいの敵</option> 
    <option value="43" ***mr_base:43*** >MR:880くらいの敵</option> 
    <option value="44" ***mr_base:44*** >MR:900くらいの敵</option> 
    <option value="45" ***mr_base:45*** >MR:920くらいの敵</option> 
    <option value="46" ***mr_base:46*** >MR:940くらいの敵</option> 
    <option value="47" ***mr_base:47*** >MR:960くらいの敵</option> 
    <option value="48" ***mr_base:48*** >MR:980くらいの敵</option> 
    <option value="49" ***mr_base:49*** >MR:1000くらいの敵</option> 
  </select>
  <button type="submit">いってみる！！</button>
</form>

<hr>
・<a href="./?c=view_pc">PCを見る</a><br>
・<a href="./?c=growth">成長させる</a><br>
・お買い物<br>
　<a href="?c=buy_list&type=weapon">武器</a>
 <a href="?c=buy_list&type=armor">よろい</a>
 盾
 アイテム
 <a href="?c=buy_list&type=item_consumable">消耗アイテム</a><br>
・魔法を学ぶ<br>
・雇い入れる<br>
・<a href="./?c=remake_pc_conf">PCを作り直す</a><br>
$$$/is_chara$$$

$$$is_nochara$$$
<hr>
・<a href="./?c=create_pc">PCを作成する</a><br>
$$$/is_nochara$$$

<hr>
・<a href="./?c=description">簡単な説明</a><br>
・<a href="./?c=account">細かい説明</a><br>
<hr>
お問い合わせなどありましたら、現状、すみません twitter で <a href="http://twitter.com/gallu/">@gallu</a> 宛にお声がけいただければ、気づき次第返信出来るよう努力いたします。<br>
寂しんぼなので、激励とか要望とか大歓迎です。
</body>
</html>

