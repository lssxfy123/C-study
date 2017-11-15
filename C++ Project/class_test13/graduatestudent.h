#ifndef GRADUATESTUDENT
#define GRADUATESTUDENT

#include "advisor.h"
#include "student.h"

class GraduateStudent : public Student  // ��ļ̳�
{
  public:
    GraduateStudent();

  public:
    int GetQualifier();

  protected:
    Advisor advisor_; //һ����������һ������������ݳ�Ա����������
    int qualifier_grade_;

};

#endif  // GRADUATESTUDENT
