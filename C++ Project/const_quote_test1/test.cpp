// const����

#include <iostream>

int main(int argc, char* argv[])
{
    const int a = 10;

    const int& quote_a = a;  // ok
    const int& quote_d = 15;  // ok

    // int& quote_b = a;  // error ���ܽ���const���ð󶨵�const������
    // int& quote_c = 15;  // error

    int n = 5;
    const int& quote_n = n;  // ok�����Խ�const���ð󶨵���const������

    n = 6;
    std::cout << "n = " << n << std::endl;
    std::cout << "quote_n = " << quote_n << std::endl;

    // quote_n = 89;  // error,���ܸ�������ֵ���ο�ָ������ָ��

    return 0;
}
