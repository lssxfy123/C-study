// Copyright 2017.���|�|
// author�����|�|
// smartָ�룺weak_ptr
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Person
{
public:
    Person(const string& name,
        shared_ptr<Person> mother = nullptr,
        shared_ptr<Person> father = nullptr)
        : name_(name), mother_(mother), father_(father)
    {
    }

    ~Person()
    {
        cout << "delete " << name_.c_str() << endl;
    }
public:
    string name_;
    shared_ptr<Person> mother_;
    shared_ptr<Person> father_;
    // ����Ҫʹ����smartָ��
    // ���ʹ��shared_ptr������
    // ���ڻ���ʽָ�򣬻����
    // ָ������ͷŵ����
    vector<weak_ptr<Person>> kids_;
};

shared_ptr<Person> InitFamily(const string& name)
{
    shared_ptr<Person> mom(new Person(name + "'s mom"));
    shared_ptr<Person> dad(new Person(name + "'s dad"));
    shared_ptr<Person> kid(new Person(name, mom, dad));
    mom->kids_.push_back(kid);
    dad->kids_.push_back(kid);
    return kid;
}

int main(int argc, char* argv[])
{
    shared_ptr<Person> ptr = InitFamily("nico");
    cout << "nico is shared " << ptr.use_count() << " times" << endl;  // 1
    cout << "name of 1st kid of nico's mom " <<
        ptr->mother_->kids_[0].lock()->name_.c_str() << endl;
    ptr = InitFamily("jim");
    cout << "jim's family exists" << endl;

    // �ж�weak_ptr����Ķ����Ƿ����
    try
    {
        shared_ptr<string> sp(new string("hi"));
        weak_ptr<string> wp = sp;
        sp.reset();  // �ͷ�shared_ptr�����ͷ�ָ��Ķ���
        // weak_ptr����Ķ��󲻴���
        cout << wp.use_count() << endl;  // 0
        cout << boolalpha << wp.expired() << endl;  // true
        shared_ptr<string> p1 = wp.lock();  // p1Ϊempty
        shared_ptr<string> p2(wp);  // throw bad_weak_ptr
    }
    catch (const exception& e)
    {
        cerr << "exception: " << e.what() << endl;
    }
    return 0;
}
