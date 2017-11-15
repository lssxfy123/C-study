#include <iostream>
using std::cout;
using std::endl;

union {
    struct
    {
        unsigned char a;
        unsigned char b;
        unsigned char c;
        unsigned char d;

    }V;
    int i;
} U;

int main(int argc, char* argv[])
{
    int k = 0x123456;
    char* p = (char*)&k;
    cout << (int)*p << endl;  // 86，对应十六进制为0x56

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char* p1 = (char*)a;
    char* p2 = (char*)(a + 5);

    cout << p2 - p1 << endl;  // 20

    U.i = 2;
    U.V.a = 2;
    U.V.d = U.V.c = U.V.b = U.V.a++;

    cout << U.i << endl;
    return 0;
}
