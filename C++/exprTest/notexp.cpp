#include "notexp.h"
NotExp::NotExp ( BoolExp* op)
    : BoolExp(NOT_EXP)
{
    _operand = op;
}

NotExp::~NotExp ( )
{
    if(_operand)
    {
        delete _operand;
        _operand = nullptr;
    }
}

bool NotExp::Evaluate(Context& con)
{
    return !_operand->Evaluate(con);
}

BoolExp* NotExp::Replace(const char* name, BoolExp& exp)
{
    return new NotExp(_operand->Replace(name,exp));
}

BoolExp* NotExp::Copy() const
{
    return new NotExp(_operand->Copy());
}

string NotExp::Name() const
{
    return "~" + _operand->Name();
}
BoolReturn NotExp::Infer()
{
    return BoolReturn(_operand, nullptr);
}

