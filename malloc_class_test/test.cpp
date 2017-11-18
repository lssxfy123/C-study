// Copyright 2017.���|�|
// author�����|�|
// malloc������ָ��
#include <iostream>
#include "../include/print.hpp"
using namespace std;

class A {
    A()
    {
        cout << "construct A" << endl;
    }

    ~A()
    {
        cout << "destruct A" << endl;
    }
};

int main(int argc, char* argv[])
{
    // malloc�����ù��캯��
    // free��������������
    cout << "malloc A" << endl;
    A* a_ptr = (A*)malloc(sizeof(A));

    cout << "free A" << endl;
    free(a_ptr);
    return 0;
}
