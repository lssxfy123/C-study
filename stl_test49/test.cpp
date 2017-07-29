// Copyright 2017.刘珅珅
// author：刘珅珅
// 容器：map和multimap
#include <algorithm>
#include <map>
#include <iostream>
#include <iomanip>
#include "../include/print.hpp"
using namespace std;

namespace MyLib {
    // 替换map容器的key
    template<typename Cont>
    inline bool ReplaceKey(Cont& c,
                                        const typename Cont::key_type& old_key,
                                        const typename Cont::key_type& new_key)
    {
        typename Cont::iterator pos;
        pos = c.find(old_key);
        if (pos != c.end())
        {
            c.insert(typename Cont::value_type(new_key, pos->second));
            c.erase(pos);
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main(int argc, char* argv[])
{
    map<string, int> c{ { "old_key", 8 }, {"hello", 9} };
    cout << "original:    " << endl;
    for (auto& elem : c)
    {
        cout << elem.first << " : " << elem.second << endl;
    }
    MyLib::ReplaceKey(c, "old_key", "new_key");
    cout << endl;
    cout << "replace key:   " << endl;
    for (auto& elem : c)
    {
        cout << elem.first << " : " << elem.second << endl;
    }

    cout << endl;
    map<string, double> coll{ { "tim", 9.9 }, {"struppi", 11.77} };
    for_each(coll.begin(), coll.end(),
        [](pair<const string, double>& elem) {
        elem.second *= elem.second;
    });

    for_each(coll.cbegin(), coll.cend(),
        [](const map<string, double>::value_type& elem) {
        cout << elem.first << " : " << elem.second << endl;
    });

    typedef map<string, float> StringFloatMap;
    StringFloatMap stocks;
    stocks["BASF"] = 369.5f;
    stocks["VW"] = 413.5f;
    stocks["Daimler"] = 819.0f;
    stocks["BMW"] = 834.0f;
    stocks["Siemens"] = 842.2f;
    StringFloatMap::iterator pos;
    cout << left;  // 输出左对齐
    for (pos = stocks.begin(); pos != stocks.end(); ++pos)
    {
        cout << "stock: " << setw(12) << pos->first
            << "price: " << pos->second << endl;
    }
    cout << endl;

    for (pos = stocks.begin(); pos != stocks.end(); ++pos)
    {
        pos->second *= 2;
    }

    for (pos = stocks.begin(); pos != stocks.end(); ++pos)
    {
        cout << "stock: " << setw(12) << pos->first
            << "price: " << pos->second << endl;
    }
    cout << endl;

    // 替换key
    stocks["Volkswagen"] = stocks["VW"];
    stocks.erase("VW");

    for (pos = stocks.begin(); pos != stocks.end(); ++pos)
    {
        cout << "stock: " << setw(12) << pos->first
            << "price: " << pos->second << endl;
    }
    cout << endl;

    multimap<string, string> dictionary;
    dictionary.insert({ { "day", "Tag" }, { "strange", "fremd" },
    { "car", "Auto" }, { "smart", "elegant" }, { "trait", "Merkmal" }, {"strange", "seltsam"},
    { "smart", "raffiniert" }, { "smart", "klug" }, {"clever", "raffiniert"} });
    cout.setf(ios::left, ios::adjustfield);
    for (const auto& elem : dictionary)
    {
        cout << ' ' << setw(10) << elem.first 
            << elem.second << endl;
    }
    cout << endl;
    cout << "smart: " << endl;
    // 所有key为smart的元素的value
    for (auto p = dictionary.lower_bound("smart"); 
        p != dictionary.upper_bound("smart"); ++p)
    {
        cout << "     " << p->second << endl;
    }
    return 0;
}

