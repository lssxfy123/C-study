#ifndef TEST_H_H
#define TEST_H_H

//int sum(int a, int b)  // error，重复定义的链接错误
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
    // 会默认为inline
    int sum(int a, int b)  // ok
    {
        return (a + b);
    }

    // 会默认为inline
    A& operator* ()
    {
        return *this;
    }

    void func();
};

// error，重复定义错误
//void A::func()
//{
//
//}

#endif

