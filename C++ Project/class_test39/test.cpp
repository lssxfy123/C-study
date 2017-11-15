// 重载与using声明

#include <iostream>
using std::cout;
using std::endl;

namespace sgcc
{
    void Print(int n)
    {
        cout << "n = " << n << endl;
    }

    void Print(double f)
    {
        cout << "f = " << f << endl;
    }
}

// using sgcc::Print(double f);  // error，using声明无法带上形参
using sgcc::Print;

void Print(char* str)
{
    cout << "str = " << str << endl;
}

//void Print(int n)  // error，函数void sgcc::Print(int)已有主体
//{
//    cout << "n = " << n << endl;
//}

int main(int argc, char* argv[])
{
    int n = 5;
    Print(n);  // 调用sgcc::Print(int n)

    double f = 3.5;
    Print(f);  // 调用sgcc::Print(double f)

    char* str = "abcde";
    Print(str);  // 调用Print(char* str)
    return 0;
}

