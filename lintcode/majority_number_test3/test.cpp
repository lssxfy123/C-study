// Copyright 2019.刘珅珅
// author：刘珅珅
// 主元素III
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include "../../include/print.hpp"
using namespace std;

int majorityNumber(vector<int> &nums, int k) {
    // write your code here
    if (nums.size() == 0 || k <= 0)
    {
        return 0;
    }
    int result = INT_MIN;

    unordered_map<int, int> tmp;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (tmp.count(nums[i]) != 0)
        {
            tmp[nums[i]]++;
        }
        else if (tmp.size() < k)
        {
            tmp[nums[i]] = 1;
        }
        else
        {
            // remove_if不能用于哈希容器
            // remove_if(tmp.begin(), tmp.end(), [](auto elem) { return elem.second == 1; });
            for (auto& elem : tmp)
            {
                elem.second--;
            }

            for (auto itor = begin(tmp); itor != tmp.end();)
            {
                if (itor->second == 0)
                {
                    itor = tmp.erase(itor);
                }
                else
                {
                    ++itor;
                }
            }

            if (tmp.size() < k)
            {
                tmp[nums[i]] = 1;
            }
        }
    }

    for (auto& elem : tmp)
    {
        elem.second = 0;
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        if (tmp.count(nums[i]) != 0)
        {
            tmp[nums[i]]++;
        }
    }

    int max_count = -1;
    for (auto& elem : tmp)
    {
        if (max_count < elem.second)
        {
            max_count = elem.second;
            result = elem.first;
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    vector<int> vec{ 3,1,2,3,2,3,3,4,4,4 };
    int k = 3;
    cout << majorityNumber(vec, k) << endl;
    vector<int> vec1{ 1, 1, 2 };
    cout << majorityNumber(vec1, k) << endl;
    return 0;
}
