// ��̳��еĺ�������

#include <iostream>

class Base
{
  public:
    virtual void fcn()
    {
        std::cout << "Base::fcn()" << std::endl;
    }
};

class Derive1 : public Base
{
  public:
    void fcn(int i)  // ���������˻����fcn()��������������̬��
    {
        std::cout << "Derive1::fcn(int i)" << std::endl;
    }
};

class Derive2 : public Derive1
{
  public:
    void fcn()
    {
        std::cout << "Derive2::fcn()" << std::endl;
    }

    void fcn(int i)  // �麯��Ҳ���Ա�����
    {
        std::cout << "Derive2::fcn(int i)" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    Base b;
    Derive1 d1;
    Derive2 d2;

    Base* b_ptr = &b;
    Base* b1_ptr = &d1;
    Base* b2_ptr = &d2;

    b_ptr->fcn();  // Base::fcn()

    // ����b1_ptr��b2_ptrָ��ķֱ���Derive1�����Derive2����
    // ���������Ǳ�����Base*���͵ı��������Բ��ܵ���Derive1��
    // Derive2�����г�Ա����
    b1_ptr->fcn();  // Base::fcn()
    b2_ptr->fcn();  // Derive2::fcn()

    return 0;
}
