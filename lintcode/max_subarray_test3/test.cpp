// Copyright 2019.���|�|
// author�����|�|
// ���������III
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

    // local_max_sums[i][j]��ʾnums�д�1-i�����֣��ֳ�j������󣬺͵����ֵ���ұ���
    // ������i������nums[i-1]
    vector<vector<int>> local_max_sums(nums.size() + 1, vector<int>(k + 1, 0));
    
    // global_max_sums[i][j]��ʾnums�д�1-i�����֣��ֳ�j������󣬺͵����ֵ����
    // ��j�����鲻һ���Ͱ���nums[i-1]
    vector<vector<int>> global_max_sums(nums.size() + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= nums.size(); ++i)
    {
        local_max_sums[i][0] = INT_MIN;
        for (int j = 1; j <= k; ++j)
        {
            // ÿ�������鶼������ֵ
            // ����j > iʱ��local_max_sums[i][j]
            // ��global_max_sums[i][j]����ֵΪINT_MIN
            // ������Ӱ��������жϣ����ܸ�ֵΪ0��
            // ��Ϊ������local_max_sums��global_max_sums
            // ����С��0
            if (j > i)
            {
                local_max_sums[i][j] = INT_MIN;
                global_max_sums[i][j] = INT_MIN;
                continue;
            }

            // global_max_sums[i-1][j-1]+nums[i-1]��ʾ1��i-1�����ֳ���j-1������
            // Ȼ���i����nums[i-1]�γɵ�j������
            // local_max_sums[i-1][j]+nums[i-1]��ʾ1��i-1�����ֳ���j������
            // Ȼ���i����nums[i-1]���뵽��j�����飨Ҳֻ�ܼ����j�����������������ص���

            // ���Կ�������̬�滮��ת�Ʒ�����������global_max_sums[i][j]�Ӳ�����
            // ��i������nums[i-1]�ҷ�Ϊj��������ĺ͵����ֵglobal_max_sums[i - 1][j]
            // �Լ�������i�������ҷ�Ϊj��������ĺ͵����ֵlocal_max_sums[i][j]��ѡ�����ֵ
            // ��local_max_sums[i][j]�ִӽ�nums[i-1]��ӵ���j���������е�
            // local_max_sums[i - 1][j]+nums[i-1]�Լ���nums[i-1]�γɵ�j�������
            // global_max_sums[i-1][j-1]+nums[i-1]��ѡ����߽ϴ�ֵ
            // ���ܲ���������ת�Ʒ���dp[i][j]=max(dp[i-1][j], dp[i-1][j-1]+nums[i-1])
            local_max_sums[i][j] = max(global_max_sums[i - 1][j - 1],
                local_max_sums[i - 1][j]) + nums[i - 1];
            if (j == i)  // ÿ����������ֻ����һ��ֵ��nums[i-1]�����ڵ�j����������
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
