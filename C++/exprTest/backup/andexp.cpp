#include "andexp.h"
AndExp::AndExp ( BoolExp* op1, BoolExp* op2)
{
	_operand1 = op1;
	_operand2 = op2;
}

AndExp::~AndExp ( )//need to make sure the destructor of the pointed to item gets called
{}

bool AndExp::Evaluate(Context& con)
{
	bool val1 = _operand1->Evaluate(con);
	bool val2 = _operand2->Evaluate(con);

	return val1 && val2;
}

BoolExp* AndExp::Replace(const char* name, BoolExp& exp)
{
	return new AndExp(_operand1->Replace(name,exp),
					  _operand2->Replace(name,exp));
}

BoolExp* AndExp::Copy() const
{
	return new AndExp(_operand1->Copy(),
					  _operand2->Copy());
}

string AndExp::Name() const
{
	string ret = "(" + _operand1->Name() + " & " + _operand2->Name() + ")";
	return ret;
}
