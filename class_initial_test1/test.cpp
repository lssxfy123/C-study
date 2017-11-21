// Copyright 2017.刘珅珅
// author：刘珅珅
// 类中成员的初始化
#include <iostream>
using namespace std;

// C98下
// C11下可以初始化
class Test
{
private:
    // static int a = 0;  // error
    const static int b = 3;
    // const static double c = 3.5;  // error
    const static char d = 'a';  // ok，char也可以看成整型
    // const static char* str = "abc";  // error
    // const static char[b] = 'ac';  // error
};

int main(int argc, char* argv[])
{
    // 从上例可以看出，只有const static的整型变量或字符型变量才可以在声明中初始化
    // 参考http://www.cnblogs.com/good90/archive/2012/03/19/2405757.html
    return 0;
}
