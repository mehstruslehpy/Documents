#/bin/sh
#check for commandline arguments

if [ $# -ne 1 ]
	then
    echo "USAGE:"
	echo "    CurrentCountByHost.sh <hostname>"
	exit
fi

if [ $1 == "-h" ]
	then
    echo "USAGE:"
	echo "    CurrentCountByHost.sh <hostname>"
	exit
fi

if [ $1 == "--help" ]
	then
    echo "USAGE:"
	echo "    CurrentCountByHost.sh <hostname>"
	exit
fi

HOSTTOFILTER=$(echo $1)
echo "Output of the ten highest unique counts of packets by timestamp:"
echo "Format: <count-of-packets> <timestamp>"
cat tcpdump_comms_*.log |egrep $1|tee greppedlines.log| sed 's/\.[0-9][0-9][0-9][0-9][0-9][0-9]//' | sed -r 's/(IP6|IP)//' | sed 's/ /_/'|\
cut --characters=1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 | uniq -c
