#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    char* str = "abd" + 2;  // 输出为d：将指针向后移动了两次
    // char* str1 = "abd" + "cde";  // error：无法将两个指针相加
    cout << str << endl;
    return 0;
}