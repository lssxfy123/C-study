// Copyright 2017.刘珅珅
// author：刘珅珅
// 类中的静态变量
#include <iostream>
using namespace std;

class P
{
  public:
    static void init()
    {
        // 静态成员函数只能调用静态成员函数和静态成员变量，原因是静态成员函数在类对象之前就已经存在代码区，
        // 这个时间非静态成员还没有分配内存空间，非静态成员在类对象构造时才能分配内存空间。
        // m = 4;  // error，无法访问非静态成员变量
        cout << "静态成员函数" << endl;
    }

    void output()
    {
        init();  // 非静态成员函数可以调用静态成员函数和成员变量

        x = 1;
        y = 1;
        cout << x << endl;
        cout << y << endl;

        cout <<" 非静态成员函数" << endl;
    }

    static double z;

  private:
    static int x;
    static int y;
    int m;
};

// 如果要访问静态成员变量时，静态成员变量必须进行初始化，
// 并且在类定义之外进行，如果不访问静态成员变量，静态成员变量不需要进行初始化
int P::x = 0;
int P::y = 0;
double P::z = 0.0;

int main(int argc, char* argv[])
{
    P p1;
    p1.init();//可以这样访问静态成员函数
    p1.output();
    P::init();//也可以这样访问静态成员函数

    P::z = 1.0;//z为公共静态成员变量，可以这样访问

    return 0;
}

