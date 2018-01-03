/************************
Author: Mehstruslehpy
Date:   24 Dec 2017
************************/

#ifndef CARRAY_MEH_
#define CARRAY_MEH_
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

//NOTE: instances where the code previously used unsigned have been converted to integers, this has mainly been done
//to avoid comparing any unsigneds to ints. This does however effectively halve the total possible length usable by _len

template <class T>
class CArray
{
    T* _Array;  //storage for elements
    int _len; //num of elements
    int _alloc; //allocated memory
    int _Vindex; //virtual index

public:
    // Vindex is the virtual index of the first element
    CArray ( int Vindex = 0 );

    // s is the number of items pointed to by T*
    // Vindex is the virtual index of the first element in your CArray
    CArray ( const T*, int s, int Vindex = 0 );

    //Copy constructor
    CArray ( const CArray<T>& );

    //Destructor
    ~CArray ( ); //[1]

    //Assignment
    CArray<T>& operator= ( const CArray<T>& );

    // Insert the array or a pointer to an array into an ostream
    template <typename OS>
    friend ostream& operator<< ( ostream&, const CArray<OS>& );

    template <typename OS>
    friend ostream& operator<< ( ostream&, const CArray<OS>* );

    // access an item at index 0 <= Vindex < _items
    T& operator[] ( int Vindex );
    const T& operator[] ( int Vindex ) const;

    // Returns a sub array from virtual index Vfirst to index Vlast-1
    CArray<T> operator( ) ( int Vfirst, int Vlast )const;

    // Append either a new item or another CArray at index _items
    void append ( const T& );
    void append ( const CArray<T>& );

    // return the number of items in the array
    int length ( ) const
    {
        return _len;
    };

    // Add a new item at index 0 <= Vindex < _items
    void add ( int Vindex, const T& );

    // Add a new item at index 0
    void add ( const T& );

    // Remove the item at index _items-1
    void remove ( );

    // Remove the item at index 0 <= Vindex <_items
    void remove ( int Vindex );

    // Remove the items from index Vfirst through index Vlast-1
    void remove ( int Vfirst, int Vlast );

    // File IO functions to read or write the structure to a file
    void write ( ofstream& )const;
    void read ( ifstream& );

    // TODO: Possibly move these into private or protected?
    int readVindex() const
    {
        return _Vindex;
    }
    void writeVindex(int n)
    {
        _Vindex = n;
    }
};

#endif

template <class T>
CArray<T>::CArray ( int Vindex )
    : _Array(NULL), _len(0), _alloc(0), _Vindex (Vindex)
{}

template <class T>
CArray<T>::CArray ( const T* Array, int s, int Vindex )
    : _Array(NULL), _len(0), _alloc(0), _Vindex(Vindex)
{
    for (int i = 0; i < s; ++i)
    {
        append(Array[i]);
    }
}

template <class T>
CArray<T>::CArray ( const CArray<T>& ra)
    : _Array(NULL), _len(0), _alloc(0), _Vindex(ra._Vindex)
{
    for (int i = 0; i < ra._len; ++i)
    {
        append(ra._Array[i]);
    }
}

template <class T>
CArray<T>::~CArray ( )
{
    delete [] _Array;
    _Array = NULL;
    _len = 0;
    _alloc = 0;
}

template <class T>
CArray<T>& CArray<T>::operator= ( const CArray<T>& ra)
{
    if (this != &ra)
    {
        if (_len != 0)
            delete [] _Array;
        _Vindex = ra._Vindex;
        _Array = NULL;
        _len = 0;
        _alloc = 0;
        for (int i = 0; i < ra._len; ++i)
            append(ra._Array[i]);
    }
    return *this;
}

template <typename OS>
ostream& operator<< ( ostream& os, const CArray<OS>& ra)
{
    if (ra._len != 0)
    {
        os << ra._Array[0];
        for (int i = 1; i < ra._len; ++i)
        {
            os << ", " << ra._Array[i];
        }
    }
    return os;
}

template <typename OS>
ostream& operator<< ( ostream& os, const CArray<OS>* ra)
{
    if (ra->_len != 0)
    {
        os << ra->_Array[0];
        for (int i = 1; i < ra->_len; ++i)
        {
            os << ", " << ra->_Array[i];
        }
    }
    return os;
}

template <class T>
T& CArray<T>::operator[] ( int Vindex )
{
    int Aindex = Vindex - _Vindex;

    if ( Aindex < 0 || Aindex >= _len)
    {
        throw int(1);
    }
    return _Array[Aindex];
}

template <class T>
const T& CArray<T>::operator[] ( int Vindex ) const
{
    int Aindex = Vindex - _Vindex;
    if ( Aindex < 0 || Aindex >= _len)
    {
        throw int(2);
    }
    return _Array[Aindex];
}

template <class T>
CArray<T> CArray<T>::operator( ) ( int Vfirst, int Vlast ) const
{
    int Afirst =  Vfirst - _Vindex;
    int Alast = Vlast - _Vindex;

    if ( Afirst < 0 || Afirst >= Alast || Alast > _len)
    {
        throw int(3);
    }

    //create a temp CArray to return as the sub-array
    CArray<T> temp(_Vindex);
    for (int i = Afirst; i < Alast; ++i)
    {
        temp.append(_Array[i]);
    }

    return temp;
}

template <class T>
void CArray<T>::append ( const T& item)
{
    if (_len >= _alloc)
    {
        _alloc *= 2;
        ++_alloc;
        T* temp = new T[_alloc];

        for (int i = 0; i < _len; ++i)
            temp[i] = _Array[i];
        if (_len != 0)
            delete [] _Array;
        _Array = temp;
    }
    _Array[_len++] = item;
}

template <class T>
void CArray<T>::append ( const CArray<T>& ra)
{
    CArray<T> temp(ra._Array,ra.length());

    for (int i = 0; i < temp.length(); ++i)
    {
        append(temp._Array[i]);
    }
}

template <class T>
void CArray<T>::add ( int Vindex, const T& rt)
{
    int Aindex = Vindex - _Vindex;

    //check the index
    if ( Aindex < 0 || Aindex >= _len)
    {
        throw int(4);
    }

    //create temp based on the original array from 0 to Aindex-1
    CArray<T> temp(_Vindex);
    for (int i = 0; i < Aindex; ++i)
    {
        temp.append(_Array[i]);
    }

    //append the new element
    temp.append(rt);

    //add everything from the last element til the end
    for (int i = Aindex; i < _len; ++i)
    {
        temp.append(_Array[i]);
    }

    //set the virtual index for temp and set *this to temp to preserve the virtual index
    //between calls, without this calls to remove "clear" the user supplied virtual index
    temp._Vindex =_Vindex;
    *this = temp;
}

template <class T>
void CArray<T>::add ( const T& rt)
{
    add(_Vindex,rt);
}

template <class T>
void CArray<T>::remove ( )
{
    int Vindex = _Vindex + _len - 1;
    remove(Vindex);
}

template <class T>
void CArray<T>::remove ( int Vindex )
{
    int Aindex = Vindex - _Vindex;
    if ( Aindex < 0 || Aindex >= _len)
    {
        throw int(5);
    }
    CArray<T> temp(_Vindex);
    for (int i = 0; i < _len; ++i)
    {
        if (i != Aindex)
            temp.append(_Array[i]);
    }

    temp._Vindex = _Vindex;
    *this = temp;

}

template <class T>
void CArray<T>::remove ( int Vfirst, int Vlast )
{
    int Afirst =  Vfirst - _Vindex;
    int Alast = Vlast - _Vindex;

    if (Afirst >= _len || Alast < 0 || Afirst > Alast || Afirst ==  Alast || Alast > _len || Afirst < 0)
    {
        throw int(6);
    }

    for (int i = Afirst; i < Alast; ++i)
    {
        remove(Vfirst);   //this version of remove takes a virtual index
    }
}

template <class T>
void CArray<T>::write ( ofstream& outf )const
{
    if (outf)
    {
        outf.write(reinterpret_cast<const char*>(&_Vindex), sizeof(_Vindex));
        outf.write(reinterpret_cast<const char*>(&_len), sizeof(_len));
        outf.write(reinterpret_cast<const char*>(_Array), sizeof(T) * _len);
    }
}

template <class T>
void CArray<T>::read ( ifstream& inf)
{
    if (inf)
    {
        inf.read(reinterpret_cast<char*>(&_Vindex), sizeof(_Vindex));
        inf.read(reinterpret_cast<char*>(&_len), sizeof(_len));
        T* temp = new T[_len];
        inf.read(reinterpret_cast<char*>(temp), sizeof(T) * _len);
        CArray<T> R(temp, _len, _Vindex);
        *this = R;
        delete [] temp;
    }
}
