// ��������

#include <iostream>
#include <vector>
using std::vector;

class A
{
  public:
    A()
    {
        std::cout << "ִ�й��캯��" << std::endl;
    }

    A(const A& a)
    {
        std::cout << "ִ�п������캯��" << std::endl;
    }

    ~A()
    {
        std::cout << "ִ����������" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    //A* p = new A;

    //delete p;  // ɾ��pʱִ��������������������������Զ�ִ����������
    //p = NULL;

    A a1;

    vector<A> vec;
    vec.push_back(a1);

    std::cout << "vec size = " << vec.size() << std::endl;
    std::cout << "vec capacity = " << vec.capacity() << std::endl;

    vec.push_back(a1);

    std::cout << "vec size = " << vec.size() << std::endl;
    std::cout << "vec capacity = " << vec.capacity() << std::endl;

    vec.push_back(a1);

    std::cout << "vec size = " << vec.size() << std::endl;
    std::cout << "vec capacity = " << vec.capacity() << std::endl;
    return 0;
}
