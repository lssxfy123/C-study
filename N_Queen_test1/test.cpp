// Copyright 2017.刘珅珅
// author：刘珅珅
// 回溯算法-N皇后问题
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int N = 0;
vector<vector<int> > trace;
vector<vector<string> > result;

bool Check(int row, int column)
{
    // 第1行的任意位置都可以摆放皇后
    if (row == 1) return true;
    int i, j;

    // 判断同一列是否有皇后
    // row - 2的原因是row, column均为实际的行，列
    // 而记录遍历轨迹的trace从0开始
    // 只需要判断之前行同一列，因为是逐行摆放皇后
    // 例如row = 2时，我们只需要判断trace的第0行的同一列是否有皇后
    for (i = 0; i <= row - 2; ++i)
    {
        if (trace[i][column - 1] == 1)
        {
            return false;
        }
    }

    // 判断(row, column)主对角线是否有皇后
    i = row - 2;
    j = i - (row - column);  // j = column - 2
    while (i >= 0 && j >= 0)
    {
        if (trace[i][j] == 1)
        {
            return false;
        }
        --i;
        --j;
    }

    // 判断(row, column)副对角线是否有皇后
    i = row - 2;
    j = row + column - i - 2;  // j = column
    while (i >= 0 && j <= N - 1)
    {
        if (trace[i][j] == 1)
        {
            return false;
        }
        --i;
        ++j;
    }

    return true;
}

void Output()
{
    vector<string> temp;
    for (int i = 0; i < N; ++i)
    {
        string s;
        for (int j = 0; j < N; ++j)
        {
            // 可以摆放皇后
            if (trace[i][j] == 1)
            {
                s.push_back('Q');
            } else {
                s.push_back('.');
            }
        }
        temp.push_back(s);
    }
    result.push_back(temp);
}

void DFS(int level)
{
    if (level == N)
    {
        // 输出的为皇后的摆放方案
        Output();
    } else {
        // level代表行，i代表列
        for (int i = 0; i < N; ++i)
        {
            // level = 0,i = 0表示在第1行第1列摆放皇后
            // 然后递归调用DFS，判断在第2行某列可以摆放皇后
            // 依次类推在剩下的7行都摆放皇后
            // 接着判断level = 0,i =1时的情况直到level = 0, i = 7结束
            // 从结果result.txt可以看出，每种情况下皇后的摆放数不同
            // level = 0, i = 2时总共有16中摆放方案，第2-7行的皇后的摆放
            // 会有不同的选择，level = 0,i = 2摆放皇后，然后会判断
            // level = 1, i = 0到level = 1, i = 7的情况，还会继续判断
            // level = 2, i = 0到level = 2, i = 7的情况，所以会有不同的摆放方案
            if (Check(level + 1, i + 1))
            {
                // level + 1行i + 1列可以摆放皇后
                trace[level][i] = 1;

                // 递归调用把所有函数的调用都压入栈中
                // 返回时依次从栈中弹出
                DFS(level + 1);
                trace[level][i] = 0;  // 第level + 1行i + 1列不摆放皇后
            }
        }
    }
}

vector<vector<string> > SolveNQueens(int n)
{
    N = n;
    for (int i = 0; i < n; ++i)
    {
        vector<int> array(n, 0);
        trace.push_back(array);
    }
    DFS(0);
    return result;
}

int main(int argc, char* argv[])
{
    SolveNQueens(12);

    cout << "total solution: " << result.size() << endl;

    //ofstream write;
    //write.open("result.txt", ios::out);
    //for (int i = 0; i < result.size(); ++i)
    //{
    //    write << "solution " << i + 1 << endl;
    //    for (int j = 0; j < result[i].size(); ++j)
    //    {
    //        write << result[i][j].c_str() << endl;
    //    }
    //    write << endl;
    //}

    return 0;
}
