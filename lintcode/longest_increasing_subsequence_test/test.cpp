// Copyright 2019.���|�|
// author�����|�|
// �����������
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int longestIncreasingSubsequence(vector<int> &nums) {
    // write your code here
    if (nums.size() < 2)
    {
        return nums.size();
    }
 
    // sequence[i]��ʾ��i+1Ԫ�ؽ�β��������������еĳ���
    // Ĭ��Ϊ1����ʾ������β������������ֻ��һ��Ԫ��
    vector<int> sequece(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            // ��̬�滮
            // ���nums[i]>nums[j]�����ʾ��nums[j]��β������������
            // �������nums[i]�����µ�����������
            // sequence[j]+1��ʾ��0-j������������������nums[i]���γɵ������еĳ���
            // ��������sequence[i]�������sequence[i]
            if (nums[i] > nums[j] && sequece[j] + 1 > sequece[i])
            {
                sequece[i] = sequece[j] + 1;
            }
        }
    }

    int max_long_sequence = 0;
    // ����sequnce�����ֵ
    // sequence���п���������ģ����ĳ��Ԫ�ز������������������
    // ����ֵΪ1
    for (int i = 0; i < nums.size(); ++i)
    {
        if (sequece[i] > max_long_sequence)
        {
            max_long_sequence = sequece[i];
        }
    }

    return max_long_sequence;
}

int longestIncreasingSubsequence1(vector<int> &nums) {
    // write your code here
    if (nums.size() < 2)
    {
        return nums.size();
    }

    // ����ջ�Ĺ���
    vector<int> sequece(nums.size(), INT_MIN);
    int top = 0;  // top+1������������еĳ���
    sequece[top] = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        // ���nums[i]>ջ��Ԫ��
        // ��nums[i]��ջ
        if (nums[i] > sequece[top])
        {
            ++top;
            sequece[top] = nums[i];
        }
        else if (nums[i] == sequece[top])
        {
            continue;
        }
        else
        {
            // nums[i]<sequence[top]
            // ����ջ�е�һ������num[i]��Ԫ��
            // Ȼ����nums[i]�滻�������������������䡰Ǳ����
            // ����ԭ����Ϊ1��5��8��3��6��7
            // ջΪ1��5��8����ʱ����3����3�滻5���õ�1��3��8�� 
            // �ٶ�6����6�滻8���õ�1��3��6��
            // �ٶ�7���õ�����ջΪ1��3��6��7�������������Ϊ����4��
            int low = 0;
            int high = top;
            while (low + 1 < high)
            {
                int middle = low + (high - low) / 2;
                if (nums[i] < sequece[middle])
                {
                    // �����˳�whileѭ����Ҫ��������
                    // ֱ���ҵ���һ��С��nums[i]��Ԫ��
                    high = middle;
                }
                else
                {
                    low = middle;
                }
            }

            if (sequece[low] > nums[i])
            {
                sequece[low] = nums[i];
            }
            else
            {
                sequece[high] = nums[i];
            }
        }
    }

    return top + 1;
}

int main(int argc, char* argv[])
{
    vector<int> vec{ 4, 2, 4, 5, 3, 7 };
    cout << longestIncreasingSubsequence(vec) << endl;
    return 0;
}
