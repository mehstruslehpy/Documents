#roman numeral thing
#this is probably the worst way to do this
#but it works

#declare and initialize
inputNum = input()
inputNum = int(inputNum)
outputStr = ""

#Only continue on numbers 1-9
if inputNum > 9 or inputNum < 1:
	print("Number outside range")
	exit()

#special case because I prefixes V in 4
if inputNum == 4:
    outputStr = "IV"
    print(outputStr)
    exit()

#special case because I prefixes X in 9
if inputNum == 9:
    outputStr = "IX"
    print(outputStr)
    exit()

#cases less than 4
if inputNum < 4:
        for inputNum in range(0, inputNum):
            outputStr = outputStr + "I"
        print(outputStr)
        exit()

#cases greater than 9
inputNum = inputNum - 5
outputStr = outputStr + "V"
while inputNum > 0:
    outputStr = outputStr + "I"
    inputNum = inputNum - 1

#print what remains in outputStr and exit
print(outputStr)
exit()
