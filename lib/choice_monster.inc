<?php

/***************************************************
 * モンスターチョイス
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_sample_front_base.inc');
require_once('ddl_monster.inc');

class choice_monster extends base_model_sample_front_base {


//処理
public function execute() {
//print "Trap 1\n";

  //
  $req = $this->get_cgi_request();
  $conv = $this->get_conv();

  // チョイスロジック…外だしする意味あるか？

  // MRの幅を取得
  $i = abs($req->find('mr_base') + 0) % 100; //
  $conv->monoDic('mr_base', $i);
  //
  setcookie('mr_base', $i, time() + 60*60*24*365);

  //
  $mr_min = (($i*20)+10);
  $mr_max = (($i+1)*20+10);
  // MR決定
  $mr = mt_rand($mr_min, $mr_max);
//var_dump($mr);

  // 名前選択
  // XXX (立方根を２でわって整数化) - 1;
  // XXX 0-4
  $name_base = (int)(sqrt($mr) / 2)  - 2;
  if (0 > $name_base) {
    $name_base = 0;
  }
  if (4 < $name_base) {
    $name_base = 4;
  }
//var_dump($name_base);

  // 名前各種：あとで外だしかねぇ？
  $mons_names = array (
    '0' => array(
      'プチコボルト',
      'コボルト',
      'チワワコボルト',
      'コボルトゾンビ',
      'コボルトスケルトン',
      'コボルトダンサー',
      'ミニゴブリン',
      'ゴブリンダンサー',
    ),

    '1' => array(
      'ゴブリン',
      'ゴブリン肉屋',
      'ゴブリン魚屋',
      'ゴブリン裁縫屋',
      'ゴブリン鍛冶屋',
      'ゴブリンゾンビ',
      'ゴブリンスケルトン',
      '柴コボルト',
      'プードルコボルト',
      'パグコボルト',
      'コボルトワイト',
      'レッサーバンパイアコボルト',
      'ヤマタノコボルト',
    ),

    '2' => array(
      'レトリバーコボルト',
      'ハイゴブリン',
      'ゴブリンロード',
      'ゴブリンシャーマン',
      'ゴブリンワイト',
      'レッサーバンパイアゴブリン',
      'バンパイアコボルト',
      'ヤマタノゴブリン',
    ),

    '3' => array(
      'ドーベルマンコボルト',
      'ウルフコボルト',
      'エンシェントゴブリン',
      'ゴブリンハイロード',
      'バンパイアゴブリン',
      'ノーライフキングコボルト',
      'マスターコボルト',
      'ビボルドライドコボルト',
    ),

    '4' => array(
      'レジェンドゴブリン',
      'ドラゴンライダーゴブリン',
      'エレメンタルゴブリン',
      'ノーライフキングゴブリン',
      'ゴブリンギーク',
      'コボルトギーク',
      'マスターゴブリン',
      'ビボルドライドゴブリン',
    ),
  );

  // 名前を選択
  $awk = $mons_names[$name_base];
//var_dump($awk);
  $name_no = array_rand($awk, 1);
  $name = $mons_names[$name_base][$name_no];
//var_dump($name);

  // インスタンス作って
  $mons_obj = new ddl_monster();

  // 設定して
  $mons_obj->set_mr($mr);
  $mons_obj->set_name($name);
  $mons_obj->set_damage(0);

  // 保存して
  $mons_obj->save();

  // 表示
  $mons_obj->set_to_conv($conv);

}

} // end of class

/*
26	75
76	125
126	175
176	225
226	275
276	325
326	375
376	425
426	475
476	525
526	575
576	625
626	675
676	725
726	775
776	825
826	875
876	925
926	975
976	1025
1026	1075

0-20

((n*50)+26) - ((n+1)*50+25)


(立方根を２でわって整数化) - 1;
0-4



*/
