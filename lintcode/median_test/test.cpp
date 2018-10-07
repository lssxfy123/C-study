// Copyright 2018.Áõ«|«|
// author£ºÁõ«|«|
// ÖÐÎ»Êý
#include <iostream>
#include <queue>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int median(vector<int> &nums) {
    // write your code here
    int k = (nums.size() + 1) / 2;
    priority_queue<int> pq;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (pq.size() == k)
        {
            if (pq.top() > nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        else
        {
            pq.push(nums[i]);
        }
    }
    return pq.top();
}

int main(int argc, char* argv[])
{
    vector<int> vec{ 2, 3, 1, 1, 1, 1, 1, 4, 5, 9 };
    cout << median(vec) << endl;
    return 0;
}
