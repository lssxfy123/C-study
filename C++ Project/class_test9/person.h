#ifndef PERSON_H
#define PERSON_H

class Person
{
  public:
    Person(char* name_ptr);
    Person(Person& p);//�������캯��
    ~Person();

  protected:
    char* name_ptr_;
};

#endif  // PERSON_H

