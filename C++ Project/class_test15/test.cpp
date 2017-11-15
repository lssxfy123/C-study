// ��Ķ�̬��

#include <iostream>
using namespace std;

class A  // ����
{
  public:
    virtual A* f()
    {
        cout << "A��f()" << endl;
        return this;
    }
};

class B : public A  // ������
{
  public:
    virtual B* f()  // ���ܺͻ����е�f()�ķ���ֵ���Ͳ�ͬ����f()��Ȼ���麯��
    {
        cout << "B��f()" << endl;
        return this;
    }
};

int main(int argc, char* argv[])
{
    A* a_ptr = new A;
    a_ptr->f();  // ִ��A��f()
    delete a_ptr;
    a_ptr = NULL;

    a_ptr = new B;  // ����ָ��ָ�����������
    a_ptr->f();  // ִ��B��f()

    delete a_ptr;
    a_ptr = NULL;

    B b;
    A& a_ref = b;  // �������ð����������
    a_ref.f();  // ִ��B��f()

    A a = b;
    a.f();  // ִ��A��f()������Ķ���ֱ�ӵ��ã���������̬��

    B* b_ptr = NULL;
    a_ptr = new A;
    b_ptr = (B*)a_ptr;  // �������ǲ���ȫ��
    b_ptr->f();  // ִ��A��f()��b_ptrֻ�ܵ��û���A�ĺ���

    delete a_ptr;
    a_ptr = NULL;
    b_ptr = NULL;

    return 0;
}
