// Copyright 2019.刘珅珅
// author：刘珅珅
// 字符大小写排序
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int search(vector<int> &A, int target) {
    // write your code here
    if (A.size() == 0)
    {
        return -1;
    }

    int result = -1;
    int low = 0;
    int high = A.size() - 1;
    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (A[middle] == target)
        {
            result = middle;
            break;
        }
        else if (A[middle] < target)
        {
            if (A[low] < A[middle])
            {
                // low-middle之间是有序的
                low = middle + 1;
            }
            else
            {
                // low-middle之间有旋转跳变位置
                // middle-high之间是有序的
                if (A[high] < target)
                {
                    // middle-high之间的元素都小于target
                    high = middle - 1;
                }
                else
                {
                    low = middle + 1;
                }
            }
        }
        else  // A[middle] > target
        {
            if (A[low] > A[middle])
            {
                // low-middle之间有旋转跳变位置
                // middle-high之间的元素是有序的，肯定都大于target
                high = middle - 1;
            }
            else
            {
                // low-middle之间是有序的
                if (A[low] > target)
                {
                    // low-middle之间的所有元素都大于target
                    low = middle + 1;
                }
                else
                {
                    high = middle - 1;
                }
            }
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    vector<int> vec{ 0,1,2,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1 };
    cout << search(vec, -9) << endl;
    return 0;
}
