// Copyright 2019.���|�|
// author�����|�|
// ������
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

class Solution {
public:
    /**
    * @param nums: A list of integer
    * @return: An integer, maximum coins
    */
    int maxCoins(vector<int> &nums) {
        // write your code here
        if (nums.size() == 0)
        {
            return 0;
        }

        int n = nums.size();  // �Ƚ�ԭʼ���ȴ洢����
        // ������Ŀ��ʾ��nums�������˸����һ��1���������ļ���
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // dp[i][j]��ʾ������i������j�������ܻ�õ����ķ���
        // ���ڵ�i����j�����򣬿��������ⴵ��һ������k���ܻ��
        // nums[k]*(k��ǰһ����)*(k�ĺ�һ����)��
        // �����ڲ����k��ߺ��ұߵ�������û�б����������޷�ȷ��k���ҵ���
        // ��ô��һ��˼·����󴵱�����һ������k����ôk�������־�ȷ���ˣ�
        // ��߿϶���nums[i-1]���ұ߿϶���nums[j+1],��Ϊ�˿̵�i����j������
        // ֻʣ��kû�б���������ʱ��õķ�������nums[i-1]*nums[k]*nums[j+1]
        // �ټ��ϴ���k֮ǰ��õ�������dp[i][k-1]+dp[k+1][j]
        // ������k֮ǰ������:k��ߵ�i����k-1����k�ұߵ�k+1����j����
        // ״̬ת�Ʒ��̣�dp[i][j]=max(nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j])
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for (int len = 1; len <= n; ++len)
        {
            for (int i = 1; i <= n - len + 1; ++i)
            {
                int j = i + len - 1;

                // ѡ��ͬ��kֵ
                for (int k = i; k <= j; ++k)
                {
                    int tmp = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                    if (dp[i][j] < tmp)
                    {
                        dp[i][j] = tmp;
                    }
                }
            }
        }

        // ���յ�������Ϊ��1������n��
        return dp[1][n];
    }
};

int main(int argc, char* argv[])
{
    return 0;
}
