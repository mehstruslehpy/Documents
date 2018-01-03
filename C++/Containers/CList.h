/************************
Author: Mehstruslehpy
Date:   24 Dec 2017
************************/

//a clist is not a linked list

#ifndef CLIST_MEH_
#define CLIST_MEH_
#include "CArray.h"

using namespace std;

template <class T>
class CList
{
    CArray<T> _impl;
public:
    CList ();
    CList ( const CList<T>& );
    CList ( const CArray<T>& );
    CList ( const T*, int s);

    ~CList ( ); //dtor

    CList<T>& operator= ( const CList<T>& );
    CList<T>& operator= ( const CArray<T>& );

    template <typename OS>
    friend ostream& operator<< ( ostream&, const CList<OS>& );

    template <typename OS> // print
    friend ostream& operator<< ( ostream&, const CList<OS>* );

    //CArray<T> operator( ) ( int first, int last )const;
    CList<T> subList( int first, int last ) const;
    CArray<T> subArray( int first, int last ) const;

    int length ( ) const;	//these are the same
    int size ( ) const;
    bool isEmpty() const;

    CList<T> tail() const; //return a list containing everything but the last element
    CList<T> cdr() const;	//same as tail
    CList<T> head() const;	//return a list containing only the first element
    CList<T> car() const;	//same as head

    void insert(int,T); //insert a T at int
    void insert(T); //insert a T at int
    void append(T);     //append a T to the end
    void append(CList<T>&);	//append a CList to the end
    void append(CArray<T>&); //append a CArray to the end
    void remove();	//remove the last thing
    void remove(int); //remove the thing at int
    void remove(int,int); //remove a range of things
    int contains(T) const; //search the list for a T return the index of the first occurence
    int count(T) const; //count occurences of given T
    T at(int = 0) const; //returns a T in the list by default the 0th element or head

    void write ( ofstream& ) const;
    void read ( ifstream& );

};

#endif

template <typename T>
CList<T>::CList ()
    : _impl()
{}

template <typename T>
CList<T>::CList ( const CList<T>& sp)
    : _impl(sp._impl)
{}

template <typename T>
CList<T>::CList ( const T* arr, int s)
    : _impl(arr,s)
{}

//clists are not meant to be used with virtual indices
template <typename T>
CList<T>::CList ( const CArray<T>& arr)
    : _impl(arr)
{
    _impl.writeVindex(0);
}

template <typename T>
CList<T>::~CList ( )
{}

template <typename T>
CList<T>& CList<T>::operator= ( const CList<T>& sp)
{
    //check for self assignment
    if (this == &sp) return *this;
    _impl = CArray<T>(sp._impl); //copy construct a new copy
    return *this;
}

template <typename T>
CList<T>& CList<T>::operator= ( const CArray<T>& rp)
{
    if (&_impl == &rp) return *this;
    _impl = CArray<T>(rp);
    _impl.writeVindex(0);	//overwrite any old vindex
    return *this;

}

template <typename OS>
ostream& operator<< ( ostream& osm, const CList<OS>& rhs)
{
    osm << rhs._impl;
    return osm;
}

template <typename OS>
ostream& operator<< ( ostream& osm, const CList<OS>* rhs)
{
    return operator<<(osm, *rhs);
}

//return a list of the current list
template <typename T>
CList<T> CList<T>::subList( int first, int last ) const
{
    return CList<T>(_impl(first,last));
}

//return a subarray off the current list
template <typename T>
CArray<T> CList<T>::subArray( int first, int last) const
{
    return CArray<T>(_impl(first,last));
}

template <typename T>
int CList<T>::length ( ) const
{
    return _impl.length();
}
template <typename T>
int CList<T>::size ( ) const
{
    return _impl.length();
}

template <typename T>
bool CList<T>::isEmpty() const
{
    if (size() <= 0) return true;
    return false;
}

template <typename T>
void CList<T>::write ( ofstream& outf) const
{
    _impl.write(outf);
}
template <typename T>
void CList<T>::read ( ifstream& inf)
{
    _impl.read(inf);
}

template <typename T>
CList<T> CList<T>::tail() const
{
    return CList(_impl.operator()(1,length()));
}

template <typename T>
CList<T> CList<T>::cdr() const
{
    return CList(_impl.operator()(1,length()));
}

template <typename T>
CList<T> CList<T>::head() const
{
    return CList(_impl.operator()(0,1));
}

template <typename T>
CList<T> CList<T>::car() const
{
    return CList(_impl.operator()(0,1));
}

template <typename T>
void CList<T>::insert(int i, T x)
{
    _impl.add(i, x);
}

template <typename T>
void CList<T>::insert(T x)
{
    _impl.add(x);
}

template <typename T>
void CList<T>::append(T x)
{
    _impl.append(x);
}

template <typename T>
void CList<T>::append(CList<T>& lst)
{
    _impl.append(lst._impl);
}

template <typename T>
void CList<T>::append(CArray<T>& rub)
{
    _impl.append(rub);
    _impl.writeVindex(0);
}

template <typename T>
void CList<T>::remove()
{
    _impl.remove();
}

template <typename T>
void CList<T>::remove(int i)
{
    _impl.remove(i);
}

template <typename T>
void CList<T>::remove(int i, int j)
{
    _impl.remove(i,j);
}

template <typename T>
int CList<T>::contains(T t) const
{
    for (int i = 0; i < size(); i++)
    {
        if ( _impl[i] == t) return i;
    }
    return -1;
}

template <typename T>
int CList<T>::count(T t) const
{
    int count = 0;
    for (int i = 0; i < size(); i++)
    {
        if ( _impl[i] == t) count++;
    }
    return count;
}

template <typename T>
T CList<T>::at(int i) const
{
    return _impl[i];
}
