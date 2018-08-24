#run as ./sensorLoop.sh | tee temp.log for convenient logging
#!/bin/bash
while $1;
do 
	echo "################################################################";
	date;
	sensors;
	echo "################################################################";
	echo ;
	sleep 2; 
done
