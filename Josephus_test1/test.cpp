// Copyright 2015.
// author：刘珅珅
// 约瑟夫问题

#include <iostream>
#include <list>

using namespace std;

// 优化的约瑟夫问题求解
void Josephus(int m, int n)
{
    list<int> L;  // 约瑟夫链表
    list<int>::iterator itr;
    for (int i = 1; i <= n; ++i)
    {
        L.push_back(i);
    }

    itr = L.begin();

    for (int i = 0; i != n; ++i)
    {
        m = m % n;

        // 约瑟夫问题的优化
        // 如果m小于n/2，迭代器向前移动
        // 如果m大于n/2，迭代器向后移动，这样可以减少移动次数
        if (m <= n / 2)  // 向前传递
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
        else {  // 向后传递
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

// 一般约瑟夫问题求解
void Josephus1(int m, int n)
{
    list<int> L;  // 约瑟夫链表
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
