// Copyright 2017.刘珅珅
// author：刘珅珅
// 外覆器：wrapper
#include <iostream>
#include <vector>
using namespace std;

class Test
{
public:
    Test(int a) : number_(a)
    {
    }

public:
    void Add()
    {
        ++number_;
    }

    void Print() const
    {
        cout << "number is " << number_ << endl;
    }

private:
    int number_;
};

int main(int argc, char* argv[])
{
    Test t(1);
    // vector<Test&> coll;  // error，引用不能作为STL容器的类型
    // coll中的元素将被当成引用对待
    vector<reference_wrapper<Test>> coll;

    vector<Test> val;
    coll.push_back(t);
    val.push_back(t);
    t.Add();
    t.Print();  // 2

    for (auto m : coll)
    {
        // m.get()返回的是Test&类型
        m.get().Print();  // 2
    }

    for (auto n : val)
    {
        n.Print();  // 1
    }
    return 0;
}
