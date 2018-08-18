# What is this: 
This is a set of programs for building practice arguments to work on in first order logic.
# Files:
# common.lisp: 
Lisp functions and variables common to all scripts
# prettyPrint.lisp: 
A script that calls the functions from common.lisp, running this script will print an argument in a command line friendly format
# prettyPrintToTex.sh: 
A bash/sed script to generate a tex file from the prettyprint.lisp script
# TexConvenienceScript.sh: 
Uses the prettyPrintToTex.sh script to make and open a pdf of the created argument in the pdf viewer evince.
# prettyPrintToTexAltFormat.sh: 
An alternate quantifier format which reduces parentheses
# AltTexConvenienceScript.sh: 
Does the same thing as TexConvenienceScript.sh but with the alternate quantifier format
# README.md: 
the file you are currently viewing

# Things that are sort of bugs but it's debatable:

Currently the program does not care if it is printing a quantified proposition, meaning a statement that is NOT a predicate but is still quantified. 
For example: <img src="https://latex.codecogs.com/gif.latex?\exists%20x%20D" alt="(Some x)D"/> is a possible formula.

Currently the program does not care if it quantifies an expression and then never places the quantified variable in that expression. 
For example: <img src="https://latex.codecogs.com/gif.latex?\exists%20x%20Pab" alt="(Some x)Pab"/> is a possible formula.

See the links for why this behavior is left in

https://www.logicmatters.net/2011/12/10/and-who-is-for-nullary-functions/

https://math.stackexchange.com/questions/873237/relations-and-functions-with-valence-0/873385#873385
   
