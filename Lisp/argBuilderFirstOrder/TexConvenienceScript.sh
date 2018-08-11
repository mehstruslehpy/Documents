#!/bin/bash
./prettyPrintToTex.sh > texput.tex
pdflatex texput.tex
rm texput.log
rm texput.aux
evince texput.pdf
