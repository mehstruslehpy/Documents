#run as ./sensorLoop.sh | tee temp.log for convenient logging
#!/bin/bash
	echo "################################################################";
	date;
	sensors;
	echo "################################################################";
	echo ;
	sleep 2; 
