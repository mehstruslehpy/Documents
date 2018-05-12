#include "varexp.h"
VarExp::VarExp ( const char* nm)
{
	_name = strdup(nm); //change to strndup later
}

VarExp::~VarExp ( )
{
	free(_name);
}

bool VarExp::Evaluate(Context& con)
{
	return con.Lookup(_name);
}

BoolExp* VarExp::Replace(const char* name, BoolExp& exp)
{
	if (strcmp(name,_name) != 0)
	{
		return exp.Copy();
	}
	else
	{
		return new VarExp(_name);
	}
}

BoolExp* VarExp::Copy() const
{
	return new VarExp(_name);
}

string VarExp::Name() const
{
	return string(_name);
}
