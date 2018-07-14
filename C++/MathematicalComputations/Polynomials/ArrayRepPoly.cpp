#include "ArrayRepPoly.h"
static ostream& operator<<(ostream& os, vector<int>& invec)
{
	for (unsigned int i = 0; i < invec.size(); i++) os << invec[i] << " ";
	return os;
}
ArrayRepPoly::ArrayRepPoly()
    : _coeff(), _varname("x")
{}
ArrayRepPoly::ArrayRepPoly(int* inarr, string var,unsigned int arrcount)
{
	if (inarr == NULL)
	{
		Error("ERROR: ArrayRepPoly::ArrayRepPoly(int*, string,unsigned int):"
				"nullpointer passed to constructor expecting integer array");
	}
	_varname = var;
    for (unsigned int i = 0; i < arrcount; i++)
    {
        _coeff.push_back(inarr[i]);
    }
}
ArrayRepPoly::ArrayRepPoly(vector<int>& invec, string var)
{
    _varname = var;
    for (auto i : invec)
    {
        _coeff.push_back(i);
    }
}
ArrayRepPoly::ArrayRepPoly(const vector<int>& invec, string var, unsigned int arrcount)
{
    _varname = var;
    for (unsigned int i = 0; i < arrcount; i++)
    {
        _coeff.push_back(invec[i]);
    }
}
double ArrayRepPoly::operator() (double arg) const
{
    return Evaluate(arg);
}
double ArrayRepPoly::Evaluate(double arg) const
{
    double sum = 0;
    unsigned int size = _coeff.size();
    for (unsigned int i = 0; i < _coeff.size(); i++)
    {
        if (_coeff[i]==0) continue;
        sum += _coeff[i]*pow(arg,size-i-1);
    }
    return sum;
}
//keep or drop 0 coefficients?
string ArrayRepPoly::Name() const
{
    string name = "";
    //cout << endl <<"size:"<< _coeff.size() << endl;
	if (_coeff.size() == 0) return "0";
	for (unsigned int i = 0; i < _coeff.size(); i++)
    {
        if (_coeff[i]==0) continue;
        if (i!=0) name += "+ ";
        if (_coeff[i]!=1||i==_coeff.size()-1) name += to_string(_coeff[i]);
        if (_coeff.size()-i-1!=0) name += (_coeff[i]!=1?"*":"")
                                              +_varname
                                              +(_coeff.size()-i-1!=1?"^"+to_string(_coeff.size()-i-1):"");
        if (i < _coeff.size()-1)name += " ";
    }
    return name;
}
unsigned int ArrayRepPoly::Order() const
{
    return _coeff.size() - 1;
}
vector<int> ArrayRepPoly::Coeff()
{
    return vector<int>(_coeff);
}
ostream& operator<< ( ostream& os, ArrayRepPoly& poly)
{
    os << poly.Name();
    return os;
}
ostream& operator<< ( ostream& os, const ArrayRepPoly& poly)
{
    os << poly.Name();
    return os;
}
ostream& operator<< ( ostream& os, ArrayRepPoly* poly)
{
    os << poly->Name();
    return os;
}
ArrayRepPoly& ArrayRepPoly::operator+= (const ArrayRepPoly& rhs)
{
    int bigcount = 0;
    vector<int> newCoeff;

    if (rhs.Order() > Order())
        bigcount = rhs.Order();
    else
        bigcount = Order();

    for (int i = bigcount; i >= 0; i--)
    {
        newCoeff.push_back(Term(i)+rhs.Term(i));
    }
    _coeff = newCoeff;
	ClearLeadingZeros();
    return *this;
}
ArrayRepPoly ArrayRepPoly::operator+ (const ArrayRepPoly& rhs)
{
	ClearLeadingZeros();
    return ArrayRepPoly(*this) += rhs;
}
int ArrayRepPoly::Term(unsigned int exp) const
{
    if (exp>Order())
    {
        return 0;
    }
    else
    {
        return _coeff[Order()-exp];
    }
}
ArrayRepPoly& ArrayRepPoly::operator-= (const ArrayRepPoly& rhs)
{
    int bigcount = 0;
    vector<int> newCoeff;

    if (rhs.Order() > Order())
        bigcount = rhs.Order();
    else
        bigcount = Order();

    for (int i = bigcount; i >= 0; i--)
    {
        newCoeff.push_back(Term(i)-rhs.Term(i));
    }
    _coeff = newCoeff;
	ClearLeadingZeros();
    return *this;
}
ArrayRepPoly ArrayRepPoly::operator- (const ArrayRepPoly& rhs)
{
	ClearLeadingZeros();
    return ArrayRepPoly(*this) -= rhs;
}
void ArrayRepPoly::Scale(double scalar)
{
	ClearLeadingZeros();
    for (auto i : _coeff)
    {
        _coeff[i]*=scalar;
    }
}
ArrayRepPoly& ArrayRepPoly::operator*= (double scalar)
{
    Scale(scalar);
	ClearLeadingZeros();
    return *this;
}
ArrayRepPoly operator* (double lhs,const ArrayRepPoly& rhs)
{
	//ClearLeadingZeros();
    //rhs.ClearLeadingZeros();
	return ArrayRepPoly(rhs)*=lhs;
}
ArrayRepPoly ArrayRepPoly::operator* (double rhs)
{
	ClearLeadingZeros();
    return ArrayRepPoly(*this) *= rhs;
}
//polynomial multiplication
ArrayRepPoly& ArrayRepPoly::operator*= (const ArrayRepPoly& rhs)
{
    unsigned int newOrder = 0;
    ArrayRepPoly accumPoly;
    ArrayRepPoly tempPoly;
    double currentCoeff = 0;

    //get the order of the result
    newOrder = rhs.Order() + Order();

    //shift the accumulator poly by the correct amount
    for (unsigned int i = 0; i <= newOrder; i++)
    {
        accumPoly._coeff.push_back(0);
    }

    //polynomial multiplication
    for (unsigned int i = 0; i < newOrder; i++)
    {
        //get the current coefficient
        currentCoeff = rhs.Term(i);

        //set up temp poly from the current poly
        tempPoly = ArrayRepPoly(_coeff,_varname);

        //scale the temp poly by the current coefficient
        for (unsigned int j = 0; j <= tempPoly.Order(); j++)
        {
            tempPoly._coeff[j] *= currentCoeff;
        }

        //shift the temp poly by the correct amount
        for (unsigned int j = 0; j < i; j++)
        {
            tempPoly._coeff.push_back(0);
        }

        //add the temp poly to the new poly
        accumPoly += tempPoly;
    }
    //clear leftover leading zeros
	/*for (auto it = accumPoly._coeff.begin(); it != accumPoly._coeff.end();)
    {
    	if (*it == 0)
		{
			accumPoly._coeff.erase(it);
		}
		else
		{
			it++;
		}
	}*/
	accumPoly.ClearLeadingZeros();
    accumPoly._varname = _varname;
    //set *this to the result
    *this = accumPoly;
	
	ClearLeadingZeros();
    
	return *this;
}

ArrayRepPoly ArrayRepPoly::operator* (const ArrayRepPoly& rhs)
{
	ClearLeadingZeros();
    return ArrayRepPoly(*this) *= rhs;
}
ArrayRepPoly ArrayRepPoly::Derivative()
{
    ArrayRepPoly tempPoly;
    tempPoly._varname=_varname;
    for (int i = Order(); i-1 >= 0; i--)
    {
        //cout << "i:" << i << endl;
        tempPoly._coeff.push_back(Term(i)*i);
    }
    //cout << "new order:" << tempPoly.Order() << endl;
    //cout << tempPoly << endl;
    //cout << "exit" << endl;
	ClearLeadingZeros();
    return ArrayRepPoly(tempPoly);
}
void ArrayRepPoly::ClearLeadingZeros()
{	
	for (auto it = _coeff.begin(); it != _coeff.end();)
    {
    	if (*it == 0)
		{
			_coeff.erase(it);
		}
		else
		{
			it++;
		}
	}
}
ArrayRepPoly ArrayRepPoly::IntegerPow(unsigned int pow)
{
	//if (pow == 0) return ArrayRepPoly({0,0},_varname,1);
	if (pow == 0) return ArrayRepPoly(*this-*this);
	ArrayRepPoly newPoly(*this);
	for(unsigned int i = 1; i < pow; i++)
	{
		newPoly *= *this;
	}
	return ArrayRepPoly(newPoly);
}
void ArrayRepPoly::Error(const string& errstr)
{
	cout <<endl<< errstr << endl;
	exit(EXIT_FAILURE);
}
