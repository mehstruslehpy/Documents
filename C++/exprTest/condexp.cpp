#include "condexp.h"
CondExp::CondExp ( BoolExp* op1, BoolExp* op2)
    :BoolExp(COND_EXP)
{
    _operand1 = op1;
    _operand2 = op2;
}

CondExp::~CondExp ( )//need to make sure the destructor of the pointed to item gets called
{
    if(_operand1)
    {
        delete _operand1;
        _operand1 = nullptr;
    }
    if(_operand2)
    {
        delete _operand2;
        _operand2 = nullptr;
    }
}

bool CondExp::Evaluate(Context& con)
{
    bool val1 = _operand1->Evaluate(con);
    bool val2 = _operand2->Evaluate(con);

    return !(val1 && !val2);
}

BoolExp* CondExp::Replace(const char* name, BoolExp& exp)
{
    return new CondExp(_operand1->Replace(name,exp),
                       _operand2->Replace(name,exp));
}

BoolExp* CondExp::Copy() const
{
    return new CondExp(_operand1->Copy(),
                       _operand2->Copy());
}

string CondExp::Name() const
{
    string ret = "(" + _operand1->Name() + " -> " + _operand2->Name() + ")";
    return ret;
}
BoolReturn CondExp::Infer()
{
    return BoolReturn(_operand1,_operand2);
}
