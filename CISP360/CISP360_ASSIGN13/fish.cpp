#include "fish.h"

Fish::Fish()
{
    name = "";
    value = 0;
}
///cppcheck (a linter) said specifying these as const would be more efficient
///it works with the old version too
///Fish::Fish(string n, int v)
Fish::Fish(const string n, const int v)
{
    name = n;
    value = v;
}
///void Fish::setName(string n)
void Fish::setName(const string n)
{
    name = n;
}
void Fish::setValue(const int v)
{
    value = v;
}
string Fish::getName()
{
    return name;
}
int Fish::getValue()
{
    return value;
}
