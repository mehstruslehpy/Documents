#!/bin/sh
python requestpubip.py | grep "'*'" > file.txt; echo "YOUR IP IS:"; cat file.txt
