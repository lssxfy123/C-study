// Copyright 2017.���|�|
// author�����|�|
// reverse_iterator�Ĳ����ɾ��
#include <iostream>
#include <vector>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int>::reverse_iterator r_iter = find(v.rbegin(), v.rend(), 3);

    // ����������Ĳ���
    // ������insert()������reverse_iterator��
    // ������Ҫͨ��base()ת����
    // insert()���Ԫ�ز��뵽������ָ���Ԫ�ص�ǰ��
    // �ڷ������ʱ��99�������3��ǰ�棬�������ʱ
    // ��������4��ǰ�棬��������ʱ��r_iter��r_iter.base()�ȼ�
    v.insert(r_iter.base(), 99);
    PrintElements(v, "Insert by reverse_iterator: ");
    cout << endl;

    // �����������ɾ��
    // erase()ͬ��������reverse_iterator
    // ɾ��ʱr_iterָ���Ԫ��ʱ��r_iter��r_iter.base()���ٵȼ�
    // r_iter��(++r_iter).base()�ȼ�
    r_iter = find(v.rbegin(), v.rend(), 3);  // ֮ǰ��r_iter��Ϊ�������ʧЧ
    v.erase((++r_iter).base());
    PrintElements(v, "Erase by reverse_iterator: ");
    return 0;
}
