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
//�������캯�������������ã�����ֱ����Student(student s)
//��Ϊ���������������������ֱ�Ӵ��ݶ����ֵ��
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

