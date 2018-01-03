/************************
Author: Mehstruslehpy
Date:   24 Dec 2017
************************/

//despite the LList having a similar interface to my vector I chose
//against public inheritance because the inner workings are too different
//to justify the hassle.

#ifndef LLIST_MEH_
#define LLIST_MEH_
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

template <class T>
class LList
{
    //struct to hold nodes
    struct LNode
    {
        T _value;
        LNode* _next;
    };

    LNode* _head;
    int _len; //num of things in the list

    //delete the contents of a LList
    void dellist();

public:
    LList ();
    LList ( const T*, int);
    LList ( const LList<T>& );

    ~LList ( );

    LList<T>& operator= ( const LList<T>& );

    template <typename OS>
    friend ostream& operator<< ( ostream&, const LList<OS>& );
    template <typename OS>
    friend ostream& operator<< ( ostream&, const LList<OS>* );

    T& operator[] ( int );
    const T& operator[] ( int ) const;

    T at ( int = 0 ) const;

    // Returns a sub list from index first to index last-1
    LList<T> operator( ) ( int first, int last)const;

    void append ( const T& ); //[1][2]
    void append ( const LList<T>& );

    int length ( ) const
    {
        return _len;
    };

    void add ( int index, const T& );
    void add ( const T& );

    void remove ( );
    void remove ( int index );
    void remove ( int first, int last );

    void write ( ofstream& )const;
    void read ( ifstream& );

    // member functions specific to a list

    //RubberArray<T> operator( ) ( int first, int last )const;
    LList<T> subList( int first, int last ) const;

    int size() const;
    bool isEmpty() const;

    LList<T> tail() const; //return a list containing everything but the last element
    LList<T> cdr() const;   //same as tail
    LList<T> head() const;  //return a list containing only the first element
    LList<T> car() const;   //same as head

    void insert(int,T); //insert a T at int
    void insert(T); //insert a T at int
    int contains(T) const; //search the list for a T return the index of the first occurence
    int count(T) const; //count occurences of given T
};

#endif

template <class T>
LList<T>::LList ()
    :_head(NULL), _len(0)
{}

template <class T>
LList<T>::LList ( const T* Array, int s )
    :_head(NULL), _len(0)
{
    for (int i = 0; i < s; ++i)
    {
        append(Array[i]);
    }
}

template <class T>
LList<T>::LList ( const LList<T>& ra)
    :_head(NULL), _len(0)
{
    append(ra);
}

template <class T>
LList<T>::~LList ( )
{
    dellist();
}

template <class T>
void  LList<T>::dellist()
{
    LNode* nodePtr;
    LNode* nextNode;

    nodePtr = _head;

    while (nodePtr != NULL)
    {
        nextNode = nodePtr->_next;
        delete nodePtr;
        nodePtr = nextNode;
    }

    //clean up the loose ends
    _head = NULL;
    _len = 0;
}

template <class T>
LList<T>& LList<T>::operator= ( const LList<T>& ra)
{
    if (this != &ra)
    {
        dellist();	//destroy old LList contents
        for (int i = 0; i < ra._len; ++i) //create a new one from the old one
            append(ra.at(i));
    }
    return *this;

}

//TODO: get rid of that auto if possible
template <typename OS>
ostream& operator<< ( ostream& os, const LList<OS>& ra)
{
    if (!ra._head || ra._len <= 0)
    {
        return os;
    }
    else
    {
        auto nodePtr = ra._head;	//i'd prefer not to use auto...
        os << nodePtr->_value;
        while (nodePtr->_next)
        {
            nodePtr = nodePtr->_next;
            os << ", " <<nodePtr->_value;
        }
    }
    return os;
}

template <typename OS>
ostream& operator<< ( ostream& os, const LList<OS>* ra)
{
    os << *ra;
    return os;
}

//TODO: this is super slow, I might try and speed this up?
//		I shouldn't be able to since this is how singly linked
//		list access works
template <class T>
T& LList<T>::operator[] ( int index )
{
    //check the index
    if ( index < 0 || index > _len )
    {
        throw int(1);
    }

    LNode* nodePtr = NULL;

    if (!_head)
    {
        throw int(2); //list is empty
    }
    else
    {
        nodePtr = _head;
        for (int i = 0; i < index; i++)
        {
            nodePtr = nodePtr->_next;
        }
        return nodePtr->_value;
    }
}
//see above
template <class T>
T LList<T>::at ( int index ) const
{
    //check the index
    if ( index < 0 || index > _len )
    {
        throw int(3);
    }

    LNode* nodePtr = NULL;

    if (!_head)
    {
        throw int(4); //list is empty
    }
    else
    {
        nodePtr = _head;
        for (int i = 0; i < index; i++)
        {
            nodePtr = nodePtr->_next;
        }
        return nodePtr->_value;
    }
}
template <class T>
const T& LList<T>::operator[] ( int index ) const
{
    //check the index
    if ( index < 0 || index > _len )
    {
        throw int(5);
    }

    LNode* nodePtr = NULL;

    if (!_head)
    {
        throw int(6); //list is empty
    }
    else
    {
        nodePtr = _head;
        for (int i = 0; i < index; i++)
        {
            nodePtr = nodePtr->_next;
        }
        return nodePtr->_value;
    }
}

//TODO: optimize
template <class T>
LList<T> LList<T>::operator( ) ( int first, int last ) const
{
    //check the index
    if ( first < 0 || first > _len || last <= first ||
            last < 0  || last > _len)
    {
        throw int(7);
    }

    //empty list
    if (_len <= 0)
    {
        throw int(8);
    }

    //construct a list based on a sublist
    LList<T> temp;
    for(int i = first; i < last; ++i)
    {
        temp.append(at(i));
    }

    return LList<T>(temp);
}

//TODO: optimize
template <class T>
void LList<T>::append ( const T& item)
{
    LNode* newNode;
    LNode* nodePtr;

    newNode = new LNode;
    newNode->_value = item;
    newNode->_next = NULL;

    if (!_head)
    {
        _head = newNode;
    }
    else
    {
        nodePtr =_head;
        while (nodePtr->_next)
        {
            nodePtr = nodePtr->_next;
        }
        nodePtr->_next = newNode;
    }
    ++_len;
}

//TODO:optimize me
template <class T>
void LList<T>::append ( const LList<T>& la)
{
    //for appending to self we need a temp length
    int templ = la.length();

    //la.at() will catch any empty lists
    for(int i = 0; i < templ; ++i)
    {
        append(la.at(i));
    }
}

//TODO: optimize
template <class T>
void LList<T>::add ( int index, const T& rt)
{
    //check the index
    if ( index < 0 || index > _len)
    {
        throw int(9);
    }

    LNode* newNode;
    LNode* nodePtr;
    LNode* prevNode = NULL;

    newNode = new LNode;
    newNode->_value = rt;

    if (!_head)
    {
        _head = newNode;
        newNode->_next = NULL;
    }
    else
    {
        nodePtr = _head;
        prevNode = NULL;

        for (int i = 0; i < index; i++)
        {
            prevNode = nodePtr;
            nodePtr = nodePtr->_next;
        }

        if ( prevNode == NULL)
        {
            _head = newNode;
            newNode->_next = nodePtr;
        }
        else
        {
            prevNode->_next = newNode;
            newNode->_next = nodePtr;
        }
    }
    ++_len;

}

//TODO: optimize
template <class T>
void LList<T>::add ( const T& rt)
{
    LNode* newNode;
    LNode* oldNode;

    newNode = new LNode;
    newNode->_value = rt;
    newNode->_next = NULL;

    if (!_head)
    {
        _head = newNode;
    }
    else
    {
        oldNode =_head;
        _head = newNode;
        _head->_next = oldNode;
    }
    ++_len;

}

template <class T>
void LList<T>::remove ( )
{
    remove(length()-1);
}

template <class T>
void LList<T>::remove ( int index )
{
    //check if list is empty
    if (_len <= 0)
    {
        throw int (11);
    }
    //check the index
    //>= because we count at 0 so the index of _len is one past the end
    if ( index < 0 || index >= _len )
    {
        throw int(12);
    }

    LNode* prevNode = NULL;
    LNode* nextNode = _head;


    for (int i = 0; i < index; i++)
    {
        prevNode = nextNode;
        nextNode = nextNode->_next;
    }

    if ( prevNode == NULL)
    {
        _head = nextNode->_next;
        delete nextNode;
    }
    else
    {
        prevNode->_next = nextNode->_next;
        delete nextNode;
    }
    _len--;
}

template <class T>
void LList<T>::remove ( int first, int last )
{
    //check if list is empty
    if (_len <= 0)
    {
        throw int (13);
    }

    //check the index for a bunch of weirdness
    //>= because we count at 0 so the index of _len is one past the end
    if ( first < 0 || first >= _len || first >= last ||
            last < 0  || last >= _len )
    {
        throw int(14);
    }

    for (int i = first; i < last; ++i)
    {
        remove(first);
    }
}

template <class T>
void LList<T>::write ( ofstream& outf )const
{
    if (outf)
    {
        if (!_head)
        {
            //list is empty cannot write an empty list
            throw int(15);
        }
        else
        {
            //write out the length to the start of the file
            outf.write(reinterpret_cast<const char*>(&_len), sizeof(_len));

            //begin writing values
            LNode* nodePtr = _head;	//i'd prefer not to use auto...

            //write out the first T
            outf.write(reinterpret_cast<const char*>(&nodePtr->_value), sizeof(nodePtr->_value));

            //loop til the end writing out T's
            while (nodePtr->_next)
            {
                nodePtr = nodePtr->_next;
                outf.write(reinterpret_cast<const char*>(&nodePtr->_value), sizeof(nodePtr->_value));
            }
        }
    }
}

template <class T>
void LList<T>::read ( ifstream& inf)
{
    if (inf)
    {
        if (_head != NULL)
        {
            //list is not empty cannot read into a non empty list
            throw int(1);
        }
        else
        {
            int templ = 0;	//need a temporary length value to prevent inf loop
            T value;		//need a T to store values read in from the file

            //read in the length from the start of the file
            inf.read(reinterpret_cast<char*>(&templ), sizeof(templ));

            //read in the first T and append it
            inf.read(reinterpret_cast<char*>(&value), sizeof(value));
            append(value);

            //loop til the end reading in T's
            for (int i = _len; i < templ; ++i)
            {
                inf.read(reinterpret_cast<char*>(&value), sizeof(value));
                append(value);
            }
        }
    }
}

template <class T>
LList<T> LList<T>::subList( int first, int last ) const
{
    return operator()(first,last);
}

template <class T>
int LList<T>::size ( ) const
{
    return length();
}

template <class T>
bool LList<T>::isEmpty() const
{
    if (size() <= 0) return true;
    return false;
}

template <class T>
LList<T> LList<T>::tail() const
{
    return LList<T>(operator()(1,length()));
}

template <class T>
LList<T> LList<T>::cdr() const
{
    return LList<T>(operator()(1,length()));
}

template <class T>
LList<T> LList<T>::head() const
{
    return LList<T>(operator()(0,1));
}

template <class T>
LList<T> LList<T>::car() const
{
    return LList<T>(operator()(0,1));
}

template <class T>
void LList<T>::insert(int i,T x)
{
    add(i,x);
}

template <class T>
void LList<T>::insert(T x)
{
    add(x);
}

template <class T>
int LList<T>::contains(T value) const
{
    if (!_head || _len <= 0)
    {
        return -1;
    }
    else
    {
        int it = 0;
        auto nodePtr = _head;	//i'd prefer not to use auto...
        if (nodePtr->_value == value) return it;
        ++it;
        while (nodePtr->_next)
        {
            nodePtr = nodePtr->_next;
            if (nodePtr->_value == value) return it;
            ++it;
        }
    }
    return -1;
}

template <class T>
int LList<T>::count(T value) const
{
    int total = 0;
    if (!_head || _len <= 0)
    {
        return 0;
    }
    else
    {
        auto nodePtr = _head;
        if (nodePtr->_value == value) total++;
        while (nodePtr->_next)
        {
            nodePtr = nodePtr->_next;
            if (nodePtr->_value == value) total++;
        }
    }
    return total;
}

