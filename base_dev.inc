<?php

// MW��Ȥ���褦�ˤ���
require_once('/opt/www/mw.conf');

// ���ǥ��쥯�ȥ������
$bp = '/home/furu/work/ga/Democratic_Dungeon_Light/';

// config�ե�����̾
$config       = $bp . 'conf/config.conf';
$admin_config = $bp . 'conf/admin_config.conf';

//
require_once('controller.inc');

//
$co = new controller;
$co->set_base_path($bp);
