#!/bin/sh
#The next line executes wish - wherever it is \
exec wish "$0" "$@"
#Make a label "Hello World"
label .hello -text "Hello World"
pack .hello
