#!/usr/bin/python
import os

filePtr = open('.//polymorph.py', 'r')
fileContent = filePtr.readlines()

runFlag = 0

poemB = "I am always changing, a growing tree or a dulled tool, tedious, exhausting, I continue.\nI can become a new job to be rebuilt, a task with no solution. What was old is new and what was new is old,\nWe forget our face while you forget my name."
poemA = "I am never the same at any instance in time, I am different every time I run, no matter how far I run.\nI can be resewn and rewritten while I do my work, I can be rebuilt to become a new job,\nwhose collar was once blue is now white, what skin that was once smooth is now hard.."
print(poemA)

if runFlag == 0:
    fileContent[6] = "runFlag = 1\n"
    fileContent[10] = "print(poemB)\n"
else:
    fileContent[6] = "runFlag = 0\n"
    fileContent[10] = "print(poemA)\n"

filePtr = open('.//polymorph.py', 'w')
filePtr.writelines(fileContent)
filePtr.close()

#This is a program that rewrites itself after each run to display a new poem.
# I got the idea from a book about reverse engineering
