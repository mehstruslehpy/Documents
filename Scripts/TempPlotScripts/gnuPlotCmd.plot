set terminal png
set output 'temp_plot.png'
plot "acpitz-virtual-0_temp1.log", "acpitz-virtual-0_temp2.log", "k10temp-pci-00c3_temp1.log", "radeon-pci-0008_temp1.log"
