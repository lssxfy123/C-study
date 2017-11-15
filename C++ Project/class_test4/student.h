#ifndef STUDENT_H
#define STUDENT_H

class Student
{
  public:
    Student(char* name_ptr = "no name");
    ~Student();
    static int number();

  protected:
    static int number_students;
    char name[40];
};

#endif
