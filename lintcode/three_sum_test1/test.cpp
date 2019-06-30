// Copyright 2019.刘珅珅
// author：刘珅珅
// 三数之和
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

    // 固定第一元素，然后查找第二，第三元素
    // 第一层循环最多到numbers.size() - 2，因为需要3个数
    for (int i = 0; i < numbers.size() - 2; ++i)
    {
        // 排序后numbers[i]为3元素中最小值
        // 如果其大于0就不需要在查找了
        if (numbers[i] > 0)
        {
            break;
        }

        // 重复
        if (i > 0 && numbers[i] == numbers[i - 1])
        {
            continue;
        }

        // 第二元素初始为第一元素的下一个
        // 第三元素初始为最后一个元素
        // 如果sum!=0，sum<0就调整left，因为numbers[right]
        // 已经是能取到的最大值，sum>0，就调整right，因为
        // numbers[left]已经是能取到的最小值
        int left = i + 1;
        int right = numbers.size() - 1;

        // 固定第一元素
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

                // 排除重复元素
                while (left < right && numbers[left] == numbers[left - 1])
                {
                    ++left;
                }

                // 排除重复元素
                while (left < right && numbers[right] == numbers[right + 1])
                {
                    --right;
                }
            }
            else if (sum < 0)  // 将第二元素索引右移，获取更大的第二元素
            {
                ++left;
            }
            else  // sum>0 将第三元素索引左移，获取更小的第三元素
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
