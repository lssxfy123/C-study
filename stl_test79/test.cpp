// Copyright 2017.���|�|
// author�����|�|
// ��ջ
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

    // top()��������Ԫ��
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
    // ʹ��move�ƶ���
    // Դ�������������
    // ��δ����������ʵ��
    // ʹ�ù����У�������
    // move���캯��������
    // ���ڿ�����״̬���ͷ�
    // �������ڴ棬�ļ�����ȣ�
    // ����ԱҲ��Ӧ��ʹ�ô�Դ����
    a2.Print();
    return 0;
}
