/************************************************************************/
/*    文件名          ：bar.h
/*    作者            ：刘珅珅
/*    日期            ：2011/11/8
/*    功能描述        ：类模板中的友元，非模板类或普通函数为友元                                                                     */
/************************************************************************/

#ifndef BAR_H
#define BAR_H


#include <iostream>
using namespace std;

class FoolBar;  // 类声明
void func();  // 函数声明

template <class T> class Bar
{
	public:

	friend class FoolBar;  // 普通非模板类
	friend void func();  //普通函数

	Bar();

	private:
		int num;
		void fcn();
};



#endif