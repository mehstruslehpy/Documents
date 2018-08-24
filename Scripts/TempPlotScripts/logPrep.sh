#prep a .log file for plotting temp values
#!/bin/sh
echo "Log file selected:"
echo $1
cat $1 | grep radeon-pci-0008 -A 2|grep temp1 |cut -c 16-19 > radeon-pci-0008_temp1.log
cat $1 | grep acpitz-virtual-0 -A 3|grep temp1 |cut -c 16-19 > acpitz-virtual-0_temp1.log
cat $1 | grep acpitz-virtual-0 -A 3|grep temp2 |cut -c 16-19 > acpitz-virtual-0_temp2.log
cat $1 | grep k10temp-pci-00c3 -A 2 | grep temp1 | cut -c 16-19 > k10temp-pci-00c3_temp1.log
