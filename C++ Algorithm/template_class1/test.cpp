/************************************************************************/
/*    �ļ���       ��test.cpp
/*    ����         �����|�|
/*    ����         ��2011/11/7
/*    ��������     ����ģ��Ĳ���                                                                     */
/************************************************************************/

#include "list.h"

int main(int argc, char *argv[])
{
    List <float> floatList;

    for (int i = 1; i < 7; ++i)
    {
        floatList.Add( *(new float(i + 0.6)));
    }

    // ������4�������������ֻ�е�3����������������ص�
    cout << "����������������" << endl << floatList << endl;

    float b = 3.6;
    float *pa = floatList.Find(b);

    if (pa)
    {
        floatList.Remove(*pa);
    }

    cout << floatList << endl;

    //�������һ������
    system("pause");
    return 0;
}
