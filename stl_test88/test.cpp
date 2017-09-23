// Copyright 2017.���|�|
// author�����|�|
// �����
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
int main(int argc, char* argv[])
{
    // ÿ�����г���
    // �õ����������һ��
    random_device rd;

    // ����
    // create default engine as source
    // of randomness
    default_random_engine dre(rd());

    // ���Էֲ�
    // use engine to generate integral
    // numbers between 10 and 20(both included)
    uniform_int_distribution<int> di(10, 20);
    for (int i = 0; i < 20; ++i)
    {
        cout << di(dre) << " ";
    }
    cout << endl;
    cout << endl;

    // ���Էֲ�
    // use engine to generate floating-point
    // numbers between 10.0 and 20.0
    // (10.0 included, 20.0 not included)
    uniform_real_distribution<double> dr(10, 20);
    for (int i = 0; i < 8; ++i)
    {
        cout << dr(dre) << " ";
    }
    cout << endl;
    cout << endl;

    // ϴ��
    // use engine to shuffle elements
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    shuffle(v.begin(), v.end(), dre);
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // ����ϴ�ƽ����ͬ
    shuffle(v.begin(), v.end(), dre);
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    return 0;
}
