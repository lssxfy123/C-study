// Copyright 2019.刘珅珅
// author：刘珅珅
// 最大子数组III
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int maxSubArray(vector<int> &nums, int k) {
    // write your code here
    if (nums.size() == 0 || k <= 0)
    {
        return 0;
    }

    int result = INT_MIN;
    if (k > nums.size())
    {
        return result;
    }

    // local_max_sums[i][j]表示nums中从1-i个数字，分成j个数组后，和的最大值，且必须
    // 包含第i个数字nums[i-1]
    vector<vector<int>> local_max_sums(nums.size() + 1, vector<int>(k + 1, 0));
    
    // global_max_sums[i][j]表示nums中从1-i个数字，分成j个数组后，和的最大值，其
    // 第j个数组不一定就包含nums[i-1]
    vector<vector<int>> global_max_sums(nums.size() + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= nums.size(); ++i)
    {
        local_max_sums[i][0] = INT_MIN;
        for (int j = 1; j <= k; ++j)
        {
            // 每个子数组都必须有值
            // 所以j > i时将local_max_sums[i][j]
            // 和global_max_sums[i][j]都赋值为INT_MIN
            // 这样不影响后续的判断，不能赋值为0，
            // 因为后续的local_max_sums和global_max_sums
            // 可能小于0
            if (j > i)
            {
                local_max_sums[i][j] = INT_MIN;
                global_max_sums[i][j] = INT_MIN;
                continue;
            }

            // global_max_sums[i-1][j-1]+nums[i-1]表示1到i-1个数分成了j-1个数组
            // 然后第i个数nums[i-1]形成第j个数组
            // local_max_sums[i-1][j]+nums[i-1]表示1到i-1个数分成了j个数组
            // 然后第i个数nums[i-1]加入到第j个数组（也只能加入第j个，不允许子数组重叠）

            // 可以看出，动态规划的转移方程有两步，global_max_sums[i][j]从不包含
            // 第i个数字nums[i-1]且分为j个子数组的和的最大值global_max_sums[i - 1][j]
            // 以及包含第i个数组且分为j个子数组的和的最大值local_max_sums[i][j]中选择最大值
            // 而local_max_sums[i][j]又从将nums[i-1]添加到第j个子数组中的
            // local_max_sums[i - 1][j]+nums[i-1]以及将nums[i-1]形成第j个数组的
            // global_max_sums[i-1][j-1]+nums[i-1]中选择二者较大值
            // 不能采用以往的转移方程dp[i][j]=max(dp[i-1][j], dp[i-1][j-1]+nums[i-1])
            local_max_sums[i][j] = max(global_max_sums[i - 1][j - 1],
                local_max_sums[i - 1][j]) + nums[i - 1];
            if (j == i)  // 每个子数组中只能有一个值，nums[i-1]必须在第j个子数组中
            {
                global_max_sums[i][j] = local_max_sums[i][j];
            }
            else
                global_max_sums[i][j] = max(local_max_sums[i][j], global_max_sums[i - 1][j]);
        }
    }

    return global_max_sums[nums.size()][k];
}

int main(int argc, char* argv[])
{
    vector<int> vec{ -1, 4, -2, 3, -2, 3 };
    int k = 2;
    cout << maxSubArray(vec, k) << endl;

    vector<int> vec1{ 1, 2, 3 };
    k = 3;
    cout << maxSubArray(vec1, k) << endl;
    return 0;
}
