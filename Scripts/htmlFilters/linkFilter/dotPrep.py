import sys

linkFile = open('links.txt', 'r')

rootString = sys.argv[1]

print("graph {")

for line in linkFile:
    if len(line) > 2:
        print("\""+rootString+"\""+" -> "+"\""+line.rstrip()+"\";")
print("}")
