// Copyright 2019.刘珅珅
// author：刘珅珅
// 跳跃游戏
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

class Solution {
public:
    /**
    * @param A: A list of integers
    * @return: A boolean
    */
    // 动态规划
    bool canJump1(vector<int> &A) {
        // write your code here
        int n = A.size();
        if (n == 0)
        {
            return false;
        }

        // dp[i]表示是否能调到第i个元素
        vector<bool> dp(n, false);
        dp[0] = true;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (!dp[i])
                {
                    // 状态转移方程
                    dp[i] = dp[j] && (A[j] >= i - j);
                    if (dp[i])
                    {
                        break;
                    }
                }
            }
        }
        return dp[n - 1];
    }

    // 
    bool canJump(vector<int> &A) {
        // write your code here
        int n = A.size();
        if (n == 0)
        {
            return false;
        }

        int tmp = 0;
        for (int i = 0;i < n; ++i)
        {
            // 如果之前能跳的最大长度比i小
            // 表明无法跳到第i个位置
            // 也肯定跳不动数组最后一个位置
            if (i > tmp)
            {
                return false;
            }

            // tmp表示前i个位置每个位置最多能跳多远
            if (tmp < i + A[i])
            {
                tmp = i + A[i];
            }
        }
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> A{ 2,3,1,1,4 };
    if (s.canJump(A))
    {
        cout << "can Jump!" << endl;
    }
    else
    {
        cout << "No can Jump!" << endl;
    }

    vector<int> A1{ 3,2,1,0,4 };
    if (s.canJump(A1))
    {
        cout << "can Jump!" << endl;
    }
    else
    {
        cout << "No can Jump!" << endl;
    }
    return 0;
}
