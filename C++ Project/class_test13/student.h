#ifndef STUDENT
#define STUDENT

class Student
{
  public:
    Student(char* name_ptr);
    void AddCourse(int hours, float grade);
    int GetHours();
    float GetAverage();
    void Display();

  protected:
    char name_[40];
    int semester_hours_;
    float average_;

};


#endif  // STUDENT
