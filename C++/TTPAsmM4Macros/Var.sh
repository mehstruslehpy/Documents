#
#create a new m4 file with all CONSTVAR macros to 
#the end of the file
#

#!/bin/bash

#create a new file with all the CONSTVAR macros removed
while IFS='' read -r line || [[ -n "$line" ]]; 
do
	if [[ $(echo $line | grep -o CONSTVAR) == "CONSTVAR" ]]; 
	then 
		echo "APPEND TO END!"
	else
		echo $line >> _TempVarFile.m4	
	fi
done < "$1"

#append all the CONSTVAR occurences to the end of the file
while IFS='' read -r line || [[ -n "$line" ]]; 
do
	if [[ $(echo $line | grep -o CONSTVAR) == "CONSTVAR" ]]; 
	then 
		echo $line >> _TempVarFile.m4	
	fi
done < "$1"
echo changes made to _TempVarFile.m4
