// Copyright 2019.���|�|
// author�����|�|
// ����֮��
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

vector<vector<int>> threeSum(vector<int> &numbers) {
    // write your code here
    vector<vector<int>> result;
    if (numbers.size() < 3)
    {
        return result;
    }

    sort(numbers.begin(), numbers.end());
    if (numbers.front() > 0 || numbers.back() < 0)
    {
        return result;
    }

    // �̶���һԪ�أ�Ȼ����ҵڶ�������Ԫ��
    // ��һ��ѭ����ൽnumbers.size() - 2����Ϊ��Ҫ3����
    for (int i = 0; i < numbers.size() - 2; ++i)
    {
        // �����numbers[i]Ϊ3Ԫ������Сֵ
        // ��������0�Ͳ���Ҫ�ڲ�����
        if (numbers[i] > 0)
        {
            break;
        }

        // �ظ�
        if (i > 0 && numbers[i] == numbers[i - 1])
        {
            continue;
        }

        // �ڶ�Ԫ�س�ʼΪ��һԪ�ص���һ��
        // ����Ԫ�س�ʼΪ���һ��Ԫ��
        // ���sum!=0��sum<0�͵���left����Ϊnumbers[right]
        // �Ѿ�����ȡ�������ֵ��sum>0���͵���right����Ϊ
        // numbers[left]�Ѿ�����ȡ������Сֵ
        int left = i + 1;
        int right = numbers.size() - 1;

        // �̶���һԪ��
        while (left < right)
        {
            int sum = numbers[i] + numbers[left] + numbers[right];
            if (sum == 0)
            {
                vector<int> tmp;
                tmp.push_back(numbers[i]);
                tmp.push_back(numbers[left]);
                tmp.push_back(numbers[right]);
                result.push_back(tmp);
                ++left;
                --right;

                // �ų��ظ�Ԫ��
                while (left < right && numbers[left] == numbers[left - 1])
                {
                    ++left;
                }

                // �ų��ظ�Ԫ��
                while (left < right && numbers[right] == numbers[right + 1])
                {
                    --right;
                }
            }
            else if (sum < 0)  // ���ڶ�Ԫ���������ƣ���ȡ����ĵڶ�Ԫ��
            {
                ++left;
            }
            else  // sum>0 ������Ԫ���������ƣ���ȡ��С�ĵ���Ԫ��
            {
                --right;
            }
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    return 0;
}
