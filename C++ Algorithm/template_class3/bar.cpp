/************************************************************************/
/*    文件名          ：bar.cpp
/*    作者            ：刘珅珅
/*    日期            ：2011/11/8
/*    功能描述        ：类模板中的友元                                                                     */
/************************************************************************/

#include "bar.h"
#include <iostream>
using namespace std;

template <class T> Bar <T> :: Bar ()
{
	cout << "类模板的构造函数" << endl;
}

template <class T> void Bar <T> :: fcn()
{
	cout << "模板类的私有函数" << endl;
}