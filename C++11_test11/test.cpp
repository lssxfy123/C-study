// Copyright 2017.���|�|
// author�����|�|
// std::move
#include <iostream>
#include "../include/print.hpp"
using namespace std;

class Moveable
{
public:
    Moveable() : ptr_(new int(3))
    {
        cout << "Construct Moveable" << endl;
    }

    // �������캯��
    Moveable(const Moveable& org) : ptr_(new int(*org.ptr_))
    {
        cout << "Copy construct Moveable" << endl;
    }

    // �ƶ����캯��
    Moveable(Moveable&& org) : ptr_(org.ptr_)
    {
        cout << "Move construct Moveable" << endl;
        org.ptr_ = nullptr;
    }

    ~Moveable()
    {
        if (ptr_ != nullptr)
        {
            cout << "delete ptr_" << endl;
            delete ptr_;
            ptr_ = nullptr;
        }
    }

    // �ƶ���ֵ�����
    Moveable& operator=(Moveable&& org)
    {
        if (this != &org)
        {
            cout << "Move operator=" << endl;
            delete ptr_;
            ptr_ = org.ptr_;
            org.ptr_ = nullptr;
        }
        return *this;
    }

public:
    int* ptr_;
};

int main(int argc, char* argv[])
{
    int c = 0;
    // int&& rr1 = c;  // error����ֵ���ò��ܰ���ֵ
    int&& rr1 = std::move(c);  // ok��move()����ֵcǿ��ת��Ϊ��ֵ

    {
        Moveable m;
        Moveable m1(m);
    }

    cout << endl;

    {
        Moveable m;
        Moveable m2(std::move(m));

        // error���׳��쳣
        // ����m�е�ָ��ptr_���ڴ��ѱ��ƶ�����m2
        // cout << *m.ptr_ << endl;
    }

    cout << endl;
    {
        Moveable m;
        Moveable m3;
        m3 = std::move(m);
    }
    return 0;
}
