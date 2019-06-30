// Copyright 2019.���|�|
// author�����|�|
// �ַ���Сд����
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
                // low-middle֮���������
                low = middle + 1;
            }
            else
            {
                // low-middle֮������ת����λ��
                // middle-high֮���������
                if (A[high] < target)
                {
                    // middle-high֮���Ԫ�ض�С��target
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
                // low-middle֮������ת����λ��
                // middle-high֮���Ԫ��������ģ��϶�������target
                high = middle - 1;
            }
            else
            {
                // low-middle֮���������
                if (A[low] > target)
                {
                    // low-middle֮�������Ԫ�ض�����target
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
