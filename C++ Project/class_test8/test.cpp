// 拷贝构造函数

#include <iostream>
#include "student.h"

void func(Student s);

int main(int argc, char* argv[])
{
    Student randy("Randy", 1234);

    func(randy);  // 调用拷贝构造函数

    std::cout << "retruned from func()\n";

    Student jenny = randy;  // 调用拷贝构造函数

    return 0;
}

void func(Student s)
{
    std::cout << "In function func()\n";
}
