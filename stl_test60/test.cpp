// Copyright 2017.���|�|
// author�����|�|
// bind()�������Ա����
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

    // ����ʹ�ú�������
    // bind()�޷��жϰ��ĸ�����
    void Print2(const string& prefix) const {
        cout << prefix << name_ << endl;
    }

private:
    string name_;
};

int main(int argc, char* argv[])
{
    vector<Person> coll = {Person("Tick"), Person("Trick"), Person("Track")};
    // bind(&Person::Print, _1)��һ��ʵ��Ϊ��Ա����
    // ��һ��ʵ�ζ��塰���Ե��ó�Ա�������Ķ���
    // �����κ�ʵ�ζ��ᱻ���ݸ��ó�Ա����
    for_each(coll.begin(), coll.end(), bind(&Person::Print, _1));
    cout << endl;
    for_each(coll.begin(), coll.end(), bind(&Person::Print2, _1, "Person:  "));
    cout << endl;

    // ����ʹ��bind
    bind(&Person::Print2, _1, "This is:  ")(Person("nico"));

    Person* ptr = new Person("Jam");
    // ���ݶ����ָ���bind
    bind(&Person::Print2, _1, "This is:  ")(ptr);
    delete ptr;

    // ����smart pointer��bind
    shared_ptr<Person> sp(new Person("Tom"));
    bind(&Person::Print2, _1, "This is:  ")(sp);
    return 0;
}
