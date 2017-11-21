
#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template <class T> class List;

template <class T> ostream& operator << (ostream& out, const List <T> &obj);

template <class T> class List
{
public:
	List(int n = 0);
	List(const List <T> &copy);

	friend ostream& operator << <T> (ostream &out, const List <T> &obj);

private:
	int num;
};

//#include "list.cpp"

#endif