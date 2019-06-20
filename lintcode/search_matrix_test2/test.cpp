// Copyright 2019.Áõ«|«|
// author£ºÁõ«|«|
// ËÑË÷¶þÎ¬¾ØÕó
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int searchMatrix(vector<vector<int>> &matrix, int target) {
    // write your code here
    if (matrix.size() == 0 || matrix[0].size() == 0)
    {
        return 0;
    }
    int count = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    int column_index = n;
    for (int i = 0; i < m; ++i)
    {
        if (matrix[i][0] <= target && matrix[i][n - 1] >= target)
        {
            for (int j = 0; j < column_index; ++j)
            {
                if (matrix[i][j] == target)
                {
                    ++count;
                    column_index = j;
                    break;
                }
            }
        }
    }
    return count;
}

int main(int argc, char* argv[])
{
    return 0;
}
