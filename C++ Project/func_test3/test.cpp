// ��������
#include <iostream>

inline int func(int a);  // ����Ϊinline���ڶ��崦����û�У���һ�㲻ͬ��const����

int main(int argc, char* argv[])
{
    int a = 1;
    a = func(a);

    return 0;
}

int func(int a)
{
    ++a;
    return a;
}
