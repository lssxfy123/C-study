#ifndef TEST_H_H
#define TEST_H_H

//int sum(int a, int b)  // error���ظ���������Ӵ���
//{
//    return (a + b);
//}

extern int kkk;
const int nnn = 0;
static int sub(int a, int b)
{
    return (a - b);
}

class A 
{
public:
    // ��Ĭ��Ϊinline
    int sum(int a, int b)  // ok
    {
        return (a + b);
    }

    // ��Ĭ��Ϊinline
    A& operator* ()
    {
        return *this;
    }

    void func();
};

// error���ظ��������
//void A::func()
//{
//
//}

#endif

