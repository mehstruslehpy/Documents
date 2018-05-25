WHAT THIS IS:
	-Exprtest is a program based off of a design from the design patterns book (the gang of four one).
	-Currently this program has two modes of operaton:
		-Calculator mode: calculates boolean formulas using the supported operators
		-Proof mode: proves a propositional argument or provides a counter argument
	-This program was written and tested on linux I cannot vouch for whether or not it will run on 
		windows
	-Input can be done in two ways:
		-via the here document generator tool in the proofTranslator directory
			-type out the well formed formulas and specify when you are entering the conlusion
				via the prompts
		-via the built in repl in the "main" binary
			-Start with specifying a unary or binary proposition
				-For unary:
					-it can be a variable or the negation of a formula
				-For binary:
					-Pick between conditional, and, or or formulas
					-arguments get filled in from left to right
		-via automating the repl by hand using a here document
			-type out the correct sequence of arguments that you would type into the repl
			-I did not invent this method of input but I found it very useful during testing
			-all 60 test arguments use this method see the first example in the valid arguments 
				directory

Well Formed formulas:
	-All formulas except negations and single variables are parenthesized
	-If you use the here doc generator you must use single letter upper case variables
		you should do this for the repl or hand written here docs but you don't have to
	-For general propositions @ and # the supported formulas are
		'(#v@)'	for or expressions
		'(#&@)' for and expressions
		'(#->@)' for conditional expressions
		'~@' for not expressions
		'#' for single variables
		# and @ can be any of the expression types above
	For Example ~((AvB)&~~(~C->~D)) is a well formed formula

The Inference Rules:
	-: {(AvB), ~A |- B} for v's
	-: {(A&B) |- A, B} for &'s
	-: {(A->B), A |- B} for ->'s (modus ponens)
	-: {(A->B), ~B |- ~A} for ->'s (modus tollens)
	-: {~~A |- A} double negation
	-: {~(AvB) |- ~A, ~B} negated v's
	-: {~(A&B), A |- ~B} negated &'s
	-: {~(A->B) |- A, ~B} negated ->'s

Inference Rules and Proofs:
	-Inference rules are listed to the right of the line to which they apply in '{}' brackets.
	-Each inference rule used in a proof specifies also the lines used to make the inference.
	-I use the turnstile 'A |- B' to mean from the general formula A the formula B is inferred
	-each inference rule listed uses A,B as general formulas, do not confuse these with the specific
		letters/variables you choose to use in your proof.
	-Every proof is done by contradiction if possible, periodically the prover checks for a 
		counterargument this way so long as a counterargument or proof exists my prover will 
		find it (given enough time and memory)
	-the prover can also make assumptions for proofs that require them, this is done periodically
		similar to the counterargument checks if needed.
	-this proof method is heavily based off the system used in Harry Genslers intro to logic book 
		which I thought was cool (obviously)

MISC:
	-to build the program run the command "make all"
	-after you build the program I have created a set of test proofs under the invalidproofs and validproofs
		directories just do ./prooftxtfile to run them if necessary you may need to give the file execute permissions
	-to use the proof translator after building the program go into the proofTranslator directory run the program 
		translator and follow the prompts after you are done a file will have been created in that directory for you
		to run as explaine above (you may need to give this file execute permissions too)

TODO: 
	-create doxygen documentation to make everything documented
	-Write a gui (maybe)
	-figure out the blocking glitch in testproof5
