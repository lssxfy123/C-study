// Copyright 2017.刘珅珅
// author：刘珅珅
// 重载与using指示
#include <iostream>
using std::cout;
using std::endl;

namespace sgcc
{
    void Print(int n)
    {
        cout << "sgcc::Print(int n)" << endl;
    }

    void Print(double f)
    {
        cout << "sgcc::Print(double f)" << endl;
    }
}

namespace xxcig
{
    void Print(int n)
    {
        cout << "xxcig::Print(int n)" << endl;
    }
}

using namespace sgcc;
using namespace xxcig;

int main(int argc, char* argv[])
{
    int n = 5;
    // Print(n);  // error，对重载函数的调用不明确

    return 0;
}

