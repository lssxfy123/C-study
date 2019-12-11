// Copyright 2018.���|�|
// author�����|�|
// ��ͬ��·��
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

void DFS(int x, int y, int m, int n, int& paths)
{
    if (x == m - 1 && y == n - 1)  // ���ﲻ��ֱ�ӷ��أ���Ϊ��ֻ���ҵ�һ��·��
    {
        ++paths;
    }

    if (x + 1 < m)  // ������
    {
        DFS(x + 1, y, m, n, paths);
    }


    if (y + 1 < n)  // ������
    {
        DFS(x, y + 1, m, n, paths);
    }
}

// �ݹ�ķ�ʽ����ʱ��̫��
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

// 114.��ͬ��·��
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

// 115.��ͬ��·��II
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
            // �����1�������ϰ������ϰ�֮���grid[i][0]�϶�Ϊ0
            // ��Ϊ�����ܴ�����������
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
                    // �����1�������ϰ������ϰ�֮���grid[0][j]�϶�Ϊ0
                    // ��Ϊ�����ܴ�����������
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
