#include "graduatestudent.h"

#include <iostream>

// �����ڹ��캯���ĳ�ʼ���б��ж�advisor_�����ʼ������ΪAdvisor��û��Ĭ�Ϲ��캯��
// ������ø���Student�Ĺ��캯������ΪStudentû��Ĭ�ϵĹ��캯��
GraduateStudent::GraduateStudent() : advisor_(5),  Student("no name")
{
    std::cout << "GraduateStudent()" << std::endl;
}

int GraduateStudent::GetQualifier()
{
    semester_hours_ = 0;  // ����ֱ�ӷ��ʸ����protected��Ա
    return qualifier_grade_;
}
