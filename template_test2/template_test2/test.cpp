// Copyright 2015.刘珅珅
// author：刘珅珅
// 函数模板的测试：使用函数对象

#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename Object, typename Comparator>
const Object& FindMax(const vector<Object>& array, Comparator isLessThan)
{
    int max_index = 0;

    for (int i = 0; i != array.size(); ++i)
    {
        if (isLessThan(array[max_index], array[i]))
        {
            max_index = i;
        }
    }

    return array[max_index];
}

template <typename Object>
const Object& FindMax(const vector<Object>& array)
{
    return FindMax(array, less<Object>());
}

class CaseInsensitiveCompare
{
public:
    //重载函数调用操作符()
    bool operator()(const string& lhs, const string& rhs) const
    {
        return _stricmp(lhs.c_str(), rhs.c_str()) < 0;
    }
};

int main(int argc, char* argv[])
{
    vector<string> array(3);
    array[0] = "ZEBRA";
    array[1] = "alligator";
    array[2] = "crocodile";

    cout << FindMax(array, CaseInsensitiveCompare()) << endl;
    cout << FindMax(array) << endl;
    return 0;
}
