#include "prover.h"

Prover::Prover()
    :_premcount(0)
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
void Prover::AddPremise(BoolExp* exp, PropType p, string reason)
{
    ++_premcount;
    _premi.push_back(exp);
    _reasons.push_back(reason);
    _ptypes.push_back(p);
}

//main functions in order to prove
void Prover::Infer(int i)
{
    switch(_ptypes[i])
    {
    case OR_EXP:
    {	
		// (AvB), ~A |- B
        BoolReturn inf = _premi[i]->Infer();

        if (!MatchNegation(inf.op1->Name()))
        {
            AddPremise(inf.op2,inf.op2->Type(), "(AvB), ~A |- B");
        }
        if (!MatchNegation(inf.op2->Name()))
        {
            AddPremise(inf.op1,inf.op1->Type(), "(AvB), ~A |- B");
        }
        break;
    }
    case VAR_EXP:
        break;
    case AND_EXP:
    {	
		//(A&B) |- A, B
        BoolReturn inf = _premi[i]->Infer();
        if (!MatchString(inf.op1->Name()))
        {
            AddPremise(inf.op1,inf.op1->Type(), "(A&B) |- A, B");
        }
        if (!MatchString(inf.op2->Name()))
        {
            AddPremise(inf.op2,inf.op2->Type(), "(A&B) |- A, B");
        }
        break;
    }
    case NOT_EXP:
    {
        //add double negation rule
        BoolReturn inf = _premi[i]->Infer();
        switch(inf.op1->Type())
        {
        case COND_EXP:
        {
            //~(A=>B) |- A, ~B
            inf = inf.op1->Infer();
            BoolExp* tmp = new NotExp(inf.op2);
            AddPremise(inf.op1,inf.op1->Type(), "~(A=>B) |- A, ~B");
            AddPremise(tmp,tmp->Type(), "~(A=>B) |- A, ~B");
            break;
        }
        case OR_EXP:
        {
            //~(AvB) |- ~A, ~B
            inf = inf.op1->Infer();
            BoolExp* tmp = new NotExp(inf.op2);
            AddPremise(tmp,tmp->Type(), "~(AvB) |- ~A, ~B");
            tmp = new NotExp(inf.op1);
            AddPremise(tmp,tmp->Type(), "~(AvB) |- ~A, ~B");
            break;
        }
        case AND_EXP:
        {
            //~(A&B), A |- ~B
            inf = inf.op1->Infer();
            if (MatchString(inf.op1->Name()))
            {
                BoolExp* tmp = new NotExp(inf.op2);
                AddPremise(tmp,tmp->Type(), "~(A&B), A |- ~B");
            }
            if (MatchString(inf.op2->Name()))
            {
                BoolExp* tmp = new NotExp(inf.op1);
                AddPremise(tmp,tmp->Type(), "~(A&B), A |- ~B");
            }
            break;
        }
        default:
        {
            break;
        }
        }
        break;
    }
    case COND_EXP:
    {
        //(A=>B), A |- B
        BoolReturn inf = _premi[i]->Infer();
        if (MatchString(inf.op1->Name()))
        {
            AddPremise(inf.op2,inf.op2->Type(), "(A=>B), A |- B");
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
        cout << j << ") " << _premi[j]->Name();
		cout << "\t{ " + _reasons[j] + " }" << endl; 
    }
}

int Prover::PremiseCount() const
{
    return _premcount;
}
