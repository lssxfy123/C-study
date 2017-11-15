#include <iostream>
#include <string>
#include "person.h"
using namespace std;

Person::Person(char* name_ptr)
{ 
    cout <<"constructing " << name_ptr << endl;
    name_ptr_ = new char[strlen(name_ptr) + 1];

    if (name_ptr_ != 0)
    {
        strcpy(name_ptr_, name_ptr);
    }

}

Person::Person(Person& p)
{
    /*
     *����������캯���Ǳ���ģ�ԭ��������������ʹ��deltete���ѿռ䷵�ظ�ϵͳ
     *���û�п������캯������ʹ��Ĭ�ϵĿ������캯������ô����ĳ�����p1,p2��ӵ����ȫ��ͬ�Ķѿռ䣬
     ������ʱ��������p2�󣬶ѿռ��Ѿ����ظ�ϵͳ��������p1ʱ��ִ��delete pName;�ͻ����
    */
    cout<< "Copying " << p.name_ptr_ << " into its own block\n";
    name_ptr_ = new char[strlen(p.name_ptr_) + 1];
    if (name_ptr_ != 0)
    {
        strcpy(name_ptr_,p.name_ptr_);
    }

}

Person::~Person()
{
    cout << "destructing " << name_ptr_ << endl;
    delete [] name_ptr_;
    name_ptr_ = NULL;
}

