#!/bin/sh

if [ $# -ne 1 ]
	then
	echo ""
    echo "USAGE:"
	echo "    CurrentCountByHost.sh <hostname>"
	echo ""
	echo "ARGUMENT: "
	echo $1
	exit
fi

if [ $1 == "-h" ]
	then
	echo ""
    echo "USAGE:"
	echo "    CurrentCountByHost.sh <hostname>"
	echo ""
	exit
fi

if [ $1 == "--help" ]
	then
	echo ""
    echo "USAGE:"
	echo "    CurrentCountByHost.sh <hostname>"
	echo ""
	exit
fi


./CurrentCountByHost.sh $1 > plottingdata.log
python Plots.py plottingdata.log
