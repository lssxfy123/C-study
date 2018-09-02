// Copyright 2018.Áõ«|«|
// author£ºÁõ«|«|
// ËÑË÷¶şÎ¬¾ØÕó
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    // write your code here
    size_t m = matrix.size();
    if (m == 0)
    {
        return false;
    }

    int index = -1;
    for (size_t i = 0; i < m; ++i)
    {
        int min = matrix[i][0];
        int max = matrix[i][matrix[i].size() - 1];
        if ( target >= min && target <= max)
        {
            index = i;
            break;
        }
    }

    if (index < 0)
    {
        return false;
    }

    for (size_t i = 0; i < matrix[index].size(); ++i)
    {
        if (target == matrix[index][i])
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    return 0;
}
