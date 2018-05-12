#include "orexp.h"
OrExp::OrExp ( BoolExp* op1, BoolExp* op2)
{
	_operand1 = op1;
	_operand2 = op2;
}

OrExp::~OrExp ( )//need to make sure the destructor of the pointed to item gets called
{}

bool OrExp::Evaluate(Context& con)
{
	bool val1 = _operand1->Evaluate(con);
	bool val2 = _operand2->Evaluate(con);

	return val1 || val2;
}

BoolExp* OrExp::Replace(const char* name, BoolExp& exp)
{
	return new OrExp(_operand1->Replace(name,exp),
					  _operand2->Replace(name,exp));
}

BoolExp* OrExp::Copy() const
{
	return new OrExp(_operand1->Copy(),
					  _operand2->Copy());
}

string OrExp::Name() const
{
	string ret = "(" + _operand1->Name() + " v " + _operand2->Name() + ")";
	return ret;
}
