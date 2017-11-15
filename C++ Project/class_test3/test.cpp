#include <iostream>

class Test1
{
  public:
    explicit Test1(int n)
    {
        std::cout << "调用构造函数" << std::endl;
        num = n;
    }

    //Test1(int n)
    //{
    //    std::cout << "调用构造函数" << std::endl;
    //    num = n;
    //}

    Test1(Test1& a)
    {
        std::cout << "调用拷贝构造函数" << std::endl;
        num = a.num;
    }

  private:
    int num;
};

int main(int argc, char* argv[])
{
    // Test1 t1 = 5;  // error，无法进行隐式转换
    Test1 t1(5);

    Test1 t2 = t1;
    return 0;
}
