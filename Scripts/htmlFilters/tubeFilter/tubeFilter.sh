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
rm *.html

#create the empty file containing the urls
touch links.html

#some preliminary info
echo "<!DOCTYPE html>" > out.html
echo "<html> " >> out.html
echo "<body> " >> out.html
echo "<head> This is a list of youtube links from the site you chose: </head><br><br>" >> out.html
echo " " >> out.html
echo "The site you chose was: " >> out.html
echo "<a href=\"" >> out.html
echo $1 >> out.html
echo "\">" >> out.html
echo $1 >> out.html
echo "</a><br><br>" >> out.html
echo " " >> out.html

#The first link is a dead link, a reminder of this is placed in the generated html page
#I probably should have thought of a better pattern but this one actually works despite
#this minor problem
lynx -dump $1  | sed 's/^ //' | sed 's/[0-9]*\. //' | sed 's/javascript.*//' |sed 's/  Hidden links://' | sed 's/\ *//' | grep '\S' | grep 'http' | grep youtu | sed 's/^.*http/http/'>> links.html
sed -e 's/^/<a href="/' -i links.html
sed -e 's/$/">CLICKME<\/a><br>/' -i links.html
echo " " >> links.html

python linkPrep.py >> out.html

#after all the links are generated we append this message, that way if this message is
#not in the final page then we know the script did not entirely complete
echo "<p>END OF LIST</p></html>" >> out.html
echo "</body> " >> out.html
echo "</html> " >> out.html

#this can be changed to auto open in whatever browser you want so long as it has cmd line
#support like this... Doing it in a variable makes it user supplied though which is nice.
exec $2 out.html
