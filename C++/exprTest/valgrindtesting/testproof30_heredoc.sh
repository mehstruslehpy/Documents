valgrind ../main <<-ENDOFMESSAGE
p
#Proposition 1
u	#this is meant to be a single conclusion proof
v	#the ui won't let you not add premises
A	#so instead I can add one that is unrelated
q #continue

#Conclusion
b
c
u
n
b
a
u
v
P
u
v
Q
b
c
u
v
Q
u
n
u
v
P
c # continue
ENDOFMESSAGE
