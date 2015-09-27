// Copyright 2015.刘珅珅
// author：刘珅珅
// 自定义vector容器

#include <iostream>
#include <vector>
using namespace std;

#include "Vector.hpp"

//int a[5];
//
//int func(int index)
//{
//    if ((index < 0) || (index >= 5))
//    {
//        throw range_error("index is not between 0 and 4");
//    }
//    return a[index];
//}

int main(int argc, char* argv[])
{
    //for (int i = 0; i != 5; ++i)
    //{
    //    a[i] = i;
    //}

    //try
    //{
    //    cout << func(5) << endl;
    //}
    //catch (runtime_error& e)
    //{
    //    cout << e.what() << endl;
    //}

    Vector<int> array;
    array.push_back(0);
    array.push_back(1);
    array.push_back(2);

    Vector<int>::const_iterator it = array.end();

    int a[3] = {1};
    for (int i = 0; i != 3; ++i)
    {
        cout << a[i] << endl;
    }

    // 可以看出尽管a[3]不存在
    // 但其地址存在，这也是end()能够执行成功的原因
    // 编译器将a[2]的地址加上sizeof(int)得到&a[3]
    cout << &a[2] << endl;  // 0071FB28
    cout << &a[3] << endl;  // 0071FB2C

    //for (Vector<int>::const_iterator it = array.begin(); it != array.end(); ++it)
    //{
    //    cout << *it << endl;
    //}

    return 0;
}
