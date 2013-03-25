<?php

//
ini_set('display_errors', 'on');
error_reporting(E_ALL);

//
//ini_set('display_errors', 'off');

// MWを使えるようにする
require_once('/opt/www/mw.conf');

// 基準ディレクトリの設定
$bp = '/home/furu/work/ga/Democratic_Dungeon_Light/';

// configファイル名
$config       = $bp . 'conf/config.conf';
$admin_config = $bp . 'conf/admin_config.conf';

//
require_once('controller.inc');

//
$co = new controller;
$co->set_base_path($bp);

