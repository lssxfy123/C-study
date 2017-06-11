// Copyright 2017.���|�|
// author�����|�|
// smartָ�룺shared_ptr
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    // �����һ��ӵ���߱�����ʱ�������lambda����
    shared_ptr<string> nico_ptr(new string("nico"), [](string* p) {
        cout << "delete " << (*p).c_str() << endl;
        delete p;
    });
    vector<shared_ptr<string>> student;
    student.push_back(nico_ptr);
    student.push_back(nico_ptr);
    student.push_back(nico_ptr);

    // nico nico nico
    for (auto ptr : student)
    {
        cout << (*ptr).c_str() << " ";
    }
    cout << endl;

    nico_ptr->replace(0, 1, "N");
    // Nico Nico Nico
    for (auto ptr : student)
    {
        cout << (*ptr).c_str() << " ";
    }
    cout << endl;

    cout << "use count: " << student[0].use_count() << endl;  // 4

    // ����
    shared_ptr<int> p(new int[5], [](int* p) {
        delete[] p;
    });

    return 0;
}
