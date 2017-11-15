#include <iostream>
#include <string>
#include "student.h"

int Student::number_students = 0;  // 初始化静态数据成员

//静态数据成员在类声明外分配空间和初始化
//常量对象和引用用冒号运算符初始化

Student::Student(char* name_ptr)
{
    std::cout << "Create one student\n";
    strcpy(name, name_ptr);

    ++number_students;  // 静态成员：每创建一个对象，学生人数增1
    std::cout << number_students << std::endl;
}

Student::~Student()
{
    std::cout << "destruct one student\n";
    --number_students;//每析构一个对象，学生人数减1
}

int Student:: number()//静态成员函数
{
    return number_students;
}

