// Copyright 2017.���|�|
// author�����|�|
// vector��size()��capactiy()����
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