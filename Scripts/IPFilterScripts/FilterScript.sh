#/bin/sh
cat tcpdump_comms_*.log | sed 's/\.[0-9][0-9][0-9][0-9][0-9][0-9]//' | sed -r 's/(IP6|IP)//' | sed 's/ /_/'
