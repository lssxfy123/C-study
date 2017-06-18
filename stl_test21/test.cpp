// Copyright 2017.���|�|
// author�����|�|
// �⸲����wrapper
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
    // vector<Test&> coll;  // error�����ò�����ΪSTL����������
    // coll�е�Ԫ�ؽ����������öԴ�
    vector<reference_wrapper<Test>> coll;

    vector<Test> val;
    coll.push_back(t);
    val.push_back(t);
    t.Add();
    t.Print();  // 2

    for (auto m : coll)
    {
        // m.get()���ص���Test&����
        m.get().Print();  // 2
    }

    for (auto n : val)
    {
        n.Print();  // 1
    }
    return 0;
}
