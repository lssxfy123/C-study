// Copyright 2017.刘珅珅
// author：刘珅珅
// 容器：map难度拓展
#include <algorithm>
#include <cctype>
#include <map>
#include <iostream>
#include <iomanip>
#include "../include/print.hpp"
using namespace std;

// 运行期定义排序准则
class RuntimeStringCompare
{
public:
    enum compare_mode { normal, nocase };

public:
    RuntimeStringCompare() : mode_(normal)
    {
    }

    RuntimeStringCompare(compare_mode mode) : mode_(mode)
    {}

    bool operator() (const string& s1, const string& s2)
    {
        if (mode_ == normal)
        {
            return s1 < s2;
        }
        else
        {
            // 忽略大小写，按字典序比较
            return lexicographical_compare(s1.begin(), s1.end(),
                                                             s2.begin(), s2.end(), 
                                                             nocase_compare);
        }
    }

private:
    static bool nocase_compare(char c1, char c2)
    {
        return toupper(c1) < toupper(c2);
    }



private:
    const compare_mode mode_;

};

typedef map<string, string, RuntimeStringCompare> StringMap;
void FillAndPrint(StringMap& coll);

int main(int argc, char* argv[])
{
    StringMap coll1;
    FillAndPrint(coll1);

    RuntimeStringCompare ignorecase(RuntimeStringCompare::nocase);
    cout << "ingore case: " << endl;
    // 在构造函数参数中定义排序准则
    // 忽略大小写后，coll2将会少一个元素
    StringMap coll2(ignorecase);
    FillAndPrint(coll2);
    return 0;
}

void FillAndPrint(StringMap& coll)
{
    coll["Deutschland"] = "Germany";
    coll["deutsch"] = "German";
    coll["Haken"] = "snag";
    coll["arbeiten"] = "work";
    coll["Hund"] = "dog";
    coll["gehen"] = "go";
    coll["Unternehmen"] = "enterprise";
    coll["unternehmen"] = "undertake";
    coll["gehen"] = "walk";
    coll["Bestatter"] = "undertaker";
    cout.setf(ios::left, ios::adjustfield);
    for (const auto& elem : coll)
    {
        cout << setw(15) << elem.first <<
            " " << elem.second << endl;
    }
    cout << endl;
}
