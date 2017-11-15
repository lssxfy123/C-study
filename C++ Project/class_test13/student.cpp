#include <iostream>
#include <string>
#include "student.h"
using namespace std;

Student::Student(char* pName)
{
    cout << "Student()" << endl;

    strncpy(name_, pName, sizeof(name_));
    average_ = semester_hours_ = 0;
}

void Student::AddCourse(int hours, float grade)
{
    average_ = (semester_hours_ * average_ + grade);//总分
    semester_hours_ += hours;//总修学时
    average_ /= semester_hours_;
}

int Student::GetHours()
{
    return semester_hours_;
}

float Student::GetAverage()
{
    return average_;
}

void Student::Display()
{
    cout << "name= \"" <<name_ << "\""  //注意这里输出的写法，若写成cout<<"name= \"<<name<<"\"，则会报错，若写成cout<<"name= "<<name，则输出的字符串没有引号
        << ", hours=" << semester_hours_
        << ", average=" << average_ <<endl;
}

