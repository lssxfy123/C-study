// Copyright 2017.���|�|
// author�����|�|
// ��ĳ��ȼ���
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
    cout << "����A�Ĵ�СΪ�� " << sizeof(A) << endl;  // ��СΪ1

    // ��ķ����Ա�����;�̬����������������Ĵ�С
    cout << "��B�Ĵ�СΪ�� " << sizeof(B) << endl;  // ��СΪ1

    // һ���������ĳ��Ⱥͽṹ��Ĵ�С��������
    // �ο�C����ѧϰ17-sizeof���÷���ṹ��ĳ��ȼ���.docx
    cout << "��C�Ĵ�СΪ�� " << sizeof(C) << endl;  // ��СΪ16

    cout << "��D�Ĵ�СΪ�� " << sizeof(D) << endl;  // ��СΪ24
    cout << "��E�Ĵ�СΪ�� " << sizeof(E) << endl;  // ��СΪ8

    cout << "��F�Ĵ�СΪ�� " << sizeof(F) << endl;  // ��СΪ4
    cout << "��F1�Ĵ�СΪ�� " << sizeof(F1) << endl;  // ��СΪ12

    cout << "��Base3�Ĵ�СΪ�� " << sizeof(Base3) << endl;  // ��СΪ16
    cout << "��G�Ĵ�СΪ�� " << sizeof(G) << endl;  // ��СΪ32

    Fun Fun_ptr = NULL;
    G g;
    Fun_ptr = (Fun)*((int*)*(int*)(&g));
    Fun_ptr();  // ִ��G::f()����

    cout << "��Base4�Ĵ�СΪ�� " << sizeof(Base4) << endl;  // ��СΪ16
    cout << "��Base5�Ĵ�СΪ�� " << sizeof(Base5) << endl;  // ��СΪ24
    cout << "��H�Ĵ�СΪ�� " << sizeof(H) << endl;  // ��СΪ32

    I i;

    K k;
    cout << "��Base6�Ĵ�СΪ�� " << sizeof(Base6) << endl;  // ��СΪ12
    cout << "��I�Ĵ�СΪ�� " << sizeof(I) << endl;  // ��СΪ44
    cout << "��J�Ĵ�СΪ�� " << sizeof(J) << endl;  // ��СΪ16
    cout << "��K�Ĵ�СΪ�� " << sizeof(K) << endl;  // ��СΪ52

    return 0;
}
