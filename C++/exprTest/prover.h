#ifndef _PROVER_H
#define _PROVER_H
#include "defs.h"
#include <vector>

//I might possible consider only using the _premi vector since a proof is really just a list
//of wff's in genslers system, the final one being the negation of the conclusion right before
//the actual derivation steps

//I will use a prover structure for implementing genslers sytem for propositional proof
class Prover
{
    int _premcount;				//the count of premises
    int _highestasm;			//the highest level of assumption
    vector<BoolExp*> _premi;	//the premises
    vector<string> 	_reasons;	//the inference rule used for each derivation

    vector<PropType> _ptypes;	//parallel array for type info premises

    vector<int> _assum; 		//the line number and level of nesting for each assumption
    vector<int> _blocked; 		//the line number and amount of blocks
    vector<int> _starred;		//starred derivations have no further inferences
    vector<bool> _contradicted; //a contradicted derivation cannot be used in further proof

    bool MatchAtomic(string);	//returns true if the atomic proposition input is present in the proof
    bool MatchString(string);	//returns true if the string input is present in the proof
    bool MatchNegation(string);	//returns true if the negation of the input string is present in the proof
public:
    Prover();
    ~Prover();

    //setup functions
    void AddPremise(BoolExp*, PropType, string);

    //main functions in order to prove
    void Infer(const int);
    void MakeAssumption();
    bool FindContradiction();

    //auxiliary functions
    void PrintPremises() const;
    int PremiseCount() const;
    int starredCount() const;
    int HighestAssumption() const;
};
#endif
