// Copyright 2015.
// author�����|�|
// Լɪ������

#include <iostream>
#include <list>

using namespace std;

// �Ż���Լɪ���������
void Josephus(int m, int n)
{
    list<int> L;  // Լɪ������
    list<int>::iterator itr;
    for (int i = 1; i <= n; ++i)
    {
        L.push_back(i);
    }

    itr = L.begin();

    for (int i = 0; i != n; ++i)
    {
        m = m % n;

        // Լɪ��������Ż�
        // ���mС��n/2����������ǰ�ƶ�
        // ���m����n/2������������ƶ����������Լ����ƶ�����
        if (m <= n / 2)  // ��ǰ����
        {
            for (int j = 0;j < m; ++j)
            {
                ++itr;
                if (itr == L.end())
                {
                    itr = L.begin();
                }
            }
        }
        else {  // ��󴫵�
            for (int j = 0; j < m; ++j)
            {
                if (itr == L.begin())
                {
                    itr = --L.end();
                }
                else {
                    --itr;
                }
            }
        }

        cout << *itr << ",";
        itr = L.erase(itr);

        if (itr == L.end())
        {
            itr = L.begin();
        }
    }

    cout << endl;
}

// һ��Լɪ���������
void Josephus1(int m, int n)
{
    list<int> L;  // Լɪ������
    list<int>::iterator itr;
    for (int i = 1; i <= n; ++i)
    {
        L.push_back(i);
    }

    itr = L.begin();

    for (int i = 0; i != n; ++i)
    {
        m = m % n;
        for (int j = 0;j < m; ++j)
        {
            ++itr;
            if (itr == L.end())
            {
                itr = L.begin();
            }
        }

        cout << *itr << ",";
        itr = L.erase(itr);
        if (itr == L.end())
        {
            itr = L.begin();
        }
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    int m = 4;
    int n = 8;

    Josephus(m, n);
    Josephus1(m, n);
    return 0;
}
