#include <iostream>
#include <string>
#include "student.h"

int Student::number_students = 0;  // ��ʼ����̬���ݳ�Ա

//��̬���ݳ�Ա�������������ռ�ͳ�ʼ��
//���������������ð���������ʼ��

Student::Student(char* name_ptr)
{
    std::cout << "Create one student\n";
    strcpy(name, name_ptr);

    ++number_students;  // ��̬��Ա��ÿ����һ������ѧ��������1
    std::cout << number_students << std::endl;
}

Student::~Student()
{
    std::cout << "destruct one student\n";
    --number_students;//ÿ����һ������ѧ��������1
}

int Student:: number()//��̬��Ա����
{
    return number_students;
}

