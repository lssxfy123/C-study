// Copyright 2015.Áõ«|«|
// author£ºÁõ«|«|
// ¶þ·ÖËÑË÷

#include <iostream>
#include <vector>
using namespace std;

#define NOT_FOUND -1

template<class T>
int BinarySearch(const vector<T>& array, const T& X)
{
    int low = 0;
    int high = array.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (array[mid] < X)
        {
            low = mid + 1;
        }else if (array[mid] > X)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }

    return NOT_FOUND;
}

int main(int argc, char* argv[])
{
    return 0;
}
