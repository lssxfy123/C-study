// Copyright 2019.Áõ«|«|
// author£ºÁõ«|«|
// ËÑË÷Çø¼ä
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

vector<int> searchRange(vector<int> &A, int target) {
    // write your code here
    vector<int> result(2, -1);
    if (A.size() == 0)
    {
        return result;
    }
    if (target < A.front() || target > A.back())
    {
        return result;
    }

    int low = 0;
    int high = A.size() - 1;
    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (A[middle] == target)
        {
            result[0] = middle;
            result[1] = middle;
            int left = middle - 1;
            int right = middle + 1;
            while (left >= low && A[left] == target)
            {
                result[0] = left;
                --left;
            }

            while (right <= high && A[right] == target)
            {
                result[1] = right;
                ++right;
            }
            return result;
        }
        else if (A[middle] < target)
        {
            low = middle + 1;
        }
        else
        {
            high = middle - 1;
        }
    }
    return result;
}

int main(int argc, char* argv[])
{
    vector<int> vec{ 1 };
    PrintElements(searchRange(vec, 1));
    return 0;
}
