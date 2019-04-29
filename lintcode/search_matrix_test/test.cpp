// Copyright 2018.Áõ«|«|
// author£ºÁõ«|«|
// ËÑË÷¶þÎ¬¾ØÕó
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

bool searchMatrix1(vector<vector<int>> &matrix, int target) {
	int n = matrix.size();
	if (n == 0) {
		return false;
	}

	int m = matrix[0].size();
	if (m == 0) {
		return false;
	}

	int start = 0, end = n * m - 1;
	while (start + 1 < end) {
		int mid = start + (end - start) / 2;
		int row = mid / m;
		int col = mid % m;

		if (matrix[row][col] < target) {
			start = mid;
		}
		else {
			end = mid;
		}
	}

	if (matrix[start / m][start % m] == target) {
		return true;
	}

	if (matrix[end / m][end % m] == target) {
		return true;
	}

	return false;
}

int main(int argc, char* argv[])
{
    return 0;
}
