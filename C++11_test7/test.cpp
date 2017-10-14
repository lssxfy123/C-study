// Copyright 2017.���|�|
// author�����|�|
// lambda���ʽ2
#include <iostream>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    // �ɱ�lambda
    // ֵ�����lambdaһ�㲻�����޸Ĳ����ֵ
    // ������ͨ����ӹؼ���mutable���޸Ĳ����ֵ
    size_t v1 = 42;
    auto f1 = [v1]() mutable {return ++v1; };
    v1 = 0;
    auto j = f1();  // j = 43


    // ->int��ʾָ��lambda�ķ�������
    auto f3 = [](int i) ->int {
        if (i > 0)
            return i;
        else
            return -i;
    };

    auto k = f3(3);
    return 0;
}
