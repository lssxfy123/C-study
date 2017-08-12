// Copyright 2017.刘珅珅
// author：刘珅珅
// bind()调用类成员函数
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>
#include "../include/print.hpp"
using namespace std;
using namespace std::placeholders;

class Person {
public:
    Person(const string& name) : name_(name) {
    }

    void Print() const {
        cout << name_ << endl;
    }

    // 不能使用函数重载
    // bind()无法判断绑定哪个函数
    void Print2(const string& prefix) const {
        cout << prefix << name_ << endl;
    }

private:
    string name_;
};

int main(int argc, char* argv[])
{
    vector<Person> coll = {Person("Tick"), Person("Trick"), Person("Track")};
    // bind(&Person::Print, _1)第一个实参为成员函数
    // 下一个实参定义“用以调用成员函数”的对象
    // 其他任何实参都会被传递给该成员函数
    for_each(coll.begin(), coll.end(), bind(&Person::Print, _1));
    cout << endl;
    for_each(coll.begin(), coll.end(), bind(&Person::Print2, _1, "Person:  "));
    cout << endl;

    // 单独使用bind
    bind(&Person::Print2, _1, "This is:  ")(Person("nico"));

    Person* ptr = new Person("Jam");
    // 传递对象的指针给bind
    bind(&Person::Print2, _1, "This is:  ")(ptr);
    delete ptr;

    // 传递smart pointer给bind
    shared_ptr<Person> sp(new Person("Tom"));
    bind(&Person::Print2, _1, "This is:  ")(sp);
    return 0;
}
