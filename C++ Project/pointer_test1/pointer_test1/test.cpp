
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    int a = 5;
    int* p = &a;
    cout << p << endl;  // 00D3FDBC
    ++p;
    cout << p << endl;  // 00D3FDC0
    cout << *p << endl;  // 输出一个随机数
    return 0;
}
