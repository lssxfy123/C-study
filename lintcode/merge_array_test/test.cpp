// Copyright 2018.刘珅珅
// author：刘珅珅
// 合并两个有序数组
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
    // write your code here
    if (A.size() == 0)
    {
        return B;
    }

    if (B.size() == 0)
    {
        return A;
    }

    int max_A = A[A.size() - 1];
    int min_A = A[0];
    int max_B = B[B.size() - 1];
    int min_B = B[0];
    if (max_A <= min_B)
    {
        if (A.size() > B.size())
        {
            A.swap(B);
        }

        for (vector<int>::reverse_iterator itor = A.rbegin(); itor < A.rend(); ++itor)
        {
            B.insert(B.begin(), *itor);
        }
        return B;
    }

    if (min_A >= max_B)
    {
        if (A.size() > B.size())
        {
            A.swap(B);
        }

        for (vector<int>::iterator itor = A.begin(); itor < A.end(); ++itor)
        {
            B.insert(B.end(), *itor);
        }
        return B;
    }

    if (A.size() > B.size())
    {
        A.swap(B);
    }

    for (vector<int>::iterator itor = B.begin(); itor < B.end(); ++itor)
    {
        if (A.size() > 0 && *itor > A[0])
        {
            itor = B.insert(itor, A[0]);
            A.erase(A.begin());
        }

        if (A.size() == 0)
        {
            break;
        }
    }

    if (A.size() > 0)
    {
        for (vector<int>::iterator itor = A.begin(); itor < A.end(); ++itor)
        {
            B.insert(B.end(), *itor);
        }
    }
    return B;
}

int main(int argc, char* argv[])
{
    vector<int> A = { 1, 5, 6, 7 };
    vector<int> B = { 1, 8, 9 };
    A = mergeSortedArray(A, B);
    for (vector<int>::iterator itor = A.begin(); itor < A.end(); ++itor)
    {
        cout << *itor << ",";
    }
    cout << endl;
    return 0;
}
