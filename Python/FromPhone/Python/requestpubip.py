import subprocess

bashcmd1 = 'wget ip.42.pl/raw'
bashcmd2 = 'cat raw '
bashcmd3 = 'rm raw'

process = subprocess.Popen(bashcmd3.split(), stdout=subprocess.PIPE)
process = subprocess.Popen(bashcmd1.split(), stdout=subprocess.PIPE)
output = process.communicate()[0]
process = subprocess.Popen(bashcmd2.split(), stdout=subprocess.PIPE)
output = process.communicate()[0]
str(output)
print(output)
process = subprocess.Popen(bashcmd3.split(), stdout=subprocess.PIPE)
