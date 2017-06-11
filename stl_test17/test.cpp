// Copyright 2017.���|�|
// author�����|�|
// smartָ�룺unique_ptr
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

void Sink(unique_ptr<string> up)
{
}

class Test
{
public:
    Test() {}
    ~Test() { cout << "delete Test" << endl; }
};

unique_ptr<Test> Source()
{
    unique_ptr<Test> ptr(new Test);

    // ����moveҲû��ϵ�����������Զ�����
    return move(ptr);
}

void Func()
{
    unique_ptr<Test> ptr;
    for (int i = 0; i < 5; ++i)
    {
        ptr = Source();
    }
    cout << "Unique Ptr test end" << endl;
}

int main(int argc, char* argv[])
{
    unique_ptr<string> up(new string("hello"));
    // unique_ptrͬһʱ��ֻ�������һ��ӵ����
    // unique_ptr<string> up1(up);  // error
    // unique_ptr<string> up2 = up;  // error

    // ����ͨ��move���彫ӵ��Ȩת��
    unique_ptr<string> up3(move(up));  // ok

    unique_ptr<string> up4(new string("welcome"));
    // ��Ҫʹ��move����
    Sink(move(up4));
    Func();
    return 0;
}
