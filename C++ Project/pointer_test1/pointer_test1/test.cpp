
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
    cout << *p << endl;  // ���һ�������
    return 0;
}
