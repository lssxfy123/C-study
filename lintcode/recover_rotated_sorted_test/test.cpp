// Copyright 2018.Áõ«|«|
// author£ºÁõ«|«|
// »Ö¸´Ðý×ªÊý×é
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

void recoverRotatedSortedArray(vector<int> &nums) {
    // write your code here
    if (nums.size() == 0)
    {
        return;
    }

    int index = -1;
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        if (nums[i] > nums[i + 1])
        {
            index = i + 1;
            break;
        }
    }

    if (index > 0)
    {
        if (index > nums.size() / 2)
        {
            for (int i = index; i < nums.size(); ++i)
            {
                int tmp = nums.back();
                nums.pop_back();
                nums.insert(nums.begin(), tmp);
            }
        }
        else
        {
            for (int i = 0; i < index; ++i)
            {
                int tmp = nums[0];
                nums.erase(nums.begin());
                nums.push_back(tmp);
            }
        }
    }

}

int main(int argc, char* argv[])
{
    vector<int> nums{2, 3, 4, 5, 1};
    recoverRotatedSortedArray(nums);
    return 0;
}
