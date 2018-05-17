#include "context.h"
#include "varexp.h"

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
void Context::DefaultAssign(const char* str)
{
    _map.insert(std::pair<string,bool>(str,true)); //default is true
}
void Context::AssignValues()
{
    bool trf = false;
    for (std::map<string,bool>::iterator it=_map.begin(); it!=_map.end(); ++it)
    {
        cout << it->first << " = ";
        cin >> trf;
        cin.ignore(256,'\n');
        _map.insert(std::pair<string,bool>(it->first,trf));
    }
}
void Context::AssignCombination(vector<bool>& combination)
{
    int i = 0;
    for (std::map<string,bool>::iterator it=_map.begin(); it!=_map.end(); ++it,++i)
    {
        it->second = combination[i];
    }
}
int Context::VarCount()
{
    int i = 0;
    for (std::map<string,bool>::iterator it=_map.begin(); it!=_map.end(); ++it)
    {
        ++i;
    }
    return i;
}

void Context::DumpContext()
{
    for (std::map<string,bool>::iterator it=_map.begin(); it!=_map.end(); ++it)
    {
        cout << it->first << "=" << it->second << endl;
    }
}
