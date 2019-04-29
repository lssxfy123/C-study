// Copyright 2019.刘珅珅
// author：刘珅珅
// 全排列
#include <iostream>
#include <vector>
#include <algorithm>
#include "../../include/print.hpp"

void dfs(vector<int> nums, vector<int> mark, vector<int>& reslut, int step, vector<vector<int>> results)
{
    if (step == nums.size())
    {
        for (int i = 0; i < reslut.size(); ++i)
        {
            cout << reslut[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        bool flag = true;

        // 如果前后两个数字相同，则访问后一个数字时，前一个数字
        // 必须已经访问过，否则就是相同的排列
        if (i > 0 && nums[i] == nums[i - 1] && mark[i - 1] == 0)
        {
            continue;
        }

        if (mark[i] == 0)
        {
            if (reslut.size() == nums.size())
            {
                reslut[step] = nums[i];
            }
            else
            {
                reslut.push_back(nums[i]);
            }

            mark[i] = 1;
            dfs(nums, mark, reslut, step + 1, results);
            mark[i] = 0;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    // write your code here
    vector<vector<int>> results;
    if (nums.size() == 0)
    {
        return results;
    }

    // 对数组进行排序，如果有重复元素
    // 则肯定挨在一起
    sort(nums.begin(), nums.end());
    vector<int> mark(nums.size(), 0);
    vector<int> result;
    dfs(nums, mark, result, 0, results);
    return results;
}

// 非递归方式
// 使用next_permutation函数
vector<vector<int>> permute1(vector<int> &nums) {
    // write your code here
    vector<vector<int>> results;
    if (nums.size() == 0)
    {
        return results;
    }

    sort(nums.begin(), nums.end());
    while (next_permutation(nums.begin(), nums.end()))
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    return results;

}

// 将深度优先搜索改成非递归形式
vector<vector<int>> permute2(vector<int> &nums) {
    // write your code here
    vector<vector<int>> results;
    if (nums.size() == 0)
    {
        return results;
    }

    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<bool> mark(n, false);
    vector<int> tmp;

    // tmp存储已经使用的元素的索引
    // 默认添加-1，以便输出自身排列
    tmp.push_back(-1);

    while (tmp.size() > 0)
    {
        // 例：nums = {1, 3, 5}
        // 初始是，tmp = {-1}
        // 第一次while循环：
        // tmp = {0, 1, 2}
        // result = {1, 3, 5}
        // mark全是true
        // 第二次while循环：
        // last首先是2，mark[2]=false
        // 第1个for循环查找next=-1，接着进行第3次while循环
        // last为1，mark[1]=false，next=2
        // tmp={0, 2, 1},result={1, 5, 3}
        // 依次类推
        int last = tmp.back();
        tmp.pop_back();
        if (last != -1)
        {
            mark[last] = false;
        }

        // 查找未使用的元素
        int next = -1;
        for (int i = last + 1; i < n; ++i)
        {
            // 如果前后两个数字相同，则访问后一个数字时，前一个数字
            // 必须已经访问过，否则就是相同的排列
            if (i > 0 && nums[i] == nums[i - 1] && mark[i - 1] == false)
            {
                continue;
            }

            if (mark[i] == false)
            {
                next = i;
                break;
            }
        }

        if (next == -1)
        {
            continue;
        }

        tmp.push_back(next);
        mark[next] = true;
        for (int i = 0; i < n; ++i)
        {
            if (!mark[i])
            {
                tmp.push_back(i);
                mark[i] = true;
            }
        }

        // 输出一个排列
        vector<int> result;
        for (int i = 0; i < n; ++i)
        {
            result.push_back(nums[tmp[i]]);
        }

        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return results;

}


int main(int argc, char* argv[])
{
    vector<int> vec{ 1, 3, 5 };
    vector<int> vec1{ 1, 3, 3 };
    vector<int> vec2{ 1, 2, 5, 2 };
    permute(vec);
    cout << endl;
    permute(vec1);
    cout << endl;
    permute(vec2);
    cout << "非递归" << endl;
    permute1(vec2);
    cout << "非递归2" << endl;
	permute2(vec);
    permute2(vec2);
    return 0;
}
