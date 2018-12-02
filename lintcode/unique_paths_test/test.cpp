// Copyright 2018.刘珅珅
// author：刘珅珅
// 不同的路径
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

void DFS(int x, int y, int m, int n, int& paths)
{
    if (x == m - 1 && y == n - 1)  // 这里不能直接返回，因为这只是找到一条路径
    {
        ++paths;
    }

    if (x + 1 < m)  // 向下走
    {
        DFS(x + 1, y, m, n, paths);
    }


    if (y + 1 < n)  // 向右走
    {
        DFS(x, y + 1, m, n, paths);
    }
}

// 递归的方式运行时间太慢
int uniquePaths(int m, int n) {
    // write your code here
    if (m == 0 || n == 0)
    {
        return 0;
    }
    int paths = 0;
    DFS(0, 0, m, n, paths);
    return paths;
}

int uniquePaths1(int m, int n) {
    // write your code here
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (m == 1 || n == 1)
    {
        return 1;
    }

    vector<vector<int>> grid;
    for (int i = 0; i < m; ++i)
    {
        vector<int> tmp(n, 0);
        tmp[0] = 1;
        grid.push_back(tmp);
        for (int j = 1; j < n; ++j)
        {
            if (i == 0)
            {
                grid[i][j] = 1;
            }
            else
            {
                grid[i][j] = (grid[i][j - 1] + grid[i - 1][j]);
            }
        }

    }
    return grid[m - 1][n - 1];
}

int main(int argc, char* argv[])
{
    cout << uniquePaths1(8, 68) << endl;
    return 0;
}
