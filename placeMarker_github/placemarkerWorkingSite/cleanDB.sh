#!/bin/bash

#saving this script for later
#set $user variable to the user name from dbconfig.py
user=$(cat dbconfig.py | grep db_user | cut -c 9-100)
temp="${user%\"}"
user="${temp#\"}"
echo "deleting input places html files and database entries"
#delete all places from the database using $user this will prompt for a password

#this line is broke
#echo "use placemap; delete from places" | mysql -u $user -p -h mehstruslehpy2.mysql.pythonanywhere-services.com
#this line is broke

#remove all html files from places directory
#rm -rf static/html/places/*
#cp backups/place_index.html static/html/places/place_index.html
