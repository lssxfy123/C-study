#include "bar.h"
#include <iostream>
using namespace std;

template <class T> Bar <T> :: Bar ()
{
	cout << "��ģ��Ĺ��캯��" << endl;
}

template <class T> void Bar <T> :: fcn()
{
	cout << "ģ�����˽�к���" << endl;
}