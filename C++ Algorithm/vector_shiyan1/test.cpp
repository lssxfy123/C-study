/************************************************************************/
/*    文件名        ：test.cpp
/*    作者          ：刘珅珅
/*    日期          ：2011/11/14
/*    功能描述      ：容器vector的测试                                                                     */
/************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> ivec; // 定义一个空容器

	for(vector<int> :: size_type i = 0; i != 10; ++i)
	{
		ivec.push_back(i); // 向容器尾部中插入10个元素，注意：使用下标不会添加元素
	}

	vector<int> :: iterator iter; // 定义一个容器迭代器

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
	fval = atof(str6);  // 将浮点型字符串转化成浮点数

	cout << fval << endl;
	
	double dval = 12.12345;
	vector<float> vfval;
	vfval.push_back(dval);  // double型数据可以插入float型链表中，数据有可能发生截断
	
	cout << vfval[0] << endl;
	
	// vector<double> vdval(vfval); // error: 元素类型不同
	vector<double> vdval;
	vdval.push_back(fval);  // float型数据也可以插入double型链表中
	
	cout << vdval[0] << endl;

	vector<char*> vcval;
	char *str = "abcd";
	vcval.push_back(str);

	cout << vcval[0] << endl;

	cout << "7 % 4" << " = " << 7 % 4 << endl;

	return 0;
}