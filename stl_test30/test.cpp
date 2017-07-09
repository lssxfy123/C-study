// Copyright 2017.���|�|
// author�����|�|
// stl��׼ģ��⣺����ʽ����(Container)
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

int main(int argc, char* argv[])
{
    set<string> city{ "Hanover", "Paris" };
    city.insert("London");
    // ����һ���ظ���Ԫ�أ��������κ�Ч��
    city.insert("Paris");
    for (const auto& elem : city)
    {
        cout << elem.c_str() << " ";
    }
    cout << endl;

    multiset<string> cities{ "Hanover", "Paris" };
    cities.insert("London");
    cities.insert("Paris");  // multiset�����ظ�
    for (const auto& elem : cities)
    {
        cout << elem.c_str() << " ";
    }
    cout << endl;

    // ��2��key=1������Ч
    map<int, string> coll{ { 5, "tagged" }, { 2, "a" }, { 1, "this" }, {1, "is"} };
    for (const auto& elem : coll)
    {
        cout << elem.first << ": " << elem.second.c_str() << ' ';
    }
    cout << endl;
    // ok��֧��[]����
    string tmp = coll[1];

    // ��2��key=1��Ч
    multimap<int, string> colls{ { 5, "tagged" }, { 2, "a" }, { 1, "this" }, { 1, "is" } };
    for (const auto& elem : colls)
    {
        cout << elem.first << ": " << elem.second.c_str() << ' ';
    }
    cout << endl;
    // error����֧��[]����
    //string tmp = colls[1];
    return 0;
}
