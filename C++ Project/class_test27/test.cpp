// ������

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
    Student st;  // Student��Teacher�����ӵ��Ĭ�Ϲ��캯����������Ҫ��TutoPair�Ĺ��캯����ʼ���б��н��г�ʼ��
    Teacher th;
};

void main()
{
    TutoPair tp;
}


