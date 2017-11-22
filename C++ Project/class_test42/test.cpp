// Copyright 2017.刘珅珅
// author：刘珅珅
// 类的长度计算
#include <iostream>
using std::cout;
using std::endl;

class A
{

};

class B
{
  public:
    void func()
    {

    }

    static void f()
    {

    }

  private:
    static int a;
    // int b;
};

int B::a = 0;

class C
{
  private:
    char c;
    int a;
    double f;
};

class D
{
  public:
    virtual void func()
    {
    }

    virtual void h()
    {

    }

  private:
    char i;
    int a;
    double f;
};

class E
{
  public:
    virtual void f()
    {

    }

  private:
    char i;
};

class Base
{
  public:
    virtual void f()
    {

    }

    virtual void h()
    {

    }
};

class Base1
{
public:
    virtual void f()
    {

    }

    virtual void h()
    {

    }
};

class Base2
{
  public:
    virtual void f()
    {

    }

    virtual void h()
    {

    }
};

class F : public Base
{
  public:
    virtual void f()
    {

    }

    virtual void g()
    {

    }
};

class F1 : public Base, public Base1, public Base2
{

};

class Base3
{
  //public:
    //virtual void f()
    //{

    //}

  private:
    char i;
    double d;
};

class G : public Base3
{
  public:
    virtual void f()
    {
        cout << "G::f()" << endl;
    }

  private:
    char i;
    // int n;
};

class Base4
{
  private:
    int n;
    double f;
};

class Base5 : public Base4
{
  private:
    char i;
};

class H : public Base5
{
  private:
    char i;
};

class Base6
{
  public:
    virtual void f()
    {

    }

  private:
    int i;
    int j;
};

class I : virtual public Base6
{
  private:
    char str[10];
    double d;
};

class J : virtual public Base6
{

};

class K : public I, public J
{

};

typedef void (*Fun)(void);

int main(int argc, char* argv[])
{
    cout << "空类A的大小为： " << sizeof(A) << endl;  // 大小为1

    // 类的非虚成员函数和静态变量均不会增加类的大小
    cout << "类B的大小为： " << sizeof(B) << endl;  // 大小为1

    // 一般情况下类的长度和结构体的大小计算类似
    // 参考C语言学习17-sizeof的用法与结构体的长度计算.docx
    cout << "类C的大小为： " << sizeof(C) << endl;  // 大小为16

    cout << "类D的大小为： " << sizeof(D) << endl;  // 大小为24
    cout << "类E的大小为： " << sizeof(E) << endl;  // 大小为8

    cout << "类F的大小为： " << sizeof(F) << endl;  // 大小为4
    cout << "类F1的大小为： " << sizeof(F1) << endl;  // 大小为12

    cout << "类Base3的大小为： " << sizeof(Base3) << endl;  // 大小为16
    cout << "类G的大小为： " << sizeof(G) << endl;  // 大小为32

    Fun Fun_ptr = NULL;
    G g;
    Fun_ptr = (Fun)*((int*)*(int*)(&g));
    Fun_ptr();  // 执行G::f()函数

    cout << "类Base4的大小为： " << sizeof(Base4) << endl;  // 大小为16
    cout << "类Base5的大小为： " << sizeof(Base5) << endl;  // 大小为24
    cout << "类H的大小为： " << sizeof(H) << endl;  // 大小为32

    I i;

    K k;
    cout << "类Base6的大小为： " << sizeof(Base6) << endl;  // 大小为12
    cout << "类I的大小为： " << sizeof(I) << endl;  // 大小为44
    cout << "类J的大小为： " << sizeof(J) << endl;  // 大小为16
    cout << "类K的大小为： " << sizeof(K) << endl;  // 大小为52

    return 0;
}
