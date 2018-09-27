// Copyright 2018.刘珅珅
// author：刘珅珅
// 主元素查找：出现的次数严格大于数组元素的二分之1
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int majorityNumber(vector<int> &nums) {
    // write your code here
    int majorty_number = nums[0];
    int count = 1;

    // 查找当前出现最多的元素
    // 默认nums中存在主元素，出现
    // 次数最多的就是主元素
    for (int i = 1; i < nums.size(); ++i)
    {
        count += nums[i] == majorty_number ? 1 : -1;
        if (count == 0)  // count为0表示0-i范围内，该元素不为主元素
        {
            majorty_number = nums[i];
            count = 1;
        }
    }
    return majorty_number;
}

int main(int argc, char* argv[])
{
    vector<int> nums{1, 3, 5, 6, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1 };
    cout << majorityNumber(nums) << endl;
    return 0;
}
