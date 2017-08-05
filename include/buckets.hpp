#ifndef BUCKETS_H
#define BUCKETS_H

#include <iostream>
#include <iomanip>
#include <utility>
#include <iterator>
#include <typeinfo>
#include "../include/print.hpp"
using namespace std;


template <typename T, typename V>
ostream& operator << (ostream& os, const pair<T, V>& p)
{
    return os << "[" << p.first << "," << p.second << "]";
}

template<typename T>
void PrintHashTableState(const T& cont)
{
    cout << "size:                         " << cont.size() << endl;
    cout << "buckets:                   " << cont.bucket_count() << endl;
    cout << "load factor:               " << cont.load_factor() << endl;
    cout << "max load factor        " << cont.max_load_factor() << endl;


    if (typeid(typename iterator_traits<typename T::iterator>::iterator_category)
        == typeid(bidirectional_iterator_tag))
    {
        cout << "chaining style: doubly-linked" << endl;
    }
    else {
        cout << "chaining style: singly-linked" << endl;
    }

    cout << "data:   " << endl;
    for (auto idx = 0; idx != cont.bucket_count(); ++idx)
    {
        cout << "b[" << setw(2) << idx << "]:   ";
       for (auto pos = cont.begin(idx); pos != cont.end(idx); ++pos)
      {
           cout << *pos << " ";
      }
        cout << endl;
    }
    cout << endl;
}

#endif
