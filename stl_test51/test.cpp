// Copyright 2017.���|�|
// author�����|�|
// ����������������hash
#include <algorithm>
#include <cctype>
#include <unordered_set>
#include <iostream>
#include <iomanip>
#include "../include/hashval.hpp"
#include "../include/print.hpp"
using namespace std;

class Customer {
public:
    Customer(const string& fn, const string& ln, long n)
        : fname_(fn), lname_(ln), no_(n)
    {
    }

    friend ostream& operator << (ostream& os, const Customer& c)
    {
        return os << "[" << c.fname_ << "," << c.lname_
            << "," << c.no_ << "]";
    }

    friend class CustomerHash;
    friend class CustomerEqual;

private:
    string fname_;
    string lname_;
    long no_;
};

class CustomerHash
{
public:
    size_t operator() (const Customer& c) const {
        return hash_val(c.fname_, c.lname_, c.no_);
    }
};

class CustomerEqual
{
public:
    bool operator() (const Customer& c1, const Customer& c2) const
    {
        return c1.no_ == c2.no_;
    }
};

int main(int argc, char* argv[])
{
    // CustomerHashΪ�Լ��ṩ��hash����
    // CustomerEqualΪ�Լ��ṩ�ĵȼ�׼��
    unordered_set<Customer, CustomerHash, CustomerEqual> custset;
    custset.insert(Customer("nico", "josuttis", 42));
    PrintElements(custset);

    return 0;
}
