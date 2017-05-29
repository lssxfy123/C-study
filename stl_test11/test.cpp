// Copyright 2017.���|�|
// author�����|�|
// C++11 ����������
#include <iostream>
#include <map>
using namespace std;

int main(int argc, char* argv[])
{
    map<string, float> coll;
    coll.insert(pair<string, float>("abc", 4));
    coll["bcd"] = 5;

    // ͨ��decltype��ȡ����
    typedef decltype(coll.begin()) map_type;
    for (map_type i = coll.begin(); i != coll.end(); ++i)
    {
        cout << (*i).first.c_str() << " " << (*i).second << endl;
    }

    // ��scoped enum
    enum Color
    {
        yellow,
        green
    };

    // auto yellow = false;  // error���ض���ö����
    Color c = Color::green;
    if (c < 14.5)  // ok��c������ʽת��Ϊ����
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
    //if (c1 < 14.5)  // error��c1������ʽת��Ϊ����
    //{
    //}
    return 0;
}
