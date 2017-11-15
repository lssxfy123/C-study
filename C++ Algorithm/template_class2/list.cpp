
#include "list.h"
#include <iostream>
using namespace std;

template <class T> List <T> :: List(int n)
{
	num = n;
}

template <class T> List <T> :: List(const List <T> &copy)
{
	num = copy.num;
}

template <class T> ostream& operator << (ostream& out, const List<T> &obj)
{
	out << obj.num ;
	return out;
}