// Copyright 2017.���|�|
// author�����|�|
// �ݹ�
#include <iostream>
using std::cout;
using std::endl;

int func(int n)
{
    cout << "n = " << n << endl;
    int k = 1;
    if (n > 0)
    {
        k += func(--n);
        cout << "k = " << k << endl;
        // cout << n << endl;
        k += func(--n);
    }

    return k;
}

int main(void)
{
    int a = 2;
    cout << func(a) << endl;
    return 0;
}
