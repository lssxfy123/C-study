// ����������

#include <iostream>

class Base
{
  public:
    Base()
    {
        std::cout << "ִ��Base�Ĺ��캯��" << std::endl;
    }

    virtual ~Base()
    {
        std::cout << "ִ��Base����������" << std::endl;
    }
};

class Derive : public Base
{
  public:
    Derive()
    {
        std::cout << "ִ��Derive�Ĺ��캯��" << std::endl;
    }

    ~Derive()
    {
        std::cout << "ִ��Derive����������" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    Base* b_ptr = new Derive();

    delete b_ptr;  // ��̬����������󣬱���ʹ��deleteɾ�������򲻻������������
    b_ptr = NULL;

    return 0;
}

