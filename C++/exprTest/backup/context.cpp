#include "context.h"
#include "varexp.h"
//class VarExp; //forward decl
bool Context::Lookup(const char* str) const
{
	auto i = _map.find(string(str));
	if (i == _map.end()) 
	{
		cout << "Query for unregistered variable" << endl;
		abort();
	}
	return i->second;
	
}

void Context::Assign(VarExp* var, bool trf)	//trf like true false
{
	_map.insert(std::pair<string,bool>(string(var->_name),trf));
}
