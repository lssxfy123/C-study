// Copyright 2017.刘珅珅
// author：刘珅珅
// 回溯算法-八皇后问题
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int total;
int vis[3][15];

void Search(int cur)
{
    int i, j;
    if (cur == 8)
    {
        ++total;
    } else {
        for (i = 0; i < 8; ++i)
        {
            if (!vis[0][i] && !vis[1][cur - i + 8]
            && !vis[2][cur + i])
            {
                vis[0][i] = 1;
                vis[1][cur - i + 8] = 1;
                vis[2][cur + i] = 1;
                Search(cur + 1);
                vis[0][i] = 0;
                vis[1][cur - i + 8] = 0;
                vis[2][cur + i] = 0;
            }
        }
    }
}


int main(int argc, char* argv[])
{
    Search(0);
    cout << total << endl;
    return 0;
}
