// Copyright 2019.���|�|
// author�����|�|
// ���� n ��������һ������ k, ����Դ���ѡ�� k ������, 
// ���ڣ�Ҫ��������k������Ϊ�������ж����ַ���
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

class Solution {
public:
    int count;
    /**
    * @param a: the n numbers
    * @param k: the number of integers you can choose
    * @return: how many ways that the sum of the k integers is a prime number
    */
    int getWays(vector<int> &a, int k) {
        // Write your code here
        if (a.size() == 0 || a.size() < k)
        {
            return 0;
        }
        count = 0;
        vector<int> tmp;
        dfs(a, k, tmp, 0);
        return count;
    }

    void dfs(vector<int>& a, int k, vector<int> tmp, int index)
    {
        if (tmp.size() == k)
        {
            int sum = 0;
            for (int i = 0; i < tmp.size(); ++i)
            {
                sum += tmp[i];
            }

            if (isPrime(sum))
            {
                ++count;
            }

            return;
        }

        for (int i = index; i < a.size(); ++i)
        {
            tmp.push_back(a[i]);
            dfs(a, k, tmp, i + 1);
            tmp.pop_back();
        }
    }

    bool isPrime(int num)
    {
        for (int i = 2; i <= sqrt(num); ++i)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    return 0;
}
