// Copyright 2017.���|�|
// author�����|�|
// �����������������������������
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> coll;
    for (int i = 1; i <= 9; ++i)
    {
        coll.push_back(i);
    }

    // ���������
    copy(coll.crbegin(), coll.crend(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
