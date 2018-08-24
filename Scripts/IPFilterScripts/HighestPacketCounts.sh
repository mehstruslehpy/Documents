#/bin/sh
echo "Output of the ten highest unique counts of packets by timestamp:"
echo "Format: <count-of-packets> <timestamp>"
./FilterScript.sh | cut --characters=1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 | uniq -c | sort -h | uniq
