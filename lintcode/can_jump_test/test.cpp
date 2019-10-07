// Copyright 2019.���|�|
// author�����|�|
// ��Ծ��Ϸ
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
    // ��̬�滮
    bool canJump1(vector<int> &A) {
        // write your code here
        int n = A.size();
        if (n == 0)
        {
            return false;
        }

        // dp[i]��ʾ�Ƿ��ܵ�����i��Ԫ��
        vector<bool> dp(n, false);
        dp[0] = true;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (!dp[i])
                {
                    // ״̬ת�Ʒ���
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
            // ���֮ǰ��������󳤶ȱ�iС
            // �����޷�������i��λ��
            // Ҳ�϶��������������һ��λ��
            if (i > tmp)
            {
                return false;
            }

            // tmp��ʾǰi��λ��ÿ��λ�����������Զ
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
