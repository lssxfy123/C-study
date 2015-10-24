// Copyright 2015.���|�|
// author�����|�|
// �Զ���vector����

#include <iostream>
#include <vector>
using namespace std;

#include "Vector.hpp"

int main(int argc, char* argv[])
{
    //Vector<int> vector1;
    //vector1.push_back(1);
    //vector1.push_back(2);
    //vector1.push_back(3);
    //try
    //{
    //    cout << vector1[3] << endl;
    //}
    //catch (runtime_error& e)
    //{
    //    cout << e.what() << endl;
    //}

    Vector<int> array;
    array.push_back(0);
    array.push_back(1);
    array.push_back(2);

    for (Vector<int>::const_iterator itr = array.begin(); itr != array.end(); ++itr)
    {
        cout << *itr << ",";
    }

    cout << endl;

    Vector<int>::iterator itr = array.end();
    itr = array.insert(itr, 3);

    for (Vector<int>::const_iterator itr = array.begin(); itr != array.end(); ++itr)
    {
        cout << *itr << ",";
    }

    cout << endl;

    itr = array.begin();
    array.erase(itr);

    for (Vector<int>::const_iterator itr = array.begin(); itr != array.end(); ++itr)
    {
        cout << *itr << ",";
    }
    cout << endl;

    Vector<int> array1(array);

    for (Vector<int>::const_iterator itr = array.begin(); itr != array.end(); ++itr)
    {
        cout << *itr << ",";
    }
    cout << endl;

    //int a[3] = {1};
    //for (int i = 0; i != 3; ++i)
    //{
    //    cout << a[i] << endl;
    //}

    //// ���Կ�������a[3]������
    //// �����ַ���ڣ���Ҳ��end()�ܹ�ִ�гɹ���ԭ��
    //// ��������a[2]�ĵ�ַ����sizeof(int)�õ�&a[3]
    //cout << &a[2] << endl;  // 0071FB28
    //cout << &a[3] << endl;  // 0071FB2C

    return 0;
}
