// Copyright 2019.Áõ«|«|
// author£ºÁõ«|«|
// Ö÷ÔªËØIII
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int threeSumClosest(vector<int> &numbers, int target) {
    // write your code here
    int result = INT_MAX;
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size() - 2; ++i)
    {
        int left = i + 1;
        int right = numbers.size() - 1;
        while (left < right)
        {
            int sum = numbers[i] + numbers[left] + numbers[right];
            if (sum == target)
            {
                return target;
            }
            else
            {
                result = abs(result - target) > abs(target - sum) ? sum : result;
                if (sum < target)
                {
                    ++left;
                }
                else
                {
                    --right;
                }
            }
        }
    }
    return result;
}

int main(int argc, char* argv[])
{
    vector<int> vec{ 2,7,11,15 };
    cout << threeSumClosest(vec, 3) << endl;
    cout << threeSumClosest(vec, 20) << endl;
    return 0;
}
