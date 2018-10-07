// Copyright 2018.Áõ«|«|
// author£ºÁõ«|«|
// ²éÕÒ²åÈëÎ»ÖÃ
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int searchInsert(vector<int> &A, int target) {
    // write your code here
    int result = 0;
    if (A.size() == 0)
    {
        return result;
    }

    int low = 0;
    int high = A.size() - 1;
    int length = A.size();

    if (target <= A[0])
    {
        return 0;
    }

    if (target >= A[high])
    {
        return target == A[high] ? high : high + 1;
    }

    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (A[middle] == target)
        {
            return middle;
        }

        if (A[middle] > target)
        {
            if ((middle - 1) >= 0 && A[middle - 1] <= target)
            {
                return A[middle - 1] == target ? middle - 1 : middle;
            }
            else
            {
                high = middle - 1;
            }
        }

        if (A[middle] < target)
        {
            if ((middle + 1) < length && A[middle + 1] >= target)
            {
                return middle + 1;
            }
            else
            {
                low = middle + 1;
            }
        }
    }
    return result;
}

int main(int argc, char* argv[])
{
    vector<int> A{ 1, 3, 5, 6 };
    cout << searchInsert(A, 5) << endl;
    cout << searchInsert(A, 2) << endl;
    cout << searchInsert(A, 7) << endl;
    cout << searchInsert(A, 0) << endl;
    return 0;
}
