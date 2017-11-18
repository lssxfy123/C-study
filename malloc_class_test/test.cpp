// Copyright 2017.刘珅珅
// author：刘珅珅
// malloc分配类指针
#include <iostream>
#include "../include/print.hpp"
using namespace std;

class A {
    A()
    {
        cout << "construct A" << endl;
    }

    ~A()
    {
        cout << "destruct A" << endl;
    }
};

int main(int argc, char* argv[])
{
    // malloc不调用构造函数
    // free不调用析构函数
    cout << "malloc A" << endl;
    A* a_ptr = (A*)malloc(sizeof(A));

    cout << "free A" << endl;
    free(a_ptr);
    return 0;
}
