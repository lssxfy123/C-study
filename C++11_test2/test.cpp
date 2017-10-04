// Copyright 2017.刘珅珅
// author：刘珅珅
// auto和decltype的区别
#include <iostream>
#include <vector>
using namespace std;

// error，auto不能为函数形参
//void func(auto a = 1) {}

// 不能修饰非静态常量成员
struct MyStruct 
{
    //auto var = 1;  // error
    //const auto var3 = 3;  // error
    //static auto var4 = 4;  // error
    const static auto var2 = 2;  // ok
};

class A
{
public:
    static int Get()
    {
        return 0;
    }
};

class B
{
public:
    static string Get()
    {
        return "abc";
    }
};

template<class T>
void Func()
{
    // 此处无法获取到Get的返回类型，使用auto
    auto val = T::Get();
}

// 返回类型后置
// auto作为返回值
// 通过decltype(t + u)推导返回值的类型
template<typename T, typename U>
auto Add(T t, U u) -> decltype(t + u)
{
    return t + u;
}

int main(int argc, char* argv[])
{
    // auto
    auto x = 5;  // x是int型
    auto p = new auto(1);  // p是int*类型
    const auto v = &x;  // v是int * const，常量指针
    const auto *v1 = &x;  // v1是const int*，指向常量的指针
    v1 = nullptr;

    int m = 9;
    int& c = m;
    auto d = c;  // d为int，抛弃了引用
    auto& h = c;  // h为int&

    const int n = 8;
    auto e = n;  // e为int，抛弃了const
    const auto f = n;  // f为const int

    const int& k = 6;
    auto& j = k;  // j为const int&
    auto* l = &k;  // l为const int*

    //auto r[10] = { 0 };  // error， 不能定义数组
    //vector<auto> vec = { 0 };  // error， 不能推导模板参数
    Func<A>();
    Func<B>();

    // decltype
    // 不需要初始化
    int x1;
    decltype(x1) y1;  // y1为int类型

    int t = 1;
    float u = 2.0f;
    auto sum = Add(t, u);
    return 0;
}
