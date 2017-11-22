#include "graduatestudent.h"

#include <iostream>

// 必须在构造函数的初始化列表中对advisor_对象初始化，因为Advisor类没有默认构造函数
// 必须调用父类Student的构造函数，因为Student没有默认的构造函数
GraduateStudent::GraduateStudent() : advisor_(5),  Student("no name")
{
    std::cout << "GraduateStudent()" << std::endl;
}

int GraduateStudent::GetQualifier()
{
    semester_hours_ = 0;  // 可以直接访问父类的protected成员
    return qualifier_grade_;
}
