// Copyright 2018.Áõ«|«|
// author£ºÁõ«|«|
// É¾³ýÅÅÐòÊý×éÖØ¸´ÔªËØ
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

int removeDuplicates1(vector<int> &nums) {
    // write your code here
    if (nums.size() == 0)
    {
        return 0;
    }
    int length = 0;
    for (int i = 1; i < nums.size();  ++i)
    {
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

int removeDuplicates2(vector<int> &nums) {
    // write your code here
    if (nums.size() == 0)
    {
        return 0;
    }
    int length = 0;
    int index = 1;
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
            if (index == 2)
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
