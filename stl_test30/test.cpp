// Copyright 2017.刘珅珅
// author：刘珅珅
// stl标准模板库：关联式容器(Container)
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

int main(int argc, char* argv[])
{
    set<string> city{ "Hanover", "Paris" };
    city.insert("London");
    // 插入一个重复的元素，不会有任何效果
    city.insert("Paris");
    for (const auto& elem : city)
    {
        cout << elem.c_str() << " ";
    }
    cout << endl;

    multiset<string> cities{ "Hanover", "Paris" };
    cities.insert("London");
    cities.insert("Paris");  // multiset允许重复
    for (const auto& elem : cities)
    {
        cout << elem.c_str() << " ";
    }
    cout << endl;

    // 第2个key=1不会有效
    map<int, string> coll{ { 5, "tagged" }, { 2, "a" }, { 1, "this" }, {1, "is"} };
    for (const auto& elem : coll)
    {
        cout << elem.first << ": " << elem.second.c_str() << ' ';
    }
    cout << endl;
    // ok，支持[]访问
    string tmp = coll[1];

    // 第2个key=1有效
    multimap<int, string> colls{ { 5, "tagged" }, { 2, "a" }, { 1, "this" }, { 1, "is" } };
    for (const auto& elem : colls)
    {
        cout << elem.first << ": " << elem.second.c_str() << ' ';
    }
    cout << endl;
    // error，不支持[]访问
    //string tmp = colls[1];
    return 0;
}
