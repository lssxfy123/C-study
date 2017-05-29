// Copyright 2017.刘珅珅
// author：刘珅珅
// C++11 其他新特性
#include <iostream>
#include <map>
using namespace std;

int main(int argc, char* argv[])
{
    map<string, float> coll;
    coll.insert(pair<string, float>("abc", 4));
    coll["bcd"] = 5;

    // 通过decltype获取类型
    typedef decltype(coll.begin()) map_type;
    for (map_type i = coll.begin(); i != coll.end(); ++i)
    {
        cout << (*i).first.c_str() << " " << (*i).second << endl;
    }

    // 非scoped enum
    enum Color
    {
        yellow,
        green
    };

    // auto yellow = false;  // error，重定义枚举数
    Color c = Color::green;
    if (c < 14.5)  // ok，c可以隐式转换为整型
    {
    }

    // scoped enum
    enum  class Color1
    {
        black,
        white
    };
    auto black = false;  // ok
    Color1 c1 = Color1::black;
    //if (c1 < 14.5)  // error，c1不能隐式转换为整型
    //{
    //}
    return 0;
}
