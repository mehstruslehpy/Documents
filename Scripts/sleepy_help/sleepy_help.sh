#!/usr/bin/python

import os                                   #for chdir and getcwd
import glob                                 #for retrieving a list of only txt files
from subprocess import call                 #for calling less on any given file

#move to the info file directory; this will need modified for other machines
os.chdir('/home/sleepy/Info')

print("Help files in: ")
print(os.getcwd())
print("Contents: ")
helpFiles = glob.glob('*.txt')

#priming inputs
userChoice = ""
userNum = 999

#enter the repl loop
while userNum != -1:

    #print the list of options
    for i in range(0, len(helpFiles) - 1, 1):
        print(str(i)+") "+helpFiles[i])

    #prompt user for choice
    print("Choose file (-1 to quit): ")
    userChoice = input()
    userNum = int(userChoice)

    #range check the user input
    if userNum > (len(helpFiles) - 1) or userNum < -1:
        while int(userChoice) > (len(helpFiles) - 1) or int(userChoice) < 0:
            print("Error: input out of range please make another choice")
            userChoice = input()
            userChoice = userChoice.strip()

    #if the user did not choose to quit then run less in a subprocess
    if userNum != -1:
        fileName = helpFiles[int(userChoice)]
        call(["less", fileName])
