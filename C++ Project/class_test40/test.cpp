// Copyright 2017.���|�|
// author�����|�|
// ������usingָʾ
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
    // Print(n);  // error�������غ����ĵ��ò���ȷ

    return 0;
}

