// Copyright 2017.刘珅珅
// author：刘珅珅
// allocator分配内存
#include <iostream>
#include "../include/print.hpp"
using namespace std;

class A
{
public:
    A(int k) : number_(k)
    {
        cout << "Constructor A" << endl;
    }

    ~A()
    {
        cout << "Destructor A" << endl;
    }

    void Print()
    {
        cout << "number is " << number_ << endl;
    }
private:
    int number_;
};

int main(int argc, char* argv[])
{
    int* p = new int[7];
    delete[] p;
    p = nullptr;

    // A* ptr = new A[3];  // error, A不存在默认构造函数
    allocator<A> alloc;
    A* ptr = alloc.allocate(3);  // 为3个A分配了内存
    
    // 构造动态数组ptr中的对象
    cout << "start construct" << endl;
    alloc.construct(&ptr[0], 1);
    alloc.construct(&ptr[1], 2);
    alloc.construct(&ptr[2], 3);
    ptr[0].Print();
    ptr[1].Print();
    ptr[2].Print();

    // 删除之前分配的对象
    cout << "start destructor" << endl;
    alloc.destroy(&ptr[0]);
    alloc.destroy(&ptr[1]);
    alloc.destroy(&ptr[2]);

    // 释放内存
    cout << "delete memory" << endl;
    alloc.deallocate(ptr, 3);
    return 0;
}
