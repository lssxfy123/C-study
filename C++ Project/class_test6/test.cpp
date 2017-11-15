// const static 类成员变量

#include <iostream>

class Account
{
  public:
    const static int number = 30;  // 可以在类定义体中初始化
    double array[number];
};

class Bar
{
  public:
    Bar(int number = i)  // 静态变量作为形参的默认值
    {

    }

  private:
    static int i;
    static Bar bar1;  // ok，创建Bar对象时不会有问题，因为静态变量不占用实例的内存
        
    // Bar bar2;  // error，使用正在定义的Bar类型，在创建Bar对象时，会引起构造函数的无穷递归
};

int Bar::i = 9;
Bar Bar::bar1;

int main(int argc, char* argv[])
{
    Account a;
    std::cout << Account::number << std::endl;

    Bar bar1;
    return 0;
}
