import sys
import matplotlib.pyplot as plotter
import re

print('File: '+sys.argv[1])
if len(sys.argv) != 2:
    print("USAGE: python Plots.py <filename>")
    exit()

plotFile = open(sys.argv[1], 'r')

strings = []
nums = []

for line in plotFile:
    match1 = re.search('[^0-9]*([0-9]*)\ (.*)', line)
    if match1:
        string1 = match1.group(1)
        # nums.append(int(string1.strip('\'')))
        if string1 == '':
            nums.append(0)
        else:
            nums.append(int(string1))
        string2 = match1.group(2)
        strings.append(string2)
        # print('string1: '+string1+' string2: '+string2)
        # print(string1+' : '+string2)

print("length nums:"+str(len(nums)))
print("length strings:"+str(len(strings)))
# enables dates output on graph
plotter.xticks(rotation=90)
plotter.xticks(range(0, len(strings)), strings, size='small')
plotter.plot(nums)
plotter.show()
