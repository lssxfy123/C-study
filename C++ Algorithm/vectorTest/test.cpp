/************************************************************************/
/*    �ļ���   ��test.cpp
/*    ����     �����|�|     
/*    ����     ��2012/4/19
/*    �������� ��vector��������                                                               
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