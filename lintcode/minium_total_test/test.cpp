// Copyright 2019.���|�|
// author�����|�|
// ����������
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

class Solution {
public:
    /**
    * @param triangle: a list of lists of integers
    * @return: An integer, minimum path sum
    */
    int minimumTotal1(vector<vector<int>> &triangle) {
        // write your code here
        int n = triangle.size();
        if (n == 0 || triangle[0].size() == 0)
        {
            return 0;
        }

        int m = triangle[n - 1].size();

        // dp[i][j]��ʾ��(0,0)��(i,j)����С·����
        // dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j]
        // ����(i,j)ֻ������·��������(i-1,j-1)���(i-1,j)
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                if (j == 0)  // ��߽�
                {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                    continue;
                }

                if (j == triangle[i].size() - 1)  // �ұ߽�
                {
                    // ֻ�ܴ���һ�е����Ҷ˵�(i-1,j-1)����(i,j)
                    dp[i][j] = dp[i - 1][triangle[i - 1].size() - 1] + triangle[i][j];
                    continue;
                }

                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }

        // ����dp[n - 1]����Сֵ
        int result = dp[n - 1][0];
        for (int i = 1; i < triangle[n - 1].size(); ++i)
        {
            result = min(result, dp[n - 1][i]);
        }
        return result;
    }

    int minimumTotal(vector<vector<int>> &triangle) {
        // write your code here
        int n = triangle.size();
        if (n == 0 || triangle[0].size() == 0)
        {
            return 0;
        }

        int m = triangle[n - 1].size();

        // ��minimumTotal1�п��Կ���dp[i]ֻ��dp[i-1]���
        // ״̬ת�Ʒ���ת��Ϊdp[j]=min(dp[j],dp[j-1])+triangle[i][j]
        vector<int> dp(m, 0);
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; ++i)
        {
            // �ڲ��forѭ���±��ǴӴ�С��ʼ�ģ����ά����µ��ڲ�forѭ����ͬ
            // �ο�92.�������⣬���ֽ�ά�������ò�ƶ������
            // https://www.jianshu.com/p/918ca2aff350
            // ������⣺һά��״̬ת�Ʒ����Ǵ�dp[j]->dp[j-1]�����ԴӴ�С
            // ��ά����£��õ��ǲ�ͬ�е�dp[i][j]->dp[i-1][j-1]
            for (int j = triangle[i].size() - 1; j >= 0; --j)
            {
                if (j == 0)  // ��߽�
                {
                    dp[j] = dp[j] + triangle[i][j];
                    continue;
                }

                if (j == triangle[i].size() - 1)  // �ұ߽�
                {
                    // ֻ�ܴ���һ�е����Ҷ˵�(i-1,j-1)����(i,j)
                    dp[j] = dp[triangle[i - 1].size() - 1] + triangle[i][j];
                    continue;
                }

                dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
            }
        }

        // ����dp����Сֵ
        int result = dp[0];
        for (int i = 1; i < dp.size(); ++i)
        {
            result = min(result, dp[i]);
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    return 0;
}
