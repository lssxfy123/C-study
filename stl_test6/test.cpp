// Copyright 2017.���|�|
// author�����|�|
// move�ƶ�����
#include <iostream>
#include <vector>
using namespace std;

class P
{
public:
    P()
    {
        cout << "���캯��" << endl;
    }

    P(const P& p)
    {
        cout << "�������캯��" << endl;
    }

    ~P()
    {
        cout << "��������" << endl;
    }
};

int main(int argc, char* argv[])
{
    vector<P> vec_p;
    P p1;

    // vector�����ڲ���p1ʱ
    // �����ȵ��ÿ������캯��
    // ����һ����ʱ�������������
    vec_p.push_back(p1);
    return 0;
}
