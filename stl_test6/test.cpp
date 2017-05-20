// Copyright 2017.刘珅珅
// author：刘珅珅
// move移动语义
#include <iostream>
#include <vector>
using namespace std;

class P
{
public:
    P()
    {
        cout << "构造函数" << endl;
    }

    P(const P& p)
    {
        cout << "拷贝构造函数" << endl;
    }

    ~P()
    {
        cout << "析构函数" << endl;
    }
};

int main(int argc, char* argv[])
{
    vector<P> vec_p;
    P p1;

    // vector容器在插入p1时
    // 会首先调用拷贝构造函数
    // 构造一个临时对象插入容器中
    vec_p.push_back(p1);
    return 0;
}
