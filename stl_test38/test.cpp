// Copyright 2017.���|�|
// author�����|�|
// ������Ϊ�㷨��ʵ��3��˫���ж�ʽ
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
using namespace std;

struct Person{
public:
    Person(string first_name, string last_name)
    {
        first_name_ = first_name;
        last_name_ = last_name;
    }

public:
    string first_name_;
    string last_name_;
};

// ˫���ж�ʽ
bool PersonSortCriterion(const Person& p1, const Person& p2)
{
    return p1.last_name_.compare(p2.last_name_) < 0
        || (p1.last_name_.compare(p2.last_name_) == 0
        && p1.first_name_.compare(p2.first_name_) < 0);
}

int main(int argc, char* argv[])
{
    deque<Person> coll{ { "Jam", "Tom" }, { "Jo", "Robert" }, {"Trump", "Bill"} };
    sort(coll.begin(), coll.end(), PersonSortCriterion);
    for (const auto& elem : coll)
    {
        cout << "first name " << elem.first_name_.c_str() 
            << " last name " << elem.last_name_.c_str() << endl;
    }

    return 0;
}
