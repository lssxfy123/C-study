// Copyright 2017.���|�|
// author�����|�|
// STL������C++��������������
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include "../include/print.hpp"
using namespace std;

class Test
{
public:
    Test()
    {
        cout << "Construct Test" << endl;
    }
};

int main(int argc, char* argv[])
{
    // ������һ������������Ϊt������ֵΪTest
    Test t();

    ifstream data_file("test.txt");

    // data��һ������������ֵΪlist<int>
    // ��һ������Ϊdata_file������Ϊistream_iterator<int>
    // �ڶ�������û�����ƣ�����һ������ָ�룬ָ��һ��
    // ����istream_iterator<int>�ĺ���
    // list<int> data(istream_iterator<int>(data_file), istream_iterator<int>());
    istream_iterator<int> data_begin(data_file);
    istream_iterator<int> data_end;
    list<int> data(data_begin, data_end);
    for (auto v : data)
    {
        cout << v << endl;
    }
    return 0;
}
