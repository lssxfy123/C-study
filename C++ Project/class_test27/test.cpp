// 类的组合

#include <iostream>
using namespace std;

class Student
{
  public:
    Student()
    {
        cout << "constructing student.\n";
    }

    ~Student()
    {
        cout << "distructing student.\n";
    }
};

class Teacher
{
  public:
    Teacher()
    {
        cout << "constructing teacher.\n";
    }

    ~Teacher()
    {
        cout << "distructing teacher.\n";
    }
};

class TutoPair
{
  public:
    TutoPair()
    {
        cout << "constructing TutoPair.\n";
    }

    ~TutoPair()
    {
        cout << "distructing TutoPair.\n";
    }

  private:
    Student st;  // Student和Teacher类必须拥有默认构造函数，否则需要在TutoPair的构造函数初始化列表中进行初始化
    Teacher th;
};

void main()
{
    TutoPair tp;
}


