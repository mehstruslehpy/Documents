#include "boolexp.h"
BoolReturn::BoolReturn(BoolExp* o1, BoolExp* o2)
    :op1(o1), op2(o2)
{}

BoolExp::BoolExp (PropType p)
    : _type(p)
{}
//BoolExp::BoolExp ( const BoolExp& )
//{}
BoolExp::~BoolExp ( )
{}
PropType BoolExp::Type() const
{
    return _type;
}
