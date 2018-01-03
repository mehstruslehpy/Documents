/************************
Author: Mehstruslehpy
Date:   24 Dec 2017
************************/

#ifndef LSTACK_MEH_
#define LSTACK_MEH_
#include "LList.h"

using namespace std;

template <class T>
class LStack
{
    //my stack is built on top of a carray
    LList<T> _impl;

public:
    LStack ();	//default ctor
    LStack ( const LStack<T>& );	//copy ctor
    LStack ( const LList<T>& );	//this might be a bad choice
    LStack ( const T*, int s);

    ~LStack ( ); //dtor

    LStack<T>& operator= ( const LStack<T>& ); //op= on a stack
    LStack<T>& operator= ( const LList<T>& ); //op= on a CArray

    template <typename OS> // print
    friend ostream& operator<< ( ostream&, const LStack<OS>& );

    template <typename OS> // print
    friend ostream& operator<< ( ostream&, const LStack<OS>* );

    //LList<T> operator( ) ( int first, int last )const;
    LStack<T> subLStack( int first, int last ) const;
    LList<T> subArray( int first, int last ) const;

    T peek (int = 0);
    void push ( const T& ); //push a single elem onto a stack
    void push ( const T*, int s); //push an array onto a stack
    void push ( const LStack<T>& ); //push a stack onto a stack
    void push ( const LList<T>& ); //push a CArray onto a stack
    T pop ( );

    void dupl( );	//duplicate the top of stack
    void rrot (int = 0);	//rotate everything right or via
    void lrot (int = 0);	//an offset from the bottom
    void swap ( );	//swap the top of stack

    int length ( ) const;	//these are the same
    int size ( ) const;

    bool isEmpty() const;

    void write ( ofstream& ) const;
    void read ( ifstream& );

};

#endif

template <typename T>
LStack<T>::LStack ()
    : _impl()
{}

template <typename T>
LStack<T>::LStack ( const LStack<T>& sp)
    : _impl(sp._impl)
{}

template <typename T>
LStack<T>::LStack ( const T* arr, int s)
    : _impl(arr,s)
{}

//stacks are not meant to be used with virtual indices
template <typename T>
LStack<T>::LStack ( const LList<T>& arr)
    : _impl(arr)
{}

template <typename T>
LStack<T>::~LStack ( )
{}

template <typename T>
LStack<T>& LStack<T>::operator= ( const LStack<T>& sp)
{
    //check for self assignment
    if (this == &sp) return *this;
    _impl = LList<T>(sp._impl); //copy construct a new copy
    return *this;
}

template <typename T>
LStack<T>& LStack<T>::operator= ( const LList<T>& rp)
{
    if (&_impl == &rp) return *this;
    _impl = LList<T>(rp);
    return *this;

}

template <typename OS>
ostream& operator<< ( ostream& osm, const LStack<OS>& rhs)
{

    osm << rhs._impl;
    return osm;
}

template <typename OS>
ostream& operator<< ( ostream& osm, const LStack<OS>* rhs)
{
    return operator<<(osm, *rhs);
}

//return a substack of the current stack
template <typename T>
LStack<T> LStack<T>::subLStack( int first, int last ) const
{
    return LStack<T>(_impl(first,last));
}

//return a subarray off the current stack
template <typename T>
LList<T> LStack<T>::subArray( int first, int last) const
{
    return LList<T>(_impl(first,last));
}

//note: any invalid indices will be caught by impl's op[]
template <typename T>
T LStack<T>::peek (int i)
{
    return _impl[i];
}

template <typename T>
void LStack<T>::push ( const T* arr, int s)
{
    for (int i = 0; i < s; ++i)
    {
        _impl.append(arr[i]);
    }

}

template <typename T>
void LStack<T>::push ( const T& in)
{
    _impl.append(in);
}

template <typename T>
void LStack<T>::push ( const LStack<T>& sp)
{
    _impl.append(sp._impl);
}

template <typename T>
void LStack<T>::push ( const LList<T>& rp)
{
    _impl.append(rp);
}

//TODO: inefficient due to carray remove()
template <typename T>
T LStack<T>::pop ( )
{
    T temp = _impl[_impl.length() - 1];
    _impl.remove();
    return temp;
}

template <typename T>
void LStack<T>::dupl( )
{
    T temp = pop();
    push(temp);
    push(temp);
}

template <typename T>
void LStack<T>::rrot (int i)
{
    T temp = pop(); //stksz--
    push(temp); 	//stksz++
    _impl.add(i,temp); //stksize++
    pop();		//stksz--
}

template <typename T>
void LStack<T>::lrot (int i)
{
    T temp = _impl[i]; //read the bottom item into a temp
    _impl.remove(i); //remove it
    push(temp); //push it onto the end
}

template <typename T>
void LStack<T>::swap ( )
{
    T tempa = pop();
    T tempb = pop();
    push(tempa);
    push(tempb);	//new top
}

template <typename T>
int LStack<T>::length ( ) const
{
    return _impl.length();
}
template <typename T>
int LStack<T>::size ( ) const
{
    return _impl.length();
}

template <typename T>
bool LStack<T>::isEmpty() const
{
    if (size() == 0) return true;
    return false;
}

template <typename T>
void LStack<T>::write ( ofstream& outf) const
{
    _impl.write(outf);
}
template <typename T>
void LStack<T>::read ( ifstream& inf)
{
    _impl.read(inf);
}

