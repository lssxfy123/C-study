// Copyright 2017.���|�|
// author�����|�|
// �����������
#include <stdio.h>

int main(int argc, char* argv[])
{
    int number = 9;
    float* f_ptr = &number;
    int a = 1234567890;


    printf("number = %d\n", number);
    printf("*f_ptr = %f\n", *f_ptr);

    *f_ptr = 1234567890;

    printf("number = %d\n", number);
    printf("a = %d \n", a);
    printf("*f_ptr = %f\n", *f_ptr);

    *f_ptr = 12.34;

    printf("number = %x\n", number);
    printf("*f_ptr = %f\n", *f_ptr);


    //// ��������д���ᱨ���ڴ����
    //// ԭ��double��ָ��ָ��ĵ�ַ
    //// Ӧ��Ϊ8���ֽڣ���ʵ��ָ���
    //// ��4���ֽ�
    //double* d_ptr = &number;
    //*d_ptr = 9.8;

    // printf("%d\n", number);
    return 0;
}
