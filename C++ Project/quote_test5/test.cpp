// Copyright 2017.���|�|
// author�����|�|
// ָ���������Ϊ�β�
#include <iostream>

// v1Ϊpiָ������ã�v2Ϊpjָ������ã��޸����õ����޸�ʵ�α���
void PtrSwap( int*& v1, int*& v2)
{
    int* tmp = v2;  // �м����Ϊһ��ָ��
    v2 = v1;
    v1 = tmp;
}

int main( int argc,  char *argv[] )
{
    int i = 10;
    int j = 20;
    int* pi = &i;
    int* pj = &j;

    std::cout << pi << std::endl;
    std::cout << pj << std::endl;

    // pi��pj�������˽��� 
    PtrSwap( pi, pj );

    std::cout << pi << std::endl;
    std::cout << pj << std::endl;

    std::cout << *pi << std::endl; // ���Ϊ��20
    std::cout << *pj << std::endl; // ���Ϊ��10
    return 0;
}

