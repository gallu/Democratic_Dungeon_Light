#!/bin/bash

# rsync
# --dry-run \

rsync \
 -av \
 --delete \
 --exclude 'deploy.sh' \
 --exclude '.gitignore' \
 --exclude '.git' \
 --exclude 'base.inc' \
   /opt/www/ga/Democratic_Dungeon_Light/ 133.242.143.219:/opt/www/ga/Democratic_Dungeon_Light/
