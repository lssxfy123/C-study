#include <iostream>

class Test1
{
  public:
    explicit Test1(int n)
    {
        std::cout << "���ù��캯��" << std::endl;
        num = n;
    }

    //Test1(int n)
    //{
    //    std::cout << "���ù��캯��" << std::endl;
    //    num = n;
    //}

    Test1(Test1& a)
    {
        std::cout << "���ÿ������캯��" << std::endl;
        num = a.num;
    }

  private:
    int num;
};

int main(int argc, char* argv[])
{
    // Test1 t1 = 5;  // error���޷�������ʽת��
    Test1 t1(5);

    Test1 t2 = t1;
    return 0;
}
