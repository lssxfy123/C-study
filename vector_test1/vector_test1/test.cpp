// Copyright 2015.刘珅珅
// author：刘珅珅
// 自定义vector容器

#include <iostream>
#include <vector>
using namespace std;

#include "Vector.hpp"

class A {
public:
    A()
    {
        cout << "construct A" << endl;
    }
};

int main(int argc, char* argv[])
{
    //Vector<int> vector1;
    //vector1.push_back(1);
    //vector1.push_back(2);
    //vector1.push_back(3);
    //try
    //{
    //    cout << vector1[3] << endl;
    //}
    //catch (runtime_error& e)
    //{
    //    cout << e.what() << endl;
    //}

    Vector<int> array;
    array.push_back(0);
    array.push_back(1);
    array.push_back(2);

    for (Vector<int>::const_iterator itr = array.begin(); itr != array.end(); ++itr)
    {
        cout << *itr << ",";
    }

    cout << endl;

    Vector<int>::iterator itr = array.end();
    itr = array.insert(itr, 3);

    for (Vector<int>::const_iterator itr = array.begin(); itr != array.end(); ++itr)
    {
        cout << *itr << ",";
    }

    cout << endl;

    itr = array.begin();
    array.erase(itr);

    for (Vector<int>::const_iterator itr = array.begin(); itr != array.end(); ++itr)
    {
        cout << *itr << ",";
    }
    cout << endl;

    Vector<int> array1(array);

    for (Vector<int>::const_iterator itr = array.begin(); itr != array.end(); ++itr)
    {
        cout << *itr << ",";
    }
    cout << endl;

    //int a[3] = {1};
    //for (int i = 0; i != 3; ++i)
    //{
    //    cout << a[i] << endl;
    //}

    //// 可以看出尽管a[3]不存在
    //// 但其地址存在，这也是end()能够执行成功的原因
    //// 编译器将a[2]的地址加上sizeof(int)得到&a[3]
    //cout << &a[2] << endl;  // 0071FB28
    //cout << &a[3] << endl;  // 0071FB2C

    Vector<A> vec_a(10);
    A a;
    vec_a.push_back(a);
    vec_a.push_back(a);
    vec_a.push_back(a);
    return 0;
}
