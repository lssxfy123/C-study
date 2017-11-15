#ifndef STUDENT_H
#define STUDENT_H

class Student
{
  public:
    Student(char* name_ptr = "no name", int ssID = 0);
    Student(Student& s);  //  ¿½±´¹¹Ôìº¯Êý
    ~Student();

  protected:
    char name_[40];
    int id_;

};

#endif  // STUDENT_H
