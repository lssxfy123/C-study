// Copyright 2017.���|�|
// author�����|�|
// allocator�����ڴ�
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

    // A* ptr = new A[3];  // error, A������Ĭ�Ϲ��캯��
    allocator<A> alloc;
    A* ptr = alloc.allocate(3);  // Ϊ3��A�������ڴ�
    
    // ���춯̬����ptr�еĶ���
    cout << "start construct" << endl;
    alloc.construct(&ptr[0], 1);
    alloc.construct(&ptr[1], 2);
    alloc.construct(&ptr[2], 3);
    ptr[0].Print();
    ptr[1].Print();
    ptr[2].Print();

    // ɾ��֮ǰ����Ķ���
    cout << "start destructor" << endl;
    alloc.destroy(&ptr[0]);
    alloc.destroy(&ptr[1]);
    alloc.destroy(&ptr[2]);

    // �ͷ��ڴ�
    cout << "delete memory" << endl;
    alloc.deallocate(ptr, 3);
    return 0;
}
