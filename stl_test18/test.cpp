// Copyright 2017.刘珅珅
// author：刘珅珅
// smart指针：unique_ptr
#include <functional>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class A
{
public:
    A()
    {
        cout << "construct A" << endl;
    }

    A(const A& src)
    {
        cout << "copy construct A" << endl;
    }

    ~A()
    {
        cout << "destruct A" << endl;
    }
};

class Test
{
public:
    // 如果在初始化ptr2时，new失败
    // 那么ptr1也会释放已分配的内存
    Test() : ptr1(new A), ptr2(new A)
    {
    }

    // 拷贝构造函数是必要的
    // unique_ptr不能被默认拷贝
    // Test也不能进行拷贝构造
    Test(const Test& src) : ptr1(new A(*src.ptr1)), ptr2(new A(*src.ptr2))
    {
    }

    // 赋值运算符重载是必要的
    // unique_ptr不能被默认赋值
    const Test& operator= (const Test& src)
    {
        *ptr1 = *src.ptr1;
        *ptr2 = *src.ptr2;
        return *this;
    }

    // 这里可以忽略析构函数
    // unique_ptr会自动释放开辟的资源

private:
    unique_ptr<A> ptr1;
    unique_ptr<A> ptr2;
};

class ADeleter
{
public:
    void operator() (A* ptr)
    {
        cout << "call delete for class A object" << endl;
        delete ptr;
    }
};

int main(int argc, char* argv[])
{
    Test t1;
    Test t2(t1);

    // 运行时会崩溃
    // unique_ptr调用delete，但其拥有的对象是数组
    // 在C++里必须调用delete[]
    // unique_ptr<string> up(new string[10]);  // runtime error
    
    // 在这个偏特化版本中，unique_ptr不能使用*和->
    // 可以使用[]
    unique_ptr<string[]> up(new string[5]);  // ok

    // 自定义删除
    // template第2个实参必须是函数的引用，函数指针或函数对象
    unique_ptr<int, function<void(int*)>> up1(new int[10], [](int* p) {
        delete[] p;
    });

    unique_ptr<int, void(*)(int*)> up2(new int[10], [](int* p) {
        delete[] p;
    });

    unique_ptr<A, ADeleter> up3(new A);
    return 0;
}
