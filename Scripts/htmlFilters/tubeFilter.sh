#!/bin/bash

##########################################################
#    INFO:                                               #
#        This script generates an html page of youtube   #
#        links then opens that page  in your browser     #
#                                                        #
##########################################################

##########################################################
#    USAGE:                                              #
#        urlFilter.sh [link-url] [browser]               #
#                                                        #
##########################################################

#check for commandline arguments
if [ $# -ne 2 ]
  then
      echo "USAGE:"
	  echo "    urlFilter.sh [website] [browser]"
	  exit
fi

#if the user wants help
if [ $1 == "-h" ]
  then
      echo "USAGE:"
	  echo "    urlFilter.sh [website] [browser]"
	  exit
fi

#same as the last one
if [ $1 == "--help" ]
  then
      echo "USAGE:"
	  echo "    urlFilter.sh [website] [browser]"
	  exit
fi


#create the empty file containing the urls
touch vids.html

#some preliminary info
echo "<html> <head> This is a list of youtube links from the site you chose: </head> 
	  <p>The requested site was filtered for youtube.com and youtu.be urls</p>
	  <p>Note: The first link is invalid.</p>" > vids.html
echo " " >> vids.html

#The first link is a dead link, a reminder of this is placed in the generated html page
#I probably should have thought of a better pattern but this one actually works despite
#this minor problem
echo "<a href=\"" >> vids.html
lynx -dump $1 | grep youtu | sed -e 's/\s/">click me<\/a><br> <a href="/' >> vids.html
echo "\">click me</a><br>" >> vids.html
echo " " >> vids.html

#after all the links are generated we append this message, that way if this message is 
#not in the final page then we know the script did not entirely complete
echo "<p>END OF LIST</p></html>" >> vids.html

#this can be changed to auto open in whatever browser you want so long as it has cmd line
#support like this... Doing it in a variable makes it user supplied though which is nice.
exec $2 vids.html

#clean up after the page has loaded
rm vids.html
