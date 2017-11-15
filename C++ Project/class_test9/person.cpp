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
     *这个拷贝构造函数是必须的，原因是析构函数中使用deltete将堆空间返回给系统
     *如果没有拷贝构造函数，而使用默认的拷贝构造函数，那么后面的程序中p1,p2将拥有完全相同的堆空间，
     在析构时，析构了p2后，堆空间已经返回给系统，再析构p1时，执行delete pName;就会出错
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

