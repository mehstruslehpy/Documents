#include "prover.h"

Prover::Prover()
    :_premcount(0), _highestasm(0)
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
    _blocked.push_back(0);
    _assum.push_back(_highestasm);
    BoolReturn inf = exp->Infer();
    if (p == VAR_EXP|| (p == NOT_EXP&& inf.op1->Type() == VAR_EXP))
    {
        _starred.push_back(1);
    }
    else
    {
        _starred.push_back(0);
    }
    ++_premcount;
    _premi.push_back(exp);
    _reasons.push_back(reason);
    _ptypes.push_back(p);
}

//main functions in order to prove
//TODO:
//	-need to add more rules
//	-split up / refactor
//	-work out the asm/contradict mechanism
void Prover::Infer(int i)
{
    if (_blocked[i]) return;

    switch(_ptypes[i])
    {
    case OR_EXP:
    {
        // (AvB), ~A |- B
        BoolReturn inf = _premi[i]->Infer();

        if (!MatchNegation(inf.op1->Name()))
        {
            if (!MatchString(inf.op2->Name()))
            {
                _starred[i] = 1;
                AddPremise(inf.op2,inf.op2->Type(), "(AvB), ~A |- B");
            }
        }
        if (!MatchNegation(inf.op2->Name()))
        {
            if (!MatchString(inf.op2->Name()))
            {
                _starred[i] = 1;
                AddPremise(inf.op1,inf.op1->Type(), "(AvB), ~A |- B");
            }
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
            _starred[i] = 1;
            AddPremise(inf.op1,inf.op1->Type(), "(A&B) |- A, B");
        }
        if (!MatchString(inf.op2->Name()))
        {
            _starred[i] = 1;
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
        case NOT_EXP:
        {
            // ~~A |- A
            inf = inf.op1->Infer();
            if (!MatchString(inf.op1->Name()))
            {
                _starred[i] = 1;
                AddPremise(inf.op1,inf.op1->Type(), "~~A |- A");
            }
            break;
        }
        case COND_EXP:
        {
            //~(A->B) |- A, ~B
            inf = inf.op1->Infer();
            BoolExp* tmp = new NotExp(inf.op2);
            if (!MatchString(inf.op1->Name()))
            {
                _starred[i] = 1;
                AddPremise(inf.op1,inf.op1->Type(), "~(A->B) |- A, ~B");
                AddPremise(tmp,tmp->Type(), "~(A->B) |- A, ~B");
            }
            break;
        }
        case OR_EXP:
        {
            //~(AvB) |- ~A, ~B
            inf = inf.op1->Infer();
            BoolExp* tmp = new NotExp(inf.op2);
            if (!MatchString(inf.op1->Name()))
            {
                _starred[i] = 1;
                AddPremise(tmp,tmp->Type(), "~(AvB) |- ~A, ~B");
                tmp = new NotExp(inf.op1);
                AddPremise(tmp,tmp->Type(), "~(AvB) |- ~A, ~B");
            }
            break;
        }
        case AND_EXP:
        {
            //~(A&B), A |- ~B
            inf = inf.op1->Infer();
            if (MatchString(inf.op1->Name()))
            {
                BoolExp* tmp = new NotExp(inf.op2);

                if (!MatchString(tmp->Name()))
                {
                    _starred[i] = 1;
                    AddPremise(tmp,tmp->Type(), "~(A&B), A |- ~B");
                }
            }
            if (MatchString(inf.op2->Name()))
            {
                BoolExp* tmp = new NotExp(inf.op1);
                if (!MatchString(tmp->Name()))
                {
                    _starred[i] = 1;
                    AddPremise(tmp,tmp->Type(), "~(A&B), A |- ~B");
                }
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
        //(A->B), A |- B
        BoolReturn inf = _premi[i]->Infer();
        if (MatchString(inf.op1->Name()))
        {
            if (!MatchString(inf.op2->Name()))
            {
                _starred[i] = 1;
                AddPremise(inf.op2,inf.op2->Type(), "(A->B), A |- B");
            }
        }
        break;
    }
    default:
        abort();
    }
}

//need to think this out more
void Prover::MakeAssumption()
{
    BoolReturn inf = _premi[0]->Infer();
    _highestasm++;

    //check for a usable formula, I need three cases one for each binary formula
    for (int i = 0; i < _premcount; i++)
    {
        inf = _premi[i]->Infer();
        if(_premi[i]->Type() == AND_EXP &&
                (!MatchNegation(inf.op1->Name())||!MatchNegation(inf.op2->Name())))
        {
            //cout << "DEBUG: AND ASSUMPTION" << endl;
        }
        if(_premi[i]->Type() == NOT_EXP && _premi[i]->Infer().op1->Type() == OR_EXP &&
                (!MatchString(inf.op1->Name())||!MatchString(inf.op2->Name())))
        {
            //make assumption
            //cout << "DEBUG: OR ASSUMPTION" << endl;
        }
    }
}

bool Prover::FindContradiction()
{
    //use match negation, check each formula for its own negation
    bool ret = false;
    for (unsigned int i = 0; i < _premi.size(); i++)
    {
        if (MatchNegation(_premi[i]->Name()))
        {
            cout << "Negation of line " << i << " found!" << endl;
            ret = true;
        }
    }
    if (ret == true)
    {
        //block off all lines at highest assumption level
    }
    return ret;
}

void Prover::PrintPremises() const
{
    cout << "PREMISES: " << endl;
    int j = 0;
    for (auto i = _premi.begin(); i != _premi.end(); ++i, ++j)
    {
        if (_starred[j])
        {
            cout << "* ";
        }
        else
        {
            cout << "  ";
        }
        cout << j << ") " << _premi[j]->Name();
        cout << "\t{ " + _reasons[j] + " }" << endl;
    }
}

int Prover::PremiseCount() const
{
    return _premcount;
}
int Prover::HighestAssumption() const
{
    return _highestasm;
}
