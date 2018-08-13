#!/bin/bash
./prettyPrintToTex.sh > texput.tex
pdflatex texput.tex
rm texput.log
rm texput.aux
xdg-open texput.pdf
