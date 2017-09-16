// Copyright 2017.刘珅珅
// author：刘珅珅
// 堆栈
#include <iostream>
#include <stack>
#include "../include/print.hpp"
using namespace std;

class A {
public:
    A(string name) : name_(name)
    {
        cout << "A constructor" << endl;
    }

    A(const A& rhs) : name_(rhs.name_)
    {
        cout << "A copy constructor" << endl;
    }

    A(A&& rhs) : name_(rhs.name_)
    {
        cout << "A move constructor" << endl;
    }

    ~A()
    {
        cout << "A destructor" << endl;
    }

    void Print()
    {
        cout << "this is " << name_ << endl;
    }

private:
    string name_;
};

int main(int argc, char* argv[])
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    // top()：不弹出元素
    cout << st.top() << ' ';
    st.pop();
    cout << st.top() << ' ';
    st.pop();

    // modify top element
    st.top() = 77;

    st.push(4);
    st.push(5);
    st.pop();

    while (!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << endl;
    cout << endl;
    stack<A> st1;
    A a1("a1");
    st1.push(a1);
    a1.Print();

    A a2("a2");
    st1.push(move(a2));
    // 使用move移动后
    // 源对象的生命周期
    // 并未结束，但在实际
    // 使用过程中，可以在
    // move构造函数中让其
    // 处于可析构状态（释放
    // 其分配的内存，文件句柄等）
    // 程序员也不应再使用此源对象
    a2.Print();
    return 0;
}
