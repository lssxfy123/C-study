// Copyright 2017.刘珅珅
// author：刘珅珅
// 友元
#include <iostream>

class A;  // 前向声明，类名声明

class C
{
  public:
    void SetNumber(A& a);  // 此处只能有函数声明，不能有函数的实现

    void output(A& a);
};

class A
{
    friend class B;  // 类B的所有成员函数均可访问类A的private成员
    friend void C::output(A& a);  // 类C的成员函数output()可以访问类A的private成员，其余成员函数均不可访问类A的private成员

  private:
    int number;
};

class B
{
  public:
    void SetNumber(A& a)
    {
        a.number = 5;
    }

    void output(A& a)
    {
        std::cout << a.number << std::endl;
    }
};

void C::output(A& a)
{
    std::cout << a.number << std::endl;
}

void C::SetNumber(A& a)
{
    // a.number = 5;  // error，无法访问A的private成员
}

int main(int argc, char* argv[])
{
    return 0;
}

