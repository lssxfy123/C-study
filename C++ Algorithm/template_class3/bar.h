/************************************************************************/
/*    �ļ���          ��bar.h
/*    ����            �����|�|
/*    ����            ��2011/11/8
/*    ��������        ����ģ���е���Ԫ����ģ�������ͨ����Ϊ��Ԫ                                                                     */
/************************************************************************/

#ifndef BAR_H
#define BAR_H


#include <iostream>
using namespace std;

class FoolBar;  // ������
void func();  // ��������

template <class T> class Bar
{
	public:

	friend class FoolBar;  // ��ͨ��ģ����
	friend void func();  //��ͨ����

	Bar();

	private:
		int num;
		void fcn();
};



#endif