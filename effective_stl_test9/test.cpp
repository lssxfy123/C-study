// Copyright 2017.���|�|
// author�����|�|
// map��ooperator[]��insert
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

// ������Ч�Ĳ�������
template<typename MapType,
                typename KeyArgType,
                typename ValueArgType>
typename MapType::iterator
EffectiveAddOrUpdate(MapType& m, const KeyArgType& k, const ValueArgType& v)
{
    // ʹ��typename�����﷨�Ķ�����
    // ָ��MapType::iterator�����ͣ���
    // ���Ǿ�̬����
    // ���ҵ�һ��keyֵ���ڻ����k��Ԫ�ز������������
    typename MapType::iterator lb = m.lower_bound(k);

    // ��ֵk����
    if (lb != m.end() &&
        !(m.key_comp()(k, lb->first)))
    {
        lb->second = v;
        return lb;
    }
    else  // ��ֵk������
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
