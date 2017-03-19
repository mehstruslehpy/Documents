####WHAT THIS IS####

Eat the Ats is a terminal based game (micro-engine?) similar to pacman. I thought up
the idea while making a version of tic-tac-toe for a class. Some of the
code in this was blatantly stolen from random stack overflow questions. In
instances where I have done this I had already written my own hackish solutions 
first and then later found better solutions. If you see your code and would like 
it removed please contact me and I will do so.

(for a good example see the screen refreshing code)

####GETTING THE THING TO COMPILE####
I originally made this in codeblocks during lab time for the aforementioned class.
you will need to compile with c11 support due to the nested vectors. 

(before c11 c++ had issues with >> << in nested vectorsa looking like stream operators)

####STARTING A GAME####
To run the game either do:

AtEater.exe yourMap.src

or just type:

ArEater.exe

and the game will prompt you for a map to load..

####HOW TO MAKE MAPS####

this is a basic explanation of the mapping system I created
you can find a couple of example maps in the local directory too.
The *.txt files should be made in a text editor like notepad, and 
the *.src files are the output from the map building program.

###ELEMENTS OF A MAP###
M is for monsters 
# is for walls
@ is for @'s 
l designates the end of a line 
on new line at the end of the file use e to specify the end of the map

###BUILDING YOUR MAPS###
run the finished text map file
through the mapbuilding program like this:

MapBuilder inputMap.txt > outputMap.src

###NOTES###
if you want to view the output map source in the
stdout of your terminal omit > outputMap.src
from the map command

The M tiles on the map need room to move around
or the game engine will infinitely loop trying to 
reposition the monsters.
You also need to leave coordinate (0,0) free for the player character to be drawn
