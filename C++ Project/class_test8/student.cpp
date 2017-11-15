#include <iostream>
#include <string>
#include "student.h"
using namespace std;

Student::Student(char* name_ptr,int ssID)
{
    strcpy(name_, name_ptr);
    cout << "constructing new student " << name_ << endl;
}

Student::Student(Student& s)
//拷贝构造函数，必须用引用，不能直接用Student(student s)
//因为不能像基本数据类型那样直接传递对象的值。
{
    cout << "constructing copy of " << s.name_ << endl;
    strcpy(name_, "copy of ");
    strcat(name_, s.name_);
    id_ = s.id_;
}


Student::~Student()
{
    cout<< "destructing " << name_ <<endl;
}

