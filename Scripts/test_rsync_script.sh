#!/bin/bash

#########################################
#								        #
#Not sure if I should add more to this..#
#		 						        #
#########################################
echo this should probably be run as root..
echo DO NOT MAKE CHANGES WITHOUT TESTING SAFELY!

set -e

$DATE
$BACKUPSDIR

BACKUPSDIR=/backups
DATE=$(date -I) 
echo Backup date is $DATE

echo Backup starting
rsync -aAXv --exclude={"/dev/*","/proc/*","/sys/*","/tmp/*","/run/*","/mnt/*","/media/*","/lost+found","/backups","/home/sleepy/Downloads"} / $BACKUPSDIR/$DATE
echo Backup done!

echo Tarring backed up files
tar -cvf /backups/$DATE.tar /backups/$DATE

echo Tar complete compressing archive
gzip -9 /backups/$DATE.tar

rm -rf /backups/$DATE
