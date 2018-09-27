// Copyright 2018.���|�|
// author�����|�|
// ���������
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

int maxSubArray(vector<int> &nums) {
    // write your code here
    if (nums.size() == 0)
    {
        return 0;
    }

    // �����������ֵ
    int max_value = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] > max_value)
        {
            max_value = nums[i];
        }
    }

    int max_sum = max_value;
    int tmp = 0;
    // O(N)ʱ�临�Ӷ�
    // ���tmpΪ��ֵ��˵��nums[i] < 0,i
    // ����������������е���㣬
    // ���max_value < 0��˵������ȫΪ��ֵ��
    // ����������к;���max_value;
    // ���max_value >= 0������������к� >= max_value��
    // ����i�϶���������������е���㣬�������ƣ���Ϊ��ֵ
    // ��������Ҳ��������������е�ǰ׺�����Խ�tmp�ó�0������
    // ������������еĺ�
    for (int i = 0; i < nums.size(); ++i)
    {
        tmp += nums[i];
        if (tmp > max_sum)
        {
            max_sum = tmp;
        }
        else if (tmp < 0)
        {
            tmp = 0;
        }
    }

    return max_sum;

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
    cout << maxSubArray(array) << endl;
    return 0;
}
