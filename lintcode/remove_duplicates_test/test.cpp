// Copyright 2018.刘珅珅
// author：刘珅珅
// 删除排序数组重复元素
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int removeDuplicates(vector<int> &nums) {
    // write your code here
    if (nums.size() == 0)
    {
        return 0;
    }
    auto begin = nums.begin();
    for (vector<int>::iterator itor = next(begin); itor != nums.end(); )
    {
        if (*itor == *begin)
        {
            itor = nums.erase(itor);
        }
        else
        {
            begin = itor;
            ++itor;
        }
    }
    return nums.size();
}

// 删除重复元素，每个元素只出现一次
int removeDuplicates1(vector<int> &nums) {
    // write your code here
    if (nums.size() == 0)
    {
        return 0;
    }
    int length = 0;
    for (int i = 1; i < nums.size();  ++i)
    {
        // 将数组后面与之前元素不同的元素
        // 向前挪移
        if (nums[length] != nums[i])
        {
            nums[++length] = nums[i];
        }
    }
    int delete_length = nums.size() - (length + 1);
    while (delete_length > 0)
    {
        nums.pop_back();
        --delete_length;
    }
    return length + 1;
}

// 删除重复元素，每个元素最多出现两次
int removeDuplicates2(vector<int> &nums) {
    // write your code here
    if (nums.size() == 0)
    {
        return 0;
    }
    int length = 0;
    int index = 1;
	// 思路是将不同的数字向nums左边移动
	// length为nums最终的长度，之后的都删除
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[length] != nums[i])
        {
            nums[++length] = nums[i];
            index = 1;
        }
        else
        {
            ++index;
            if (index == 2)  // index=2执行++length，之后index再增加也不增加length
            {
                nums[++length] = nums[i];
            }
        }
    }
    int delete_length = nums.size() - (length + 1);
    nums.erase(nums.begin() + length + 1, nums.end());
    return length + 1;
}


int main(int argc, char* argv[])
{
    vector<int> arr{ -14,-14,-14,-14,-14,-14,-14,-13,-13,-13,-13,-12,-11,-11,-11,-9,-9,-9,-7,-7,-7,-6,-6,-5,-5,-5,-4,-4,-4,-3,-3,-3,-2,-2,-2,-1,-1,0,0,0,0,1,1,1,2,2,2,2,3,3,3,3,3,4,4,4,5,5,6,6,6,7,7,7,7,8,8,8,8,9,9,10,10,11,11,11,11,11,12,12,12,12,13,13,13,13,14,14,15,16,17,18,18,18,20,20,21,21,21,21,21,22,22,22,22,23,24,24,25 };
    removeDuplicates2(arr);
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
