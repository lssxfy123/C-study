/************************************************************************/
/*    �ļ���     ��test.cpp
/*    ����       �����|�|
/*    ����       ��2011/11/7
/*    ��������   ������ģ�庯��                                                                     */
/************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;

template <typename T> T max(const T &a, const T &b) 
{
	cout << "ƥ�亯��ģ��" << endl;
	return a > b?a:b;
}

char* max(char *a, char *b)
{
	cout << "ƥ�����غ���" << endl;
	return (strcmp(a, b)?a:b);
}

int main(int argc, char *argv[])
{
	cout << max("Hello", "Gold") << endl;
	cout << max(3, 4) <<endl;

	return 0;
}