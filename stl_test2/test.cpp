// Copyright 2017.���|�|
// author�����|�|
// C++11������1
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    // C++11������������֮��û�˿ո�
    vector<list<int>> vec;

    // ��ָ��
    int* ptr = nullptr;

    auto i = 43;
    cout << typeid(i).name() << endl;  // int

    vector<string> strVec;
    strVec.push_back("start");
    auto begin = strVec.begin();
    cout << typeid(begin).name() << endl;

    // һ���Գ�ʼ������C#�ĸ�ֵ��ʽ����
    int k;  // δ��ʼ��
    int j{};  // ��ʼ��Ϊ0
    int* q{};  // ��ʼ��Ϊnullptr
    cout << j << endl; // 0
    int values[] {1, 2, 3};  // 1,2,3
    vector<int> v{ 2, 3, 5, 7 };
    cout << v.size() << endl;  // 4

    int x1{ 5 };  // x1��ʼ��Ϊ5
    int x2 = 5.3;  // x2Ϊ5�����Ƚ�����

    // һ���Գ�ʼ��{}��������խ��
    // �����Ƚ��ͻ���ֵ�䶯
    //int x3{ 5.3 };  // error

    double d1{ 5 };  // ok
    return 0;
}
