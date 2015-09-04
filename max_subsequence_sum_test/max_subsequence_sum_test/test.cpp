// Copyright 2015.刘珅珅
// author：刘珅珅
// 最大子序列和的算法分析

#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// 穷举法求最大子序列和
int MaxSubsequenceSum1(const vector<int>& array)
{
    int max_sub_sum = INT_MIN;

    for (int i = 0; i != array.size(); ++i)
    {
        for (int j = i; j != array.size(); ++j)
        {
            int sum = 0;

            for (int k = i; k <= j; ++k)
            {
                sum += array[k];
            }

            if (sum > max_sub_sum)
            {
                max_sub_sum = sum;
            }
        }
    }
    return max_sub_sum;
}

// 改进后的穷举法求最大子序列和
int MaxSubsequenceSum2(const vector<int>& array)
{
    int max_sub_sum = INT_MIN;

    for (int i = 0; i != array.size(); ++i)
    {
        int sum = 0;
        for (int j = i; j != array.size(); ++j)
        {
            sum += array[j];
            if (sum > max_sub_sum)
            {
                max_sub_sum = sum;
            }
        }
    }

    return max_sub_sum;
}

// 递归求解
// 求3个整数的最大值
int Max3(int a, int b, int c)
{
    if (a < b)
    {
        a = b;
    }

    if (a < c)
    {
        a = c;
    }
    return a;
}

int MaxSumRec(const vector<int>& array, int left, int right)
{
    if (left == right)  // 基准情形
    {
        return array[left];
    }

    int center = static_cast<int>((left + right) / 2);

    // 左半部分最大子序列和
    int max_left_sum = MaxSumRec(array, left, center);

    // 右半部分最大子序列和
    int max_right_sum = MaxSumRec(array, center + 1, right);

    // 跨数据中部从而占据左右两半部分的最大子序列和
    // 这个子序列包含左半部分的最后一个元素以及
    // 右半部分的第一个元素
    int max_left_border_sum = INT_MIN;
    int left_border_sum = 0;

    for (int i = center; i >= left; --i)
    {
        left_border_sum += array[i];
        if (left_border_sum > max_left_border_sum)
        {
            max_left_border_sum = left_border_sum;
        }
    }

    int max_right_border_sum = INT_MIN;
    int right_border_sum = 0;

    for (int j = center + 1; j <= right; ++j)
    {
        right_border_sum += array[j];
        if (right_border_sum > max_right_border_sum)
        {
            max_right_border_sum = right_border_sum;
        }
    }

    return Max3(max_left_sum, max_right_sum, max_right_border_sum + max_left_border_sum);
}

int MaxSubsequenceSum3(const vector<int>& array)
{
    return MaxSumRec(array, 0, array.size() - 1);
}

int main(int argc, char* argv[])
{
    vector<int> array;
    array.push_back(-2);
    array.push_back(11);
    array.push_back(-4);
    array.push_back(13);
    array.push_back(-5);
    array.push_back(-2);

    cout << "max sub sequence sum1 is: " << MaxSubsequenceSum1(array) << endl;
    cout << "max sub sequence sum2 is: " << MaxSubsequenceSum2(array) << endl;
    cout << "max sub sequence sum3 is: " << MaxSubsequenceSum3(array) << endl;
    return 0;
}
