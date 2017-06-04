// Copyright 2017.刘珅珅
// author：刘珅珅
// pair和tuple
#include <iostream>
#include <tuple>
using namespace std;

class Foo {
public:
    Foo(tuple<int, float>)
    {
        cout << "Foo::Foo(tuple)" << endl;
    }

    // 变长参数模板
    template<typename... Args>
    Foo(Args... args)
    {
        cout << "Foo::Foo(args...)" << endl;

        // 输出变长参数
        write(args...);
    }

private:
    // 这里利用模板的推导功能，每次取出第一个参数t
    // 将其他的参数继续作为变长参数args
    // 类似一个递归
    template<typename T, typename ...Args>
    void write(const T& t, Args... args)
    {
        cout << t << ",";
        write(args...);
    }

    // 递归的出口
    // 变长参数的最后一个参数
    template<typename T>
    void write(const T& t)
    {
        cout << t << endl;
    }
};

int main(int argc, char* argv[])
{
    // pair
    std::pair<int, float> p(42, 3.14f);
    cout << "first: " << p.first << " second: " << p.second << endl;
    cout << "first: " << get<0>(p) << " second: " << get<1>(p) << endl;

    tuple<int, float> t(1, 2.2f);
    tuple<int, string> t1(4, "a");
    pair<int, Foo> p1(42, t);

    // piecewise_construct作为第一实参，分段构造
    // 传入两个tuple，45强制转换为tuple，为p2的first元素
    // p2的second元素是一个Foo对象，这里会调用    template<typename... Args>
    // Foo(Args... args)构造函数，接受tuple元素而不是tuple整体
    pair<int, Foo> p2(piecewise_construct, make_tuple(45), t);

    make_pair(42, "a");
    return 0;
}
