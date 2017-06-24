// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// swap£ºÁ½Öµ»¥»»
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Container
{
public:
    Container(int number, string str)
    {
        number_ = number;
        str_ = str;
    }

    void swap(Container& x)
    {
        std::swap(number_, x.number_);
        std::swap(str_, x.str_);
    }

    void Print()
    {
        cout << "number " << number_ << " str " << str_.c_str() << endl;
    }
private:
    int number_;
    string str_;
};

int main(int argc, char* argv[])
{
    int a[5] = { 1, 2, 3, 4, 5 };
    int b[5] = { 6, 7, 8, 9, 10 };
    std::swap(a, b);
    cout << "array a" << endl;
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "array b" << endl;
    for (int j : b)
    {
        cout << j << " ";
    }
    cout << endl;

    Container c1(5, "hello");
    Container c2(6, "world");
    cout << "before swap " << endl;
    c1.Print();
    c1.swap(c2);
    cout << "after swap" << endl;
    c1.Print();
    return 0;
}
