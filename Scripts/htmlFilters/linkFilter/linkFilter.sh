#!/bin/bash

##########################################################
#    INFO:                                               #
#        This script generates an html page of links     #
#        links then opens that page  in your browser     #
#                                                        #
##########################################################

##########################################################
#    USAGE:                                              #
#        linkFilter.sh [link-url] [browser]               #
#                                                        #
##########################################################

#check for commandline arguments
if [ $# -ne 2 ]
  then
      echo "USAGE:"
	  echo "    linkFilter.sh [website] [browser]"
	  exit
fi

#if the user wants help
if [ $1 == "-h" ]
  then
      echo "USAGE:"
	  echo "    linkFilter.sh [website] [browser]"
	  exit
fi

#same as the last one
if [ $1 == "--help" ]
  then
      echo "USAGE:"
	  echo "    linkFilter.sh [website] [browser]"
	  exit
fi

echo "The following removes might fail harmlessly"
rm links.html
rm out.html
rm links.txt

#create the empty file containing the urls
touch links.html

#some preliminary info
echo "<html> <head> This is a list of links from the site you chose: </head><br><br>" > out.html
#echo "<h></h>"
echo " " >> out.html

#The first link is a dead link, a reminder of this is placed in the generated html page
#I probably should have thought of a better pattern but this one actually works despite
#this minor problem
lynx -dump $1  | sed 's/^ //' | sed 's/[0-9]*\. //' | sed 's/javascript.*//' |sed 's/  Hidden links://' | sed 's/\ *//' | grep '\S' | grep 'http' >> links.html
sed -e 's/^/<a href="/' -i links.html
sed -e 's/$/">CLICKME<\/a><br>/' -i links.html
echo " " >> links.html

#prepare link titles with python filter script
python linkPrep.py >> out.html

#after all the links are generated we append this message, that way if this message is
#not in the final page then we know the script did not entirely complete
echo "<p>END OF LIST</p></html>" >> out.html

#create links.txt file and trim to only have links
cat links.html > links.txt
sed -e 's/<a href="//' -i links.txt
sed -e 's/">CLICKME<\/a><br>//' -i links.txt

#create and output a graph file
python dotPrep.py $1 > graph.gv
dot graph.gv -Tjpg > file.jpg

#this can be changed to auto open in whatever browser you want so long as it has cmd line
#support like this... Doing it in a variable makes it user supplied though which is nice.
exec $2 out.html &
exec $2 file.jpg &
