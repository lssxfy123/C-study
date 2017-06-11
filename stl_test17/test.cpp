// Copyright 2017.刘珅珅
// author：刘珅珅
// smart指针：unique_ptr
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

    // 不加move也没关系，编译器会自动加上
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
    // unique_ptr同一时刻只允许存在一个拥有者
    // unique_ptr<string> up1(up);  // error
    // unique_ptr<string> up2 = up;  // error

    // 可以通过move语义将拥有权转移
    unique_ptr<string> up3(move(up));  // ok

    unique_ptr<string> up4(new string("welcome"));
    // 需要使用move语义
    Sink(move(up4));
    Func();
    return 0;
}
