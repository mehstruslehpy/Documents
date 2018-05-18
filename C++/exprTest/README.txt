WHAT THIS IS:
	-Exprtest is a program based off of a design pattern from a book
	-Currently this program has two modes of operaton:
		-Calculator mode: calculates boolean formulas based on input
		-Proof mode: proves a propositional argument or provides a counter argument
	Input can be done in two ways:
		-via the built in repl
			-Choose between unary or binary operators/variables
				-For unary:
					-it can be a variable or the negation of a formula (negations recurse)
				-For binary:
					-Pick between conditional, and, or formulas
					-arguments get filled in from left to right
		-via automating the repl by using a here document
			-type out the correct sequence of arguments that you would type into the repl
			-I did not invent this method of input but I found it very useful during testing
			-all 60 test arguments use this method see the first example in the valid arguments directory
TODO: 
	-general cleanup
	-refactor into something more elegant
	-write a scripting tool and or parser to make typing out
		proofs easier
	-create doxygen documentation to document everything
	-Write a gui (maybe)
	-figure out the blocking glitch in testproof5
	-add more operators and inference rules
