// Copyright 2017.���|�|
// author�����|�|
// �ַ���ָ��
#include <stdio.h>

int main(int argc, char* argv[])
{
    char* str = "abc";  // ��ͬ��const char* str = "abc";
    // str[0] = 'p';  // error������ʱû���⣬����ʱ�������

    char strArray[4] = "abc";

    strArray[2] = 'p';

    // �ַ���"abc"�����ڳ���������������ݲ������޸ģ���
    // �����ǳ���ָ�룬����char* str = "abc";�൱��strָ��
    // һ���ַ������������Բ����޸���ֵ��������char strArray[4] = "abc";
    // strArray�����ջ���������ǽ��ַ�ָ��"abc"��ֵ���Ƹ���strArray����
    // �޸ĵ��Ǵ����ջ���ַ���"abc"
    printf("%s\n", strArray);  // abp
    return 0;
}

