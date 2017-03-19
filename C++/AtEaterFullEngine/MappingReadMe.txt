###ELEMENTS OF A MAP###
M is for monsters 
# is for walls
@ is for @'s 
l designates the end of a line 
on new line at the end of the file use e to specify the end of the map

###BUILDING YOUR MAPS###
run the finished text map file
through the mapbuilding program like this:

MapBuilder myMap.txt > outputMap.src

###NOTES###
if you want to view the output map source in the
stdout of your terminal omit > outputMap.src
from the map command

The M tiles on the map need room to move around
or the game engine will infinitely loop trying to 
reposition the monsters
You need to leave coordinate (0,0) free for the player character to be drawn