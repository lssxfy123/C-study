// Copyright 2017.刘珅珅
// author：刘珅珅
// 类模板的测试   
#include "list.h"

int main(int argc, char *argv[])
{
    List <float> floatList;

    for (int i = 1; i < 7; ++i)
    {
        floatList.Add( *(new float(i + 0.6)));
    }

    // 这里有4个输出操作符，只有第3个输出操作符是重载的
    cout << "输出链表的所有内容" << endl << floatList << endl;

    float b = 3.6;
    float *pa = floatList.Find(b);

    if (pa)
    {
        floatList.Remove(*pa);
    }

    cout << floatList << endl;

    //让输出不一闪而逝
    system("pause");
    return 0;
}
