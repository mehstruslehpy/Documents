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
    vector<BoolExp*> _premi;	//the premises
    vector<string> 	_reasons;	//the inference rule used for each derivation
    vector<BoolExp*> _deriv; 	//the derivations
    BoolExp* _concl;			//the conclusion

    vector<PropType> _ptypes;	//parallel array for type info premises
    vector<PropType> _dtypes;	//parallel array for type info derivations
    PropType _ctype;			//the type of the conclusion

    vector<int> _assum; 		//the line number of each assumption
    vector<bool> _starred;		//starred derivations have no further inferences
    vector<bool> _contradicted; //a contradicted derivation cannot be used in further proof

    bool MatchAtomic(string);	//returns true if the atomic proposition input is present in the proof
    bool MatchString(string);	//returns true if the string input is present in the proof
    bool MatchNegation(string);	//returns true if the negation of the input string is present in the proof
public:
    Prover();
    ~Prover();

    //setup functions
    void AddPremise(BoolExp*, PropType);
    void AddConclusion(BoolExp*,PropType);
    void AddDerivation(BoolExp*,PropType);

    //main functions in order to prove
    void Infer(const int);
    void MakeAssumption();
    void FindContradiction();

    //auxiliary functions
    void PrintPremises() const;
    void PrintConclusion() const;
    void PrintDerivations() const;
};
#endif
