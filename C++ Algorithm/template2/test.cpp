/************************************************************************/
/*    文件名     ：test.cpp
/*    作者       ：刘珅珅
/*    日期       ：2011/11/7
/*    功能描述   ：重载模板函数                                                                     */
/************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;

template <typename T> T max(const T &a, const T &b) 
{
	cout << "匹配函数模板" << endl;
	return a > b?a:b;
}

char* max(char *a, char *b)
{
	cout << "匹配重载函数" << endl;
	return (strcmp(a, b)?a:b);
}

int main(int argc, char *argv[])
{
	cout << max("Hello", "Gold") << endl;
	cout << max(3, 4) <<endl;

	return 0;
}