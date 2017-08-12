// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// ÆäËûµÄfunction adapter
#include <algorithm>
#include <functional>
#include <iostream>
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

private:
    string name_;
};

int main(int argc, char* argv[])
{
    // mem_fn()
    vector<Person> coll = { Person("Tick"), Person("Trick"), Person("Track") };
    for_each(coll.begin(), coll.end(), mem_fn(&Person::Print));
    return 0;
}
