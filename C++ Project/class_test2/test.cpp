// thisָ��

#include <iostream>

#include "b.h"
#include "c.h"
#include "d.h"

int main(int argc, char* argv[])
{
    B b;
    b.SetHeight(30).SetWidth(40);

    C c1;
    c1.SetHeight(100);
    c1.GetHeight();  // ok����const������Ե���const��Ա����
    c1.PrintValue();

    const C c2;
    // c2.SetHeight(300);  // error��const����ֻ�ܵ���const��Ա����
    c2.GetHeight();  // ok�����Ե���const��Ա����

    D d;
    d.Display().func();  // thisָ����һ��ָ�볣�����������޸ģ�ֻ��ָ�������

    const D d1;
    d1.Display();
    // d1.Display().func();  // error�����ص�thisָ����һ��ָ��const�����constָ�룬���ܵ��÷�const��Ա����

    return 0;
}
