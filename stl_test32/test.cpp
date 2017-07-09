// Copyright 2017.���|�|
// author�����|�|
// stl�����㷨��Algorithm
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> coll = { 2, 5, 4, 1, 6, 3};
    auto min_pos = min_element(coll.cbegin(), coll.cend());
    cout << "min: " << *min_pos << endl;
    auto max_pos = max_element(coll.cbegin(), coll.cend());
    cout << "max: " << *max_pos << endl;

    // ����
    sort(coll.begin(), coll.end());
    for (const auto& elem : coll)
    {
        cout << elem << ' ';
    }
    cout << endl;

    // �ҵ���һ��ֵΪ3��Ԫ��
    auto pos3 = find(coll.begin(), coll.end(), 3);

    // ����
    // �����ҵ���ֵΪ3��Ԫ�ؼ�֮���Ԫ�ط���
    reverse(pos3, coll.end());
    for (const auto& elem : coll)
    {
        cout << elem << ' ';
    }
    cout << endl;

    list<int> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> coll2;
    // ��Ҫ��ǰ����ռ�
    coll2.resize(coll1.size());
    // Ĭ�ϵĵ�������copy�Ը��Ƿ�ʽ���ǲ��뷽ʽ����
    copy(coll1.cbegin(), coll1.cend(), coll2.begin());
    for (const auto& elem : coll2)
    {
        cout << elem << ' ';
    }
    cout << endl;
    return 0;
}
