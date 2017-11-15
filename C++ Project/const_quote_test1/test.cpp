// const引用

#include <iostream>

int main(int argc, char* argv[])
{
    const int a = 10;

    const int& quote_a = a;  // ok
    const int& quote_d = 15;  // ok

    // int& quote_b = a;  // error 不能将非const引用绑定的const对象上
    // int& quote_c = 15;  // error

    int n = 5;
    const int& quote_n = n;  // ok，可以将const引用绑定到非const对象上

    n = 6;
    std::cout << "n = " << n << std::endl;
    std::cout << "quote_n = " << quote_n << std::endl;

    // quote_n = 89;  // error,不能给常量赋值，参考指向常量的指针

    return 0;
}
