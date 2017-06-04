// Copyright 2017.刘珅珅
// author：刘珅珅
// Callable Object：可被调用的对象
#include <functional>
#include <iostream>
#include <memory>
using namespace std;

// 可被调用的对象
// 1 函数
void Func(int x, int y)
{
    cout << "callable function : " << "x: " << x << ": y : " << y << endl;
}

// 可被调用的对象
// 2 lambda
auto lambda = [](int x, int y)
{
    cout << "callable lambda : " << "x: " << x << ": y : " << y << endl;
};

// 可被调用的对象
// 3 函数对象
// 4 指向成员函数的指针
class Test {
public:
    void operator () (int x, int y) const
    {
        cout << "callable funtion object : " << "x: " << x << ": y : " << y << endl;
    }

    void MemberFunc(int x, int y)
    {
        cout << "callable member function : " << "x: " << x << ": y : " << y << endl;
    }
};

int main(int argc, char* argv[])
{
    Test t;
    shared_ptr<Test> shared_pointer(new Test);

    //std::bind() 绑定可调用对象传递参数
    auto b1 = bind(Func, 77, 33);
    b1();  // calls: Func(77, 33)

    bind(lambda, 77, 33)();  // calls: lambda(77, 33)

    bind(Test(), 77, 33)();  // calls: Test::operator() (77, 33)

    // calls: t.MemberFunc(77, 33)
    bind(&Test::MemberFunc, t, 77, 33)();

    // calls: shared_pointer->MemberFunc(77, 33)
    bind(&Test::MemberFunc, shared_pointer, 77, 33)();
    return 0;
}
 