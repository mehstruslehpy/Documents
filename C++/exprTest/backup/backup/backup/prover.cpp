#include "prover.h"

Prover::Prover()
    :_premcount(0), _highestasm(1)
{}
Prover::~Prover()
{}

int Prover::MatchAtomic(string input)
{
    int ret = 0;
    for (unsigned int i = 0; i < _premi.size(); i++)
    {
        if (input == _premi[i]->Name()) ret = i;
    }
    return ret;
}

int Prover::MatchAtomicUB(string input)
{
    int ret = 0;
    for (unsigned int i = 0; i < _premi.size(); i++)
    {
        if (input == _premi[i]->Name() && _assum[i] != -1) ret = i;
    }
    return ret;
}

int Prover::MatchNegation(string input)
{
    int ret = 0;
    string negate = "~"+input;
    for (unsigned int i = 0; i < _premi.size(); i++)
    {
        if (negate == _premi[i]->Name()) ret = i;
    }
    return ret;
}
int Prover::MatchNegationUB(string input)
{
    int ret = 0;
    string negate = "~"+input;
    for (unsigned int i = 0; i < _premi.size(); i++)
    {
        if (negate == _premi[i]->Name() && _assum[i] != -1) ret = i;
    }
    return ret;
}

int Prover::MatchString(string input)
{
    int ret = 0;
    for (unsigned int i = 0; i < _premi.size(); i++)
    {
        if (input == _premi[i]->Name()) ret = i;
    }
    return ret;
}
int Prover::MatchStringUB(string input)
{
    int ret = 0;
    for (unsigned int i = 0; i < _premi.size(); i++)
    {
        if (input == _premi[i]->Name() && _assum[i] != -1) ret = i;
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
        if (MatchNegationUB(inf.op1->Name()))
        {
            if (!MatchStringUB(inf.op2->Name()))
            {
                _starred[i] = 1;
                AddPremise(inf.op2,inf.op2->Type(),
                           "(AvB), ~A |- B on "+to_string(i)+", "+to_string(MatchNegationUB(inf.op2->Name())));
            }
        }
        if (MatchNegationUB(inf.op2->Name()))
        {
            if (!MatchStringUB(inf.op1->Name()))
            {
                _starred[i] = 1;
                AddPremise(inf.op1,inf.op1->Type(),
                           "(AvB), ~A |- B on " + to_string(i) + ", "+to_string(MatchNegationUB(inf.op2->Name())));
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
        if (!MatchStringUB(inf.op1->Name()))
        {
            _starred[i] = 1;
            AddPremise(inf.op1,inf.op1->Type(),
                       "(A&B) |- A, B on "+to_string(i));
        }
        if (!MatchStringUB(inf.op2->Name()))
        {
            _starred[i] = 1;
            AddPremise(inf.op2,inf.op2->Type(),
                       "(A&B) |- A, B on "+to_string(i));
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
            if (!MatchStringUB(inf.op1->Name()))
            {
                _starred[i] = 1;
                AddPremise(inf.op1,inf.op1->Type(),
                           "~~A |- A on " + to_string(i));
            }
            break;
        }
        case COND_EXP:
        {
            //TODO: Add code here to avoid repetition?
            //~(A->B) |- A, ~B
            inf = inf.op1->Infer();
            BoolExp* tmp = new NotExp(inf.op2);
            if (!MatchStringUB(inf.op1->Name()))
            {
                _starred[i] = 1;
                AddPremise(inf.op1,inf.op1->Type(),
                           "~(A->B) |- A, ~B on "+to_string(i));
                AddPremise(tmp,tmp->Type(),
                           "~(A->B) |- A, ~B on "+to_string(i));
            }
            break;
        }
        case OR_EXP:
        {
            //~(AvB) |- ~A, ~B
            inf = inf.op1->Infer();
            BoolExp* tmp;
            if (!MatchNegationUB(inf.op1->Name()))
            {
                _starred[i] = 1;
                tmp = new NotExp(inf.op1);
                AddPremise(tmp,tmp->Type(),
                           "~(AvB) |- ~A, ~B on " +to_string(i));
            }
            if (!MatchNegationUB(inf.op2->Name()))
            {
                _starred[i] = 1;
                tmp = new NotExp(inf.op2);
                AddPremise(tmp,tmp->Type(),
                           "~(AvB) |- ~A, ~B on " +to_string(i));
            }
            break;
        }
        case AND_EXP:
        {
            //~(A&B), A |- ~B
            inf = inf.op1->Infer();
            if (MatchStringUB(inf.op1->Name()))
            {
                BoolExp* tmp = new NotExp(inf.op2);

                if (!MatchStringUB(tmp->Name()))
                {
                    _starred[i] = 1;
                    AddPremise(tmp,tmp->Type(),
                               "~(A&B), A |- ~B on "+to_string(i)+", "+to_string(MatchStringUB(inf.op1->Name())));
                }
            }
            if (MatchStringUB(inf.op2->Name()))
            {
                BoolExp* tmp = new NotExp(inf.op1);
                if (!MatchStringUB(tmp->Name()))
                {
                    _starred[i] = 1;
                    AddPremise(tmp,tmp->Type(),
                               "~(A&B), A |- ~B on " + to_string(i) +", "+to_string(MatchStringUB(inf.op2->Name())));
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
        if (MatchStringUB(inf.op1->Name()))
        {
            if (!MatchStringUB(inf.op2->Name()))
            {
                _starred[i] = 1;
                AddPremise(inf.op2,inf.op2->Type(),
                           "(A->B), A |- B on " +to_string(i)+", "+to_string(MatchStringUB(inf.op1->Name())));
            }
        }

        if (MatchNegationUB(inf.op2->Name()))
        {
            if (!MatchNegationUB(inf.op1->Name()))
            {
                BoolExp* tmp = new NotExp(inf.op1);
                _starred[i] = 1;
                AddPremise(tmp,tmp->Type(),
                           "(A->B), ~B |- ~A on "+to_string(i)+", "+to_string(MatchNegationUB(inf.op2->Name())));
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

    //check for a usable formula, I need three cases one for each binary formula
    for (int i = 0; i < _premcount; i++)
    {
        BoolReturn inf = _premi[0]->Infer();
        inf = _premi[i]->Infer();
        if(_premi[i]->Type() == NOT_EXP && _premi[i]->Infer().op1->Type() == AND_EXP &&
                (!MatchNegationUB( _premi[i]->Infer().op1->Infer().op1->Name()  )
                 ||!MatchNegationUB( _premi[i]->Infer().op1->Infer().op1->Name()  )))
        {
            if (!MatchStringUB(inf.op1->Infer().op1->Name()))
            {
                //TODO: possibly not working right
                ++_highestasm;
                AddPremise(inf.op1->Infer().op1,inf.op1->Infer().op1->Type(), "negated and assumption to break "+ to_string(i));
                break;
            }
            if (!MatchStringUB(inf.op1->Infer().op2->Name()))
            {
                //TODO: possibly not working right
                ++_highestasm;
                AddPremise(inf.op1->Infer().op2,inf.op1->Infer().op2->Type(), "negated and assumption to break "+ to_string(i));
                break;
            }

        }
        if(_premi[i]->Type() == OR_EXP &&
                (!MatchNegationUB(inf.op1->Name())||!MatchNegationUB(inf.op2->Name())))
        {
            //TODO: possibly not working right
            if (!MatchStringUB(inf.op1->Name()))
            {
                ++_highestasm;
                AddPremise(inf.op1,inf.op1->Type(), "or assumption to break " + to_string(i));
                break;
            }
        }
        if(_premi[i]->Type() == COND_EXP &&
                (!MatchStringUB(inf.op1->Name())||!MatchNegationUB(inf.op2->Name())))
        {
            if (!MatchStringUB(inf.op1->Name()))
            {
                ++_highestasm;
                AddPremise(inf.op1,inf.op1->Type(), "conditional assumption to break " + to_string(i));
                break;
            }
        }

    }
}

bool Prover::FindContradiction()
{
    //use match negation, check each formula for its own negation
    bool ret = false;
    int contraa = -1;
    int contrab = -1;
    for (unsigned int i = 0; i < _premi.size(); i++)
    {
        if (MatchNegationUB(_premi[i]->Name()))
        {
            cout << "Negation of line " << i << " found!" << endl;
            ret = true;
            _highestasm--;
            contraa = i;
            contrab = MatchNegationUB(_premi[i]->Name());
            //_assum[i] = -1;
            break;
        }
    }
    //block off all lines at the previous assumption level
    if (ret == true)
    {
        int k = 0;
        while(_assum[k]!=_highestasm+1) k++;
        BoolExp* tmp = new NotExp(_premi[k]);
        if(_highestasm) AddPremise(tmp,tmp->Type(), "by contradiction "+to_string(contraa)+", "+to_string(contrab));
        for (unsigned int i = 0; i < _premi.size(); i++)
        {
            if (_assum[i] ==_highestasm+1||_blocked[i])
            {
                _blocked[i]++;
                _assum[i] = -1;
            }
        }
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
        cout << j << ") ";
        if(_blocked[j] > 0)
        {
            for (int k = _blocked[j]; k != 0; k--)
            {
                cout << "[";
            }
        }
        cout << " " << _premi[j]->Name();
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
