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
    average_ = (semester_hours_ * average_ + grade);//�ܷ�
    semester_hours_ += hours;//����ѧʱ
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
    cout << "name= \"" <<name_ << "\""  //ע�����������д������д��cout<<"name= \"<<name<<"\"����ᱨ����д��cout<<"name= "<<name����������ַ���û������
        << ", hours=" << semester_hours_
        << ", average=" << average_ <<endl;
}

