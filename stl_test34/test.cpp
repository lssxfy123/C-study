// Copyright 2017.���|�|
// author�����|�|
// ������������������������
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> coll;

    cout << "���룺" << endl;
    // �������������istream_iterator
    // ��1��istream_iterator�����ӡ���׼���봮��cin��
    // ��ȡ���ݵ�iterator, ͨ��>>��ȡint������, cin >> int
    // ��2��istream_iterator����һ��������������ͬcin��ȡ
    // ������������
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(coll));

    sort(coll.begin(), coll.end());

    cout << "�����" << endl;
    // �������������ostream_iterator
    // unique_copy�������ڵ��ظ�ֵ�����Ƶ�cout
    // "\n"ΪԪ�ؼ�ķָ���
    unique_copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, "\n"));
    return 0; 
}
