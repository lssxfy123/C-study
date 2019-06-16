// Copyright 2019.刘珅珅
// author：刘珅珅
// 数组划分
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int partitionArray(vector<int> &nums, int k) {
    // write your code here
    if (nums.size() == 0)
    {
        return 0;
    }

    int first_max_index = -1;  // 第一个大于等于k的位置
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] >= k && first_max_index < 0)
        {
            first_max_index = i;
        }

        if (first_max_index >=0 && nums[i] < k)
        {
            swap(nums[i], nums[first_max_index]);
            ++first_max_index;
            if (first_max_index == nums.size())
            {
                break;
            }
        }
    }

    if (first_max_index < 0)
    {
        return nums.size();
    }
    return first_max_index;
    
}

int main(int argc, char* argv[])
{
    vector<int> v{ 3, 2, 2, 1 };
    cout << partitionArray(v, 2) << endl;
    PrintElements(v);
    return 0;
}
