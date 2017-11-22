// Copyright 2017.刘珅珅
// author：刘珅珅
// 全局变量、局部静态变量，局部变量
#include <iostream>
using std::cout;
using std::endl;

int count = 3;

int main(void)
{
    int i, sum, count = 2;

    // for循环判断条件中的count为局部变量count
    for (i = 0, sum=0; i < count; i += 2, count++)
    {
        static int count = 4;
        count++;  // 静态变量count

        if((i%2) == 0)
        {
            extern int count;  // 全局变量count
            cout << "count = " << count << endl;
            count++;
            sum += count;
        }
        sum += count;  // 静态变量count

        cout << "sum = " << sum << endl;
    }

    // count = 4，这里的count为局部变量count，在for循环判断条件中自增了两次
    // sum = 20
    cout << count << " " << sum << endl;

    return 0; 
}
