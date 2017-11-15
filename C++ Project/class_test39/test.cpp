// ������using����

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

// using sgcc::Print(double f);  // error��using�����޷������β�
using sgcc::Print;

void Print(char* str)
{
    cout << "str = " << str << endl;
}

//void Print(int n)  // error������void sgcc::Print(int)��������
//{
//    cout << "n = " << n << endl;
//}

int main(int argc, char* argv[])
{
    int n = 5;
    Print(n);  // ����sgcc::Print(int n)

    double f = 3.5;
    Print(f);  // ����sgcc::Print(double f)

    char* str = "abcde";
    Print(str);  // ����Print(char* str)
    return 0;
}

