/************************
Author: Mehstruslehpy
Date:   24 Dec 2017
************************/

#ifndef CSTACK_MEH_
#define CSTACK_MEH_
#include "CArray.h"

using namespace std;

template <class T>
class CStack
{
    //my stack is built on top of a CArray
    CArray<T> _impl;

public:
    CStack ();	//default ctor
    CStack ( const CStack<T>& );	//copy ctor
    CStack ( const CArray<T>& );	//this might be a bad choice
    CStack ( const T*, int s);

    ~CStack ( ); //dtor

    CStack<T>& operator= ( const CStack<T>& ); //op= on a stack
    CStack<T>& operator= ( const CArray<T>& ); //op= on a CArray

    template <typename OS> // print
    friend ostream& operator<< ( ostream&, const CStack<OS>& );

    template <typename OS> // print
    friend ostream& operator<< ( ostream&, const CStack<OS>* );

    //CArray<T> operator( ) ( int first, int last )const;
    CStack<T> subCStack( int first, int last ) const;
    CArray<T> subArray( int first, int last ) const;

    T peek (int = 0);
    void push ( const T& ); //push a single elem onto a stack
    void push ( const T*, int s); //push an array onto a stack
    void push ( const CStack<T>& ); //push a stack onto a stack
    void push ( const CArray<T>& ); //push a CArray onto a stack
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
CStack<T>::CStack ()
    : _impl()
{}

template <typename T>
CStack<T>::CStack ( const CStack<T>& sp)
    : _impl(sp._impl)
{}

template <typename T>
CStack<T>::CStack ( const T* arr, int s)
    : _impl(arr,s)
{}

//stacks are not meant to be used with virtual indices
template <typename T>
CStack<T>::CStack ( const CArray<T>& arr)
    : _impl(arr)
{
    _impl.writeVindex(0);
}

template <typename T>
CStack<T>::~CStack ( )
{}

template <typename T>
CStack<T>& CStack<T>::operator= ( const CStack<T>& sp)
{
    //check for self assignment
    if (this == &sp) return *this;
    _impl = CArray<T>(sp._impl); //copy construct a new copy
    return *this;
}

template <typename T>
CStack<T>& CStack<T>::operator= ( const CArray<T>& rp)
{
    if (&_impl == &rp) return *this;
    _impl = CArray<T>(rp);
    _impl.writeVindex(0);	//overwrite any old vindex
    return *this;

}

template <typename OS>
ostream& operator<< ( ostream& osm, const CStack<OS>& rhs)
{
    osm << rhs._impl;
    return osm;
}

template <typename OS>
ostream& operator<< ( ostream& osm, const CStack<OS>* rhs)
{
    return operator<<(osm, *rhs);
}

//return a substack of the current stack
template <typename T>
CStack<T> CStack<T>::subCStack( int first, int last ) const
{
    return CStack<T>(_impl(first,last));
}

//return a subarray off the current stack
template <typename T>
CArray<T> CStack<T>::subArray( int first, int last) const
{
    return CArray<T>(_impl(first,last));
}

//note: any invalid indices will be caught by impl's op[]
template <typename T>
T CStack<T>::peek (int i)
{
    return _impl[i];
}

template <typename T>
void CStack<T>::push ( const T* arr, int s)
{
    for (int i = 0; i < s; ++i)
    {
        _impl.append(arr[i]);
    }

}

template <typename T>
void CStack<T>::push ( const T& in)
{
    _impl.append(in);
}

template <typename T>
void CStack<T>::push ( const CStack<T>& sp)
{
    _impl.append(sp._impl);
}

template <typename T>
void CStack<T>::push ( const CArray<T>& rp)
{
    _impl.append(rp);
}

//TODO: inefficient due to CArray remove()
template <typename T>
T CStack<T>::pop ( )
{
    T temp = _impl[_impl.length() - 1];
    _impl.remove();
    return temp;
}

template <typename T>
void CStack<T>::dupl( )
{
    T temp = pop();
    push(temp);
    push(temp);
}

template <typename T>
void CStack<T>::rrot (int i)
{
    T temp = pop(); //stksz--
    push(temp); 	//stksz++
    _impl.add(i,temp); //stksize++
    pop();		//stksz--
}

template <typename T>
void CStack<T>::lrot (int i)
{
    T temp = _impl[i]; //read the bottom item into a temp
    _impl.remove(i); //remove it
    push(temp); //push it onto the end
}

template <typename T>
void CStack<T>::swap ( )
{
    T tempa = pop();
    T tempb = pop();
    push(tempa);
    push(tempb);	//new top
}

template <typename T>
int CStack<T>::length ( ) const
{
    return _impl.length();
}
template <typename T>
int CStack<T>::size ( ) const
{
    return _impl.length();
}

template <typename T>
bool CStack<T>::isEmpty() const
{
    if (size() == 0) return true;
    return false;
}

template <typename T>
void CStack<T>::write ( ofstream& outf) const
{
    _impl.write(outf);
}
template <typename T>
void CStack<T>::read ( ifstream& inf)
{
    _impl.read(inf);
}

