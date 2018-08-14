# What this directory is for:
This directory contains a gui program for building random arguments as pdf's in either first order or propositional logic.
# Things you will need to run this program:
- xdg-open: opens your pdf viewer, if you do not have xdg-open you can instead use your preferred pdf viewer but you will need to change this by hand.
- a pdf viewer for xdg-open to use
- sbcl: the core of the argument building program is a lisp script I wrote using sbcl.
- sed: filters the argbuilder script output to tex
- pdflatex: converts the tex file to a pdf file
- tcl/tk since the gui is written for the wish shell
# Files this directory contains:
# UnifiedGui.sh:
The actual gui script, you probably want to run this.
# README.md:
The file you are currently reading
# argBuilderFirstOrder:
A trimmed down version of the first order argbuilder program
# argBuilderPropCase:
A trimmed down version of the propositional argbuilder program
# format[1-3] scripts:
The unified gui script runs these scripts to build and display the pdfs
# demo:
![alt text](https://raw.githubusercontent.com/mehstruslehpy/Documents/master/Lisp/argBuilderGuiWrapper/ArgBuilderDemo.gif)
