#include "b.h"

#include <iostream>

// ע�⣬���ﹹ�캯�����β�Ӧ����Ϊ�������ͣ��������Ϊ��ͨ���͵�i��
// �����ʼ������ref�󣬹��캯��ִ����Ϻ�i��������������ref��ֵ�ͻ���δ֪�������

B::B(int& i):ten(10), ref(i), a(i)
{
    std::cout << "����B���캯��" << std::endl;
}

B::~B()
{

}

void B::PrintValue()
{
    std::cout << ten << std::endl;
    std::cout << ref << std::endl;
}
