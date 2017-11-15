// C++�麯����

#include <iostream>

class Base
{
  public:

    void func()  // �����麯�����������麯������
    {
        std::cout << "Base::func()" << std::endl;
    }

    virtual void f()
    {
        std::cout << "Base::f()" << std::endl;
    }

    virtual void g()
    {
        std::cout << "Base::g()" << std::endl;
    }

    virtual void h()
    {
        std::cout << "Base::h()" << std::endl;
    }
};

class Derive : public Base
{
  public:
    void f()
    {
        std::cout << "Derive::f()" << std::endl;
    }

    void g()
    {
        std::cout << "Derive::g()" << std::endl;
    }

    void h()
    {
        std::cout << "Derive::h()" << std::endl;
    }

  private:
    virtual void test()  // ���е��麯����Ҳ����Derive������麯������
    {
        std::cout << "Derive::test()" << std::endl;
    }
};

typedef void (*Fun)(void);

int main(int argc, char* argv[])
{
    Base b;

    Fun Fun_ptr = NULL;

    // ���������������ͬ�ģ������麯����ĵ�ַ
    // ԭ�����麯�������ڶ�����׵�ַ
    std::cout << "�麯�����ַ��" << &b << std::endl;

    // ǿ��ת��Ϊ����ָ��õ���ָ��ָ�������׵�ַ
    std::cout << (int*)(&b) << std::endl;

    // ��ָ���ֵ����һ������ȡ������Ҳ���԰�һ������ֵ������ַ����һ��ָ��

    int n = *(int*)(&b);  // ����õ������麯������Ҳ��һ��ָ�룬Ҳ���Կ�����һ����ַ
    std::cout << (int*)n << std::endl;  // ����õ������麯������׵�ַ

    // ������Ҫ��&bǿ��ת����int*��Ȼ��ȡ����ָ��Ķ���Ȼ����ǿ��ת����int*
    // ������Ϊ�麯�����д�ŵ��Ƕ�����麯���ĺ���ָ��
    std::cout << "�麯����-��һ��������ַ��" << (int*)*(int*)(&b) << std::endl;

    // (int*)(&b)���麯����Ĵ�ŵ�ַ������b���׵�ַ
    // (int*)*(int*)(&b)���麯������׵�ַ����һ���麯���Ĵ�ŵ�ַ
    // (*((int*)*(int*)(&b)))����һ���麯��
    Fun_ptr = (Fun)(*((int*)*(int*)(&b)));

    Fun_ptr();  // ����Base::f()

    Fun_ptr = (Fun)*((int*)*(int*)(&b) + 1);
    Fun_ptr();  // ����Base::g()

    Fun_ptr = (Fun)*((int*)*(int*)(&b) + 2);
    Fun_ptr();  // ����Base::h()

    Base* b_ptr = new Derive();

    std::cout << "�麯�����ַ��" << b_ptr << std::endl;

    std::cout << "�麯����-��һ��������ַ��" << (int*)*(int*)(b_ptr) << std::endl;

    // Fun_ptr = (Fun)*((int*)*(int*)(b_ptr));
    Fun_ptr = (Fun)*((int*)*(int*)(b_ptr));

    Fun_ptr();  // ����Derive::f()

    Fun_ptr = (Fun)*((int*)*(int*)(b_ptr) + 1);
    Fun_ptr();  // ����Derive::g()

    Fun_ptr = (Fun)*((int*)*(int*)(b_ptr) + 2);
    Fun_ptr();  // ����Derive::h()

    // �����麯������ɵ����⣬���ǿ���ͨ�����ַ�ʽ���������������еĲ�����˽�е��麯��
    Fun_ptr = (Fun)*((int*)*(int*)(b_ptr) + 3);
    Fun_ptr();  // ����Derive::test()

    delete b_ptr;
    b_ptr = NULL;

    return 0;
}
