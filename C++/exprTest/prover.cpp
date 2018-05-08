#include "prover.h"

Prover::Prover()
    : _concl(nullptr)
{}
Prover::~Prover()
{}

bool Prover::MatchAtomic(string input)
{
    bool ret = false;
    for (unsigned int i = 0; i < _premi.size(); i++)
    {
        if (input == _premi[i]->Name()) ret = true;
    }
    return ret;
}

bool Prover::MatchNegation(string input)
{
    bool ret = false;
    string negate = "~"+input;
    for (unsigned int i = 0; i < _premi.size(); i++)
    {
        if (negate == _premi[i]->Name()) ret = true;
    }
    return ret;
}

bool Prover::MatchString(string input)
{
    bool ret = false;
    for (unsigned int i = 0; i < _premi.size(); i++)
    {
        if (input == _premi[i]->Name()) ret = true;
    }
    return ret;
}
//setup functions
void Prover::AddPremise(BoolExp* exp, PropType p)
{
    _premi.push_back(exp);
    _ptypes.push_back(p);
}

void Prover::AddConclusion(BoolExp* exp, PropType p)
{
    _concl = exp;
    _ctype = p;
}

void Prover::AddDerivation(BoolExp* exp, PropType p)
{
    _deriv.push_back(exp);
    _dtypes.push_back(p);
}

//main functions in order to prove
void Prover::Infer(int i)
{
    switch(_ptypes[i])
    {
    case OR_EXP:
    {
        //TODO: Test this
        BoolReturn inf = _premi[i]->Infer();

        if (!MatchNegation(inf.op1->Name()))
        {
            AddPremise(inf.op2,inf.op2->Type());
        }
        if (!MatchNegation(inf.op2->Name()))
        {
            AddPremise(inf.op1,inf.op1->Type());
        }
        break;
    }
    case VAR_EXP:
        break;
    case AND_EXP:
    {
        BoolReturn inf = _premi[i]->Infer();
        /*
        *	bool addpremise = true
        *	for (int i = 0; i < COUNTOFPREMISES)
        *	{
        *		if (inf.op1->Name == _prem[i]->Name)
        *		addpremise = false;
        *	}
        */
        //if (!MatchAtomic(inf.op1->Name()))
        if (!MatchString(inf.op1->Name()))
        {
            AddPremise(inf.op1,inf.op1->Type());
        }
        if (!MatchString(inf.op2->Name()))
        {
            AddPremise(inf.op2,inf.op2->Type());
        }
        //add reasons
        break;
    }
    case NOT_EXP:
    {
        //this needs to be broken into separate cases mainly for ~(A&B), ~(A=>B), ~(AvB)
        //A nested case might suck but it could make sense here too?
        break;
    }
    case COND_EXP:
    {
        //modus-ponens
        BoolReturn inf = _premi[i]->Infer();
        if (MatchString(inf.op1->Name()))
        {
            AddPremise(inf.op2,inf.op2->Type());
        }
        break;
    }
    default:
        abort();
    }
}

void Prover::MakeAssumption()
{}

void Prover::FindContradiction()
{
    //use match negation, check each formula for its own negation
    for (unsigned int i = 0; i < _premi.size(); i++)
    {
    	if (MatchNegation(_premi[i]->Name()))
		{
			cout << "Negation of line " << i << " found!" << endl;
		}
	}
}

//auxiliary functions
void Prover::PrintPremises() const
{
    cout << "PREMISES: " << endl;
    int j = 0;
    for (auto i = _premi.begin(); i != _premi.end(); ++i, ++j)
    {
        cout << j << ") " << _premi[j]->Name() << endl;
    }
}

void Prover::PrintConclusion() const
{}

void Prover::PrintDerivations() const
{}
