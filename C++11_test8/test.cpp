// Copyright 2017.���|�|
// author�����|�|
// ��ֹ����
#include <iostream>
#include "../include/print.hpp"
using namespace std;

class NoCopy
{
public:
    NoCopy() = default;  // ʹ�úϳɵ�Ĭ�Ϲ��캯��
    NoCopy(const NoCopy&) = delete;  // ��ֹ����
    NoCopy& operator = (const NoCopy&) = delete;  // ��ֹ��ֵ
    ~NoCopy() = default;  // ʹ�úϳɵ���������
};

int main(int argc, char* argv[])
{
    return 0;
}
