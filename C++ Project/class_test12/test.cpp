// 析构函数

#include <iostream>
#include <vector>
using std::vector;

class A
{
  public:
    A()
    {
        std::cout << "执行构造函数" << std::endl;
    }

    A(const A& a)
    {
        std::cout << "执行拷贝构造函数" << std::endl;
    }

    ~A()
    {
        std::cout << "执行析构函数" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    //A* p = new A;

    //delete p;  // 删除p时执行析构函数，否则编译器不会自动执行析构函数
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
