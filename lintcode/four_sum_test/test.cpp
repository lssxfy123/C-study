// Copyright 2019.刘珅珅
// author：刘珅珅
// 四数之和
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

vector<vector<int>> fourSum(vector<int> &numbers, int target) {
    // write your code here
    vector<vector<int>> result;
    if (numbers.size() < 4)
    {
        return result;
    }

    sort(numbers.begin(), numbers.end());
    if (numbers.front() > target)
    {
        return result;
    }

    // 同3数之和类似，要固定两个元素
    for (int i = 0; i < numbers.size() - 3; ++i)
    {
        if (i > 0 && numbers[i] == numbers[i - 1])
        {
            continue;
        }

        for (int j = i + 1; j < numbers.size() - 2; ++j)
        {
            if (j > i + 1 && numbers[j] == numbers[j - 1])
            {
                continue;
            }

            int left = j + 1;
            int right = numbers.size() - 1;
            while (left < right)
            {
                int sum = numbers[i] + numbers[j] + numbers[left] + numbers[right];
                if (sum == target)
                {
                    vector<int> tmp;
                    tmp.push_back(numbers[i]);
                    tmp.push_back(numbers[j]);
                    tmp.push_back(numbers[left]);
                    tmp.push_back(numbers[right]);
                    result.push_back(tmp);
                    ++left;
                    --right;

                    while (left < right && numbers[left] == numbers[left - 1])
                    {
                        ++left;
                    }

                    while (left < right && numbers[right] == numbers[right + 1])
                    {
                        --right;
                    }
                }
                else if (sum < target)
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
}

int main(int argc, char* argv[])
{
    return 0;
}
