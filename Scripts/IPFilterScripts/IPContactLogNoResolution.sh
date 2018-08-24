#/bin/sh
echo "Output will be in the following format"
echo "<date>.<time> <protocol> <ip-info>"
sudo tcpdump -n -tttt -i any -q | egrep -o '.*(IP6|IP|ARP).*:' | tee tcpdump_comms_no_resolution_$(date '+%Yyr%mmnth%dday%Hhr%Mmin%Ssec').log
