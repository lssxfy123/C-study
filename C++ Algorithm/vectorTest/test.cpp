/************************************************************************/
/*    文件名   ：test.cpp
/*    作者     ：刘珅珅     
/*    日期     ：2012/4/19
/*    功能描述 ：vector容器测试                                                               
/************************************************************************/

#include <vector>
#include <iostream>
using namespace std;

int main( int argc, char *argv[] )
{
	vector<int> vInt;
	vInt.reserve( 10 );
	vInt.push_back( 1 );
	vInt.push_back( 2 );
	vInt.push_back( 3 );

	cout << vInt.size() << endl;
	cout << vInt.capacity() << endl;
	return 0;
}