#this program will output your public ip
#to stdout as well as email your public ip
#to an email address

import smtplib
import subprocess
import sys

#help commands
opt = sys.argv[1]
if opt == '-h':
    print("This program will send your public IP address to a destination specified")
    print("usage: python emailip.py [gmail] [password] [destination]")
    exit()
if opt == '--help':
    print("This program will send your public IP address to a destination specified")
    print("usage: python emailip.py [gmail] [password] [destination]")
    exit()

#commandline argumentss
gmail = sys.argv[1]
password = sys.argv[2]
destination = sys.argv[3]

#we need wget because I suck at url handling
#in python
#this wget outputs to stdout
#which we store into our output variable
bashcmd1 = 'wget -O - ip.42.pl/raw'
process = subprocess.Popen(bashcmd1.split(), stdout=subprocess.PIPE)
output = process.communicate()[0]

#convert our output to a string for later
output = str(output)

#clean up the output string
output = output.replace("'", "")
output = output.replace("b", "")
print(output)


#the server and port to connect to
smtpObj = smtplib.SMTP_SSL('smtp.gmail.com', 465)

#establish first contact with server
smtpObj.ehlo()

#login, probably not the most secure way
#but this is a dummy acct
#I had to enable access
#for less secure apps
#under gmail acct settings
smtpObj.login( gmail, password)

#creating the string to send (I will clean this later)
fulloutput = 'subject: Your ip: ' + str(output)

print("Sending email...")
#sending the message
smtpObj.sendmail(gmail, destination, fulloutput)

#quit the smtp server
smtpObj.quit
