#!/bin/bash
#this script removes the parens around each quantifier which removes some of the unneeded parens
#print the preamble to the tex document
echo '\documentclass{article}'
echo '\usepackage{graphics}'
echo '\begin{document}'
echo ''
echo 'Can you prove or disprove the following argument? \newline \newline'

#use sed to filter the output into something that tex chan chomp up
./prettyPrint.lisp \
| egrep -v "Can you prove or disprove the following argument?" \
| sed 's/|-/\\vdash /g' \
| sed -r 's/\(All\ ([a-z]+)\)/\\forall\ \1 /g' \
| sed -r 's/\(Some\ ([a-z]+)\)/\\exists\ \1 /g' \
| sed 's/\ ->\ /\ \\Rightarrow\ /g' \
| sed 's/\ &\ /\ \\land\ /g' \
| sed 's/\ v\ /\ \\lor\ /g' \
| sed 's/~/\ \\lnot /g' \
| sed -r 's/(\\vdash|[0-9]+\))/\ \$ \1 ~~~ /g' \
| sed 's/$/\$ \\newline\\newline/g'

#print the ending to the tex document
echo ''
echo '\end{document}'
