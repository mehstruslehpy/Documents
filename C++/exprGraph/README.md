# WHAT THIS IS:
	-ExprGraph is a program based off of a design from the design patterns book (the gang of four one) and my previous ExprTest prover
	-Currently this program has one mode of operaton:
		-Proof mode: proves a propositional argument or provides a counter argument
	-This program was written and tested on linux I cannot vouch for whether or not it will run on 
		windows
	-Input can be done in the same way as ExprTest except this program does not have the user friendly translator tools and output is to 
		OUTPUT_DOTFILE_PROOF.gv in the dot graph descriptor language, this way you can run dot -T<format> OUTPUT_DOTFILE_PROOF.gv to build
		a visual of the generated tableau proof.
# Well Formed Formulas:
	-The notion of a wff is the same as exprtest
	-The prover will ignore p for prover mode and c for calculator mode lines in exprTest heredocs

# The Inference Rules:
	-The inference rules in this program are based on Graham Priests An Introduction To Nonclassical Logic, though my prover only does classical logic.
	-Conjunctions copy both operands to each leaf.
	-Disjunctions split the leaves with one branch for the left operand and one for the right operand.
	-Double negations copy the un-double negated formula to each leaf.
	-Nor and nand follow by demorgans law.
	-Conditionals follow from the definition of the material conditional (A->B) is (~AvB).
	-Negated conditionals follow by demorgans law.

# Inference Rules and Proofs:
	-To prove Gamma |- Delta the tree fills in the root node with Gamma and not Delta, a valid proof of Gamma |- Delta will contain a contradiction on 
		every branch an invalid proof will have at least one branch with no contradictions.
	-The tree is built until no further inferences can be made.
	-The tree checks itself for any contradictions on a branch and blocks off branches containing contradictions with "XXXXX"
	-Counter arguments can be read from branches containing no "XXXXX" if the argument is invalid.
# MISC:
	-proofs are built and run in the same style as the exprtest program
# DEMO:
![alt text](https://raw.githubusercontent.com/mehstruslehpy/Documents/master/C%2B%2B/exprGraph/exprGraphDemo.gif)
