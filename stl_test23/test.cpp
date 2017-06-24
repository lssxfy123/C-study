// Copyright 2017.���|�|
// author�����|�|
// ����������min, max, minmax
#include <algorithm>
#include <iostream>
using namespace std;

// ͨ��ָ���ֵ�Ƚ�����ָ���С
bool int_ptr_less(int* a, int* b)
{
    return *a < *b;
}

int main(int argc, char* argv[])
{
    int x = 17;
    int y = 42;
    int z = 33;
    int tmp = 99;
    int* ptr_x = &x;
    cout << "pointer x " << ptr_x << endl;
    int* ptr_y = &y;
    cout << "pointer y " << ptr_y << endl;
    int* ptr_z = &z;
    cout << "pointer z " << ptr_z << endl;

    // ����ʵ�ε�max,min,minmax���ص�������
    // �ڱ����з��ص���ָ������ã�������const����
    // ptr_max���õ���ptr_y�����޸���ptr_y��ָ���
    // ptr_max��ָ��Ҳ��֮�޸�
    int* const& ptr_max = std::max(ptr_x, ptr_y, int_ptr_less);
    cout << "pointer max " << ptr_max << endl;
    ptr_y = &tmp;
    cout << "pointer y " << ptr_y << endl;
    cout << "pointer max " << ptr_max << endl;

    // ʵ��Ϊ��ֵ�б�汾���ص��ǱȽ�ֵ�Ŀ���
    int* ptr_min = std::min({ ptr_x, ptr_y }, int_ptr_less);

    pair<int*, int*> extremes = minmax({ ptr_x, ptr_y, ptr_z }, int_ptr_less);
    // firstΪ��Сֵ
    cout << "pointer min " << extremes.first << endl;
    // secondΪ���ֵ
    cout << "pointer max " << extremes.second << endl;

    int i = 0;
    long k = 9;
    // std::max(i, k);  // error��ʵ�����Ͳ�һ��
    std::max<long>(i, k);  // ok������templateʵ�����ͣ�ȷ����������
    return 0;
}
