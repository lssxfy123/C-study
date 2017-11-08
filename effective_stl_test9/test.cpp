// Copyright 2017.刘珅珅
// author：刘珅珅
// map的ooperator[]和insert
#include <iostream>
#include <map>
#include "../include/print.hpp"
using namespace std;

class Widget
{
public:
    Widget()
    {
        cout << "Default Construct Widget " << hex << this << endl;
    }

    Widget(double weight)
    {
        cout << "Construct Widget with double param " << hex << this << endl;
    }

    Widget(const Widget& org)
    {
        cout << "Copy construct Widget " << hex << this << " from " << &org << endl;
    }

    ~Widget()
    {
        cout << "Destruct Widget " << hex << this << endl;
    }

    Widget& operator=(const Widget& org)
    {
        cout << "Operator= Widget " << hex << this << " from " << &org << endl;
        return *this;
    }
};

// 更加有效的插入或更新
template<typename MapType,
                typename KeyArgType,
                typename ValueArgType>
typename MapType::iterator
EffectiveAddOrUpdate(MapType& m, const KeyArgType& k, const ValueArgType& v)
{
    // 使用typename避免语法的二义性
    // 指明MapType::iterator是类型，而
    // 不是静态变量
    // 查找第一个key值大于或等于k的元素并返回其迭代器
    typename MapType::iterator lb = m.lower_bound(k);

    // 键值k存在
    if (lb != m.end() &&
        !(m.key_comp()(k, lb->first)))
    {
        lb->second = v;
        return lb;
    }
    else  // 键值k不存在
    {
        typedef typename MapType::value_type MVT;
        return m.insert(lb, MVT(k, v));
    }
}

int main(int argc, char* argv[])
{
    typedef map<int, Widget> IntWidgetMap;

    map<int, Widget> map1;
    
    cout << "operator[] add element" << endl;
    map1[1] = 1.5;
    cout << "operator[] end" << endl;

    cout << endl;

    cout << "insert() add element" << endl;
    map1.insert(IntWidgetMap::value_type(2, 1.8));
    cout << "insert() end" <<endl;
    cout << endl;

    cout << "operator[] update element" << endl;
    map1[1] = 2.5;
    cout << "operator[] end" << endl;
    cout << endl;

    EffectiveAddOrUpdate(map1, 1, 1.2);
    return 0;
}
