// ��̳��еĺ������Ǻ�����

#include <iostream>

class Base
{
  public:
    virtual void xfn(int i)
    {
        std::cout << "Base::xfn(int i)" << std::endl;
    }

    void yfn(float f)
    {
        std::cout << "Base::yfn(float f)" << std::endl;
    }

    void zfn()
    {
        std::cout << "Base::zfn()" << std::endl;
    }

    virtual void tfn(int i)
    {
        std::cout << "Base::tfn(int i)" << std::endl;
    }
};

class Derive : public Base
{
  public:
    virtual void xfn(int i)  // �麯������������
    {
        std::cout << "Derive::xfn(int i)" << std::endl;
    }

    void yfn(int c)  // �������λ���Base�ĺ���
    {
        std::cout << "Derive::yfn(int c)" << std::endl;
    }

    void zfn()  // �������λ���Base�ĺ���
    {
        std::cout << "Derive::zfn()" << std::endl;
    }

    virtual void tfn()  // �������λ����Base��������Ȼ����Ϊ�麯�������γɲ�ͬ����������̬��
    {
        std::cout << "Derive::tfn()" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    Derive d;

    Base* b_ptr = &d;
    Derive* d_ptr = &d;

    b_ptr->xfn(5);  // ����Derive���xfn()����
    d_ptr->xfn(5);  // ����Derive���xfn()����

    b_ptr->yfn(3.5);  // ����Base���yfn()����
    d_ptr->yfn(4);  // ����Derive���yfn()����

    b_ptr->zfn();  // ����Base���zfn()����
    d_ptr->zfn();  // ����Derive���zfn()����

    b_ptr->tfn(5);  // ����Base���tfn()����
    // d_ptr->tfn(8);  // error���������͵Ķ����޷�ֱ�ӵ��û����е�ͬ������
    d_ptr->Base::tfn(8);  // ok������ͨ����������������û����е�ͬ������
    d_ptr->tfn();

    return 0;
}
