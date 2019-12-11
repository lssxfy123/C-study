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

// 114.不同的路径
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

// 115.不同的路径II
int uniquePaths2(vector<vector<int>>& obstacleGrid) {
    // write your code here
    int m = obstacleGrid.size();
    if (m <= 0)
    {
        return 0;
    }

    int n = obstacleGrid[0].size();
    if (n <= 0)
    {
        return 0;
    }

    if (obstacleGrid[0][0] == 1)
    {
        return 0;
    }

    vector<vector<int>> grid;
    bool flag = true;
    for (int i = 0; i < m; ++i)
    {
        vector<int> tmp(n, 0);
        if (obstacleGrid[i][0] == 0 && flag)
        {
            tmp[0] = 1;
        }
        else
        {
            // 如果第1列中有障碍，则障碍之后的grid[i][0]肯定为0
            // 因为不可能从上面想下走
            flag = false;
        }
        
        grid.push_back(tmp);
        bool flag1 = true;
        for (int j = 1; j < n; ++j)
        {
            if (i == 0)
            {
                if (obstacleGrid[i][j] == 0 && flag1)
                {
                    grid[i][j] = 1;
                }
                else
                {
                    // 如果第1行中有障碍，则障碍之后的grid[0][j]肯定为0
                    // 因为不可能从左面向右走
                    flag1 = false;
                }
            }
            else
            {
                if (obstacleGrid[i][j] == 0)
                {
                    grid[i][j] = (grid[i][j - 1] + grid[i - 1][j]);
                }
            }
        }

    }
    return grid[m - 1][n - 1];
}

int main(int argc, char* argv[])
{
    //cout << uniquePaths1(8, 68) << endl;
    vector<vector<int>> vec{ {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
    vector<vector<int>> vec1{ { 0, 0},{ 0, 0},{ 0, 0 }, {1, 0}, {0, 0} };
    vector<vector<int>> vec2{ {0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0} };
    cout << uniquePaths2(vec) << endl;
    cout << uniquePaths2(vec1) << endl;
    cout << uniquePaths2(vec2) << endl;

    return 0;
}
