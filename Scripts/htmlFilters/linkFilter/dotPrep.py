import sys

linkFile = open('links.txt', 'r')

rootString = sys.argv[1]

print("digraph {")
for line in linkFile:
    if len(line) > 2:
        print("\""+rootString+"\""+" -> "+"\""+line.rstrip()+"\";")
print("}")
