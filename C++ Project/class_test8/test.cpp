// �������캯��

#include <iostream>
#include "student.h"

void func(Student s);

int main(int argc, char* argv[])
{
    Student randy("Randy", 1234);

    func(randy);  // ���ÿ������캯��

    std::cout << "retruned from func()\n";

    Student jenny = randy;  // ���ÿ������캯��

    return 0;
}

void func(Student s)
{
    std::cout << "In function func()\n";
}
