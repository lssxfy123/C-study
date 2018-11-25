// Copyright 2018.刘珅珅
// author：刘珅珅
// 最小路径和
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int GetMinValue(int x, int y, vector<vector<int>> &grid)
{
    vector<int> tmp;
    if (x - 1 >= 0)
    {
        tmp.push_back(GetMinValue(x - 1, y, grid));
    }

    //if (x + 1 < rows)
    //{
    //    tmp.push_back(GetMinValue(x + 1, y));
    //}

    if (y - 1 >= 0)
    {
        tmp.push_back(GetMinValue(x, y - 1, grid));
    }

    //if (y + 1 < colums)
    //{
    //    tmp.push_back(GetMinValue(x, y + 1));
    //}

    if (tmp.size() > 0)
    {
        return *min_element(tmp.begin(), tmp.end()) + grid[x][y];
    }
    return grid[x][y];
}

int minPathSum(vector<vector<int>> &grid) {
    // write your code here
    int rows = grid.size();
    if (rows == 0)
    {
        return 0;
    }
    int colums = grid[0].size();
    if (colums == 0)
    {
        return 0;
    }

    int sum = GetMinValue(rows - 1, colums - 1, grid);
    return sum;
}

// 动态规划
// 状态转移方程S[i][j] = min(S[i - 1][j], S[i][j - 1]) + grid[i][j]
int minPathSum1(vector<vector<int>> &grid) {
    // write your code here
    int rows = grid.size();
    if (rows == 0)
    {
        return 0;
    }
    int colums = grid[0].size();
    if (colums == 0)
    {
        return 0;
    }

    vector<vector<int>> dp = grid;

    // 第1列，只能从上向下走
    for (int i = 1; i < rows; ++i)
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // 第1行，只能从左向右走
    for (int j = 1; j < colums; ++j)
    {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < rows; ++i)
    {
        for (int j = 1; j < colums; ++j)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[rows - 1][colums - 1];
}

int main(int argc, char* argv[])
{
    vector<int> a1{ 6, 5, 3, 3, 7, 9, 6, 8, 1, 4, 8, 3 };
    vector<int> a2{ 7, 6, 6, 9, 8, 6, 7, 5, 3, 0, 9, 8 };
    vector<int> a3{ 7, 0, 6, 9, 9, 0, 3, 7, 7, 9, 1, 7 };
    vector<int> a4{ 8, 9, 5, 2, 3, 5, 5, 2, 2, 2, 3, 2 };
    vector<int> a5{ 0, 0, 8, 5, 0, 9, 6, 8, 0, 2, 9, 9 };
    vector<int> a6{ 2, 4, 7, 2, 5, 0, 9, 4, 9, 6, 8, 4 };
    vector<int> a7{ 2, 3, 6, 6, 7, 0, 8, 0, 0, 6, 7, 3 };
    vector<int> a8{ 6, 3, 3, 8, 6, 2, 7, 0, 8, 6, 2, 4 };
    vector<int> a9{ 6, 1, 0, 7, 0, 8, 1, 2, 3, 0, 0, 1 };
    vector<int> a10{ 0, 0, 1, 2, 9, 0, 5, 5, 4, 8, 5, 0 };
    vector<int> a11{ 2, 2, 2, 1, 1, 5, 7, 9, 8, 7, 7, 8 };
    vector<int> a12{ 5, 0, 2, 8, 0, 4, 1, 2, 5, 4, 7, 4 };
    vector<int> a13{ 5, 2, 1, 9, 3, 6, 1, 5, 0, 3, 8, 1 };
    vector<vector<int>> grid;
    grid.push_back(a1);
    grid.push_back(a2);
    grid.push_back(a3);
    grid.push_back(a4);
    grid.push_back(a5);
    grid.push_back(a6);
    grid.push_back(a7);
    grid.push_back(a8);
    grid.push_back(a9);
    grid.push_back(a10);
    grid.push_back(a11);
    grid.push_back(a12);
    grid.push_back(a13);
    int sum = minPathSum(grid);
    cout << "sum = " << sum << endl;
    return 0;
}
