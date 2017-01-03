#this script is largely untested
#your password will be stored in clear text as an argument
#use this script at your own risk
#!/bin/bash

while :
do
	IP=$(python ./requestpubip.py)
	echo $IP
	sleep 1h
	IP2=$(python ./requestpubip.py)
	echo $IP2
	if [ $IP != $IP2 ];
		then
			###################################################
			#ENTER YOUR SCRIPT TO EXECUTE HERE				  #
			#THIS SCRIPT WILL EXECUTE WHENEVER YOUR IP CHANGES# 
			#THE INCLUDED PYTHON SCRIPT BELOW WILL EMAIL YOU  #
			#YOUR NEW IP									  #
			# 												  #
			#USAGE: ./ip_watcher [gmail] [pwd] [dest email]	  #
			###################################################
			python emailip.py $1 $2 $3
			echo script complete!
	fi
done
