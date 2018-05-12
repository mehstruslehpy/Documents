This is a propositional logic proving program. This program uses proof by contradiction and a limited set of inference rules to prove
arguments typed in by the user. The arguments can be typed in on the fly or scripted via linux/unix here documents the first test proof
shows a working here document argument.

Currently the prover fails on arguments that require further assumptions in order to resolve certain proof aspects.
TODO: 
	-implement further assumption rules to resolve failing proofs
	-add more test proofs
	-implement even more operators (biconditionals, nands, nors, xors)
	-refactor current inference code into something cleaner
	-Flesh out the inference rules skeleton code in prover.cpp
	-Clean out unused fields in prover.h
	-Write a fun ui in main.cpp
		-Two modes: Calculation for computing binary formulas
					Proof for creating proofs of various formulas
