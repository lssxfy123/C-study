#ifndef GRADUATESTUDENT
#define GRADUATESTUDENT

#include "advisor.h"
#include "student.h"

class GraduateStudent : public Student  // 类的继承
{
  public:
    GraduateStudent();

  public:
    int GetQualifier();

  protected:
    Advisor advisor_; //一个类以另外一个类对象作数据成员，叫类的组合
    int qualifier_grade_;

};

#endif  // GRADUATESTUDENT
