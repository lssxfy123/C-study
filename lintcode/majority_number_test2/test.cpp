// Copyright 2019.���|�|
// author�����|�|
// ��Ԫ��II
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int majorityNumber(vector<int> &nums) {
    // write your code here
    if (nums.size() == 0)
    {
        return 0;
    }
    int majority_number = 0;
    int candidate1 = INT_MIN;  // ��ѡ����1
    int candidate2 = INT_MIN;  // ��ѡ����2
    int count1 = 0;
    int count2 = 0;

    // ���õ����������3�����ֻ�����ͬ�����������ʣ�µ�Ԫ���п϶�����Ԫ��
    // ������10��Ԫ�أ��ϸ����1/3����Ԫ��Ӧ��������4����ͬ���֣�
    // �����3��Ԫ�ػ�����ͬ���޳�����3��Ԫ�أ�ʣ�µ�7��Ԫ�ػ��Ǵ���3����ͬ����
    // �޳�����3��Ԫ�����������1����Ԫ������Ӧ������
    // ��ʼʱcandidate1Ϊnums[0]������num[0]��nums[1]��ͬ
    // ��candidate2Ϊnums[1]�����nums[2]��candidate1��candidate2����ͬ
    // ��count1��count2����1���൱�ڵ���һ��
    for (int i = 0; i < nums.size(); ++i)
    {
        if (candidate1 == nums[i])
        {
            ++count1;
        }
        else if (candidate2 == nums[i])
        {
            ++count2;
        }
        else if (count1 == 0)  // count1������Ϊ0�����¿�ʼ��ȡ��ѡֵ
        {
            candidate1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            candidate2 = nums[i];
            count2 = 1;
        }
        else  // ����1��
        {
            --count1;
            --count2;
        }
    }
    count1 = count2 = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == candidate1)
        {
            ++count1;
        }
        else if (nums[i] == candidate2)
        {
            ++count2;
        }
    }
    majority_number = count1 > count2 ? candidate1 : candidate2;
    return majority_number;
}

int main(int argc, char* argv[])
{
    vector<int> vec{ 99,2,99,2,99,3,3 };
    cout << majorityNumber(vec) << endl;
    vector<int> vec1{ 1, 2, 1, 2, 1, 3, 3 };
    cout << majorityNumber(vec1) << endl;
    return 0;
}
