// Copyright 2019.���|�|
// author�����|�|
// ���������II
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int maxTwoSubArrays(vector<int> &nums) {
    // write your code here
    if (nums.size() == 0)
    {
        return 0;
    }

    // �洢nums����ǰi+1��Ԫ�ص����������֮��
    vector<int> left_sum(nums.size(), 0);
    int max_left_sum = INT_MIN;
    int tmp_left = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (tmp_left < 0)
        {
            tmp_left = 0;
        }
        tmp_left += nums[i];
        left_sum[i] = max_left_sum = max(tmp_left, max_left_sum);
    }

    // �������󣬴洢nums����ǰj+1��Ԫ�ص����������֮��
    // right_sum[nums.size() - 1]��ʾ���һ��Ԫ�ص����������֮��
    // right_sum[0]��ʾ������������������֮��
    vector<int> right_sum(nums.size(), 0);
    int max_right_sum = INT_MIN;
    int tmp_right = 0;
    for (int j = nums.size() - 1; j >= 0; --j)
    {
        if (tmp_right < 0)
        {
            tmp_right = 0;
        }
        tmp_right += nums[j];
        right_sum[j] = max_right_sum = max(max_right_sum, tmp_right);
    }

    int result = INT_MIN;
    // ����������ң��������������������������ӵ����ֵ
    // �������������鲻���ظ�������left_sumȡ��k��Ԫ��ʱ��right_sumȡk+1��Ԫ��
    // ����k=0��left_sum[0]��ʾnumsǰ1��Ԫ�ص����������ͣ�right_sum[1]
    // ��ʾnums��ʾ���������ٳ���1��Ԫ�ص����������֮��
    for (int k = 0; k < nums.size() - 1; ++k)
    {
        result = max(result, left_sum[k] + right_sum[k + 1]);
    }

    return result;
}

int maxTwoSubArrays1(vector<int> &nums) {
    // write your code here
    if (nums.size() == 0)
    {
        return 0;
    }

    // �洢nums����ǰi+1��Ԫ�ص����������֮��
    vector<int> left_sum(nums.size(), 0);
    int max_left_sum = INT_MIN;
    int tmp_left = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (tmp_left < 0)
        {
            tmp_left = 0;
        }
        tmp_left += nums[i];
        if (tmp_left > max_left_sum)
        {
            max_left_sum = tmp_left;
        }
        left_sum[i] = max_left_sum;
    }

    // �������󣬴洢nums����ǰj+1��Ԫ�ص����������֮��
    // right_sum[nums.size() - 1]��ʾ���һ��Ԫ�ص����������֮��
    // right_sum[0]��ʾ������������������֮��
    vector<int> right_sum(nums.size(), 0);
    int max_right_sum = INT_MIN;
    int result = INT_MIN;
    int tmp_right = 0;
    for (int j = nums.size() - 1; j > 0; --j)
    {
        if (tmp_right < 0)
        {
            tmp_right = 0;
        }
        tmp_right += nums[j];
        if (tmp_right > max_right_sum)
        {
            max_right_sum = tmp_right;
        }

        if (max_right_sum + left_sum[j - 1] > result)
        {
            result = max_right_sum + left_sum[j - 1];
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    vector<int> vec{ 1, 3, -1, 2, -1, 2 };
    cout << maxTwoSubArrays(vec) << endl;
    vector<int> vec1{ 5, 4 };
    cout << maxTwoSubArrays(vec1) << endl;

    vector<int> vec2{ -1, 0, 1 };
    cout << maxTwoSubArrays(vec2) << endl;

    vector<int> vec3{ -1, 4, -2, 3, -2, 3 };
    cout << maxTwoSubArrays(vec3) << endl;
    return 0;
}
