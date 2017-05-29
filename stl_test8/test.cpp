// Copyright 2017.���|�|
// author�����|�|
// C++11������ֵ����
#include <iostream>
using namespace std;

class P
{
public:
    P() : length_(10), ptr_(new int[length_])
    {
        cout << "default constructor" << endl;
        for (int i = 0; i < length_; ++i)
        {
            ptr_[i] = i;
        }
    }

    P(const P& p) : length_(p.length_)
    {
        cout << "copy constructor" << endl;
        ptr_ = new int[length_];
        for (int i = 0; i < length_; ++i)
        {
            ptr_[i] = p.ptr_[i];
        }
    }

    P(P&& p) : length_(p.length_), ptr_(p.ptr_)
    {
        cout << "P&& constructor" << endl;
        p.ptr_ = nullptr;
    }

    ~P()
    {
        cout << "~P()" << endl;
        if (ptr_)
        {
            delete[] ptr_;
        }
        
        ptr_ = nullptr;
    }

private:
    int length_;
    int* ptr_;
};

P& Func1()
{
    P p;
    P& rp = p;
    return rp;
}

P&& Func2()
{
    P p;
    return move(p);
}

int main(int argc, char* argv[])
{
    // error,Func1()��������
    // ��p��һ���ֲ�������������ֵ����rp�����õĶ���
    // ��������������p1�Ŀ������캯���������
    // һ���������Ķ���
    //P p1(Func1());

    // error��Func2()���ֲ�����p����ֵ�����ֵ����
    // ��ֵ����Ҳ�����ã������������ֵ���ó���ͬ��������
    //P p2(Func2());
    return 0;
}
