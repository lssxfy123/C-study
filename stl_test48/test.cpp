// Copyright 2017.���|�|
// author�����|�|
// ������set��multiset
#include <algorithm>
#include <functional>
#include <set>
#include <iostream>
#include <iterator>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    set<int> coll1;
    coll1.insert(1);
    coll1.insert(2);
    coll1.insert(4);
    coll1.insert(5);
    coll1.insert(6);

    // ���ص�1�����԰���ֵΪ3��Ԫ�ص�λ��
    cout << "lower_bound(3): " << *coll1.lower_bound(3) << endl;
    // �������һ�����԰���ֵΪ3��Ԫ�ص�λ��
    cout << "upper_bound(3): " << *coll1.upper_bound(3) << endl;
    // ���ص�1�������1�����԰���ֵΪ3��Ԫ�ص�����
    cout << "equal_range(3): " << *coll1.equal_range(3).first 
        << "  " << *coll1.equal_range(3).second << endl;

    cout << endl;
    cout << "lower_bound(5): " << *coll1.lower_bound(5) << endl;
    cout << "upper_bound(5): " << *coll1.upper_bound(5) << endl;
    cout << "equal_range(5): " << *coll1.equal_range(5).first
        << "  " << *coll1.equal_range(5).second << endl;

    cout << endl;

    // �Ӵ�С����
    set<int, greater<int>> coll2;
    coll2.insert({4, 3, 5, 1, 6, 2});
    for (auto elem : coll2)
    {
        cout << elem << ' ';
    }
    cout << endl;
    auto status = coll2.insert(4);
    if (status.second)
    {
        cout << "4 inserted as element " << distance(coll2.begin(), status.first) + 1 << endl;
    }
    else {
        cout << "4 already exists" << endl;
    }

    // ��С��������
    set<int> coll3(coll2.cbegin(), coll2.cend());
    copy(coll3.cbegin(), coll3.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
    // ɾ���ӿ�ͷ��Ԫ��3��λ�����е�Ԫ��
    coll3.erase(coll3.begin(), coll3.find(3));

    int num = coll3.erase(5);
    cout << num << " element(s) removed" << endl;
    copy(coll3.cbegin(), coll3.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
