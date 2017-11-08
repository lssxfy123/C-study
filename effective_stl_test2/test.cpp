// Copyright 2017.刘珅珅
// author：刘珅珅
// STL容器与C++编译器分析机制
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
    // 声明了一个函数，名称为t，返回值为Test
    Test t();

    ifstream data_file("test.txt");

    // data是一个函数，返回值为list<int>
    // 第一个参数为data_file，类型为istream_iterator<int>
    // 第二个参数没有名称，它是一个函数指针，指向一个
    // 返回istream_iterator<int>的函数
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
