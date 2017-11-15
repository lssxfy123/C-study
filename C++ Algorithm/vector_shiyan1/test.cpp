/************************************************************************/
/*    �ļ���        ��test.cpp
/*    ����          �����|�|
/*    ����          ��2011/11/14
/*    ��������      ������vector�Ĳ���                                                                     */
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> ivec; // ����һ��������

	for(vector<int> :: size_type i = 0; i != 10; ++i)
	{
		ivec.push_back(i); // ������β���в���10��Ԫ�أ�ע�⣺ʹ���±겻�����Ԫ��
	}

	vector<int> :: iterator iter; // ����һ������������

	for (iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		cout << *iter << ",";
	}

	cout << endl;

	ivec.push_back(10);
	cout << *iter << endl;

	string str5("0123.12");
	const char* str6 = str5.c_str();
	float fval = 0.0;
	fval = atof(str6);  // ���������ַ���ת���ɸ�����

	cout << fval << endl;
	
	double dval = 12.12345;
	vector<float> vfval;
	vfval.push_back(dval);  // double�����ݿ��Բ���float�������У������п��ܷ����ض�
	
	cout << vfval[0] << endl;
	
	// vector<double> vdval(vfval); // error: Ԫ�����Ͳ�ͬ
	vector<double> vdval;
	vdval.push_back(fval);  // float������Ҳ���Բ���double��������
	
	cout << vdval[0] << endl;

	vector<char*> vcval;
	char *str = "abcd";
	vcval.push_back(str);

	cout << vcval[0] << endl;

	cout << "7 % 4" << " = " << 7 % 4 << endl;

	return 0;
}