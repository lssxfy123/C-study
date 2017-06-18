// Copyright 2017.���|�|
// author�����|�|
// �����⸲����wrapper
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

void Func(int x, int y)
{
    cout << "function x: " << x << " y: " << y << endl;
}

class A {
private:
    // C++11����Ǿ�̬��Ա�������������г�ʼ��
    int i = 0;

public:
    void MemberFunc(int x, int y) const
    {
        cout << "member function x: " << x << " y: " << y << endl;
    }
};

int main(int argc, char* argv[])
{
    vector<function<void(int, int)>> tasks;
    tasks.push_back(Func);
    tasks.push_back([](int x, int y) {
        cout << "lambda x: " << x << " y: " << y << endl;
    });

    for (function<void(int, int)> f : tasks)
    {
        f(33, 66);
    }

    // ���Ա�������⸲��
    function<void(int, int)> member_func_wrapper;
    A a;
    member_func_wrapper = bind(&A::MemberFunc, a, std::placeholders::_1, std::placeholders::_2);
    member_func_wrapper(33, 66);
    return 0;
}
