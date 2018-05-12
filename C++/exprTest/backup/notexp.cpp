#include "notexp.h"
NotExp::NotExp ( BoolExp* op)
{
	_operand = op;
}

NotExp::~NotExp ( )//need to make sure the destructor of the pointed to item gets called
{}

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
