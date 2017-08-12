// Copyright 2017.���|�|
// author�����|�|
// Funtion Object���ڲ�״̬
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include "../include/print.hpp"
using namespace std;

class IntSequence {
public:
    IntSequence(int init_value) : value_(init_value)
    {}

    int operator() () {
        return ++value_;
    }

private:
    int value_;
};

class MeanValue {
public:
    MeanValue() : number_(0), sum_(0) {
    }

    void operator() (int elem)
    {
        ++number_;
        sum_ += number_;
    }

    double value() {
        return static_cast<double>(sum_) / static_cast<double>(number_);
    }
private:
    long number_;
    long sum_;
};

int main(int argc, char* argv[])
{
    list<int> coll;

    // IntSequence(1)
    generate_n(back_inserter(coll),  // start
                      9,                             // number of elements
                      IntSequence(1));       // generates vlaues, starting with 1
    PrintElements(coll, "generate 1-9:    ");

    cout << "replace second to last element but one with values starting at 42" << endl;
    // IntSequence(42)
    generate(next(coll.begin()), prev(coll.end()), IntSequence(42));
    PrintElements(coll, "replace:    ");

    // ��refernce����function object
    list<int> coll1;
    list<int> coll2;
    IntSequence seq(1);
    // ��Ҫ�ڵ����㷨ʱ��ʾfunction object�Ǹ�reference����
    generate_n<back_insert_iterator<list<int>>,
        int, IntSequence&>(back_inserter(coll1), 5, seq);
    PrintElements(coll1, "coll1:    ");
    generate_n(back_inserter(coll2), 5, seq);
    PrintElements(coll2, "coll2:   ");


    // for_each�㷨�ش�function object
    vector<int> coll3 = {1, 2, 3, 4, 5, 6, 7, 8};
    MeanValue mv = for_each(coll3.begin(), coll3.end(), MeanValue());
    cout << "mean value: " << mv.value() << endl;
    return 0;
}
