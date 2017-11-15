// 动态分配字符指针与删除

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    char* ptr = new char[2];
    memset(ptr, 0, 2);

    ptr[0] = 'a';
    ptr[1] = '\0';
    cout << ptr << endl;
    delete ptr;
    ptr = NULL;
    return 0;
}
