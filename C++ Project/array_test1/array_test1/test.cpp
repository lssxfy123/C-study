#include <iostream>
using std::cout;
using std::endl;

void func(int* p);

int main(int argc, char* argv[])
{
    int a[3] = {1, 2, 3};
    int b[3];
    // b = a;  // error���޷������������鸴��

    func(a);
    cout << a[0] << endl;
    cout << a[1] << endl;
    cout << a[2] << endl;

    int c[2][3] = {{1, 2, 3,}, {4, 5, 6}};
    // int c[2][3] = {1, 2, 3, 4, 5, 6};  // ��C++�У���ά�������������ֵ
    cout << c[0][1] << endl;
    cout << c[1][0] << endl;

    int d[2][3] = {1, 2, 3, 4};
    cout << d[1][1] << endl;  // Ĭ��ֵΪ0

    int n = 9;
    unsigned int k = 0;
    k = (n - 10) * 5 + 100;
    cout << k << endl;
    return 0;
}

void func(int* p)
{
    p = new int[4];
    p[0] = 11;
}
