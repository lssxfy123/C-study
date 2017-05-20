// Copyright 2017.刘珅珅
// author：刘珅珅
// Range-Based for循环
#include <iostream>
#include <vector>
using namespace std;

class P
{
public:
    P(int i)
    {
        num_ = i;
        cout << "P constructor" << endl;
    }

    void Print() const
    {
        cout << "P Print " << num_ << endl;
    }
private:
    int num_;
};

int main(int argc, char* argv[])
{
    int array[] {2, 3, 5, 7};
    for (auto i : array)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<P> vec;
    vec.push_back({1});
    vec.push_back({ 2 });
    vec.push_back({ 3 });

    for (const auto& elem : vec)
    {
        elem.Print();
    }

    // 等同于
    for (vector<P> ::iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        (*iter).Print();
    }
    return 0;
}
