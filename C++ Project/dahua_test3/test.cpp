// Copyright 2017.���|�|
// author�����|�|
// vector��Ϊ�β�
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

int func(std::vector<int> vec)
{ 
    static int k = 2;

    // ���ﶨ��ĵ�����������ע�͵��ĵ���������Ƿ�ת��
    std::vector<int>::reverse_iterator it;

    // �����������һ��Ԫ����ǰ����
    for (it = vec.rbegin(); it != vec.rend(); ++it)
    {
        cout << "*it = " << *it << endl;

        k += (*it % 2 == 0) ? ++*it : (*it)++;
    }

    //std::vector<int>::iterator it;

    //for(it = vec.begin(); it != vec.end(); ++it)
    //{
    //    k += (*it%2== 0) ? ++*it: (*it)++;
    //}
    return k;
}

int main(void)
{ 
    std::vector<int>vec;

    for (int i = 0; i < 4; i++)
    {
        vec.push_back(i);
        cout << func(vec) << " " << endl;
    }

    return 0;
}
