// Copyright 2018.刘珅珅
// author：刘珅珅
// 中位数
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
		// pq为优先队列，顶部元素为其最大值
		// k为nums长度的一半，pq.size() == k
		// 其顶部元素为前k个元素的最大值
		// 如果pq.top()大于之后的元素，就
		// 需要弹出并将新元素插入，最终pq.top()
		// 就是中位数
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
