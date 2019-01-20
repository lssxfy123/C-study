// Copyright 2019.刘珅珅
// author：刘珅珅
// 求子集
// 如A = {1, 2, 3}
// 子集：{{1, 2, 3}, {1, 2}, {1, 3} {1}, {2, 3}, {2}, {3}, {}}
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> nums, vector<bool> marks, int level, vector<vector<int>>& results)
{
    if (level == nums.size())
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (marks[i])
            {
                result.push_back(nums[i]);
            }
        }

        results.push_back(result);
        return;
    }

    // 如果前后两个元素相同，并且level-1未选取，则后一个level也不选取,
    // 如果level选取，就会与level-1选取，level不选取的情况重复
    if (level > 0 && nums[level] == nums[level - 1] && !marks[level - 1])
    {
        marks[level] = false;  // 不取第level个元素
        dfs(nums, marks, level + 1, results);
    }
    else
    {
        marks[level] = true;  // 取第level个元素
        dfs(nums, marks, level + 1, results);
        marks[level] = false;  // 不取第level个元素
        dfs(nums, marks, level + 1, results);
    }
}

// 深度优先搜索
vector<vector<int>> subsets(vector<int>& nums) {
    // write your code here
    vector<vector<int>> results;
    vector<int> result;
    if (nums.size() == 0)
    {
        results.push_back(result);
        return results;
    }

    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<bool> mark(n, false);  // 标记数组
    dfs(nums, mark, 0, results);
    cout << "subsets size: " << results.size() << endl;
    for (int i = 0;i < results.size(); ++i)
    {
        for (int j = 0; j < results[i].size(); ++j)
        {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
    return results;
}

// 非递归
vector<vector<int>> subsets1(vector<int>& nums) {
    // write your code here
    vector<vector<int>> results;
    vector<int> result;
    results.push_back(result);
    if (nums.size() == 0)
    {
        return results;
    }

    int n = nums.size();
    sort(nums.begin(), nums.end());

    auto Print = [&results] {
        for (int i = 0; i < results.size(); ++i)
        {
            for (int j = 0; j < results[i].size(); ++j)
            {
                cout << results[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    };

    // 思路：
    // nums[i]若不和之前mums[i - 1]的重复，则把results中的每一个数组都添加nums[i],
    // 若和之前的重复，则只使用results中上一个nums[i - 1]新产生的结果，
    // 因为nums[i - 1]之前的结果如果也添加nums[i]，则肯定会与nums[i - 1]
    // 产生的新结果重复
    // 例：[1, 2, 2, 5]
    // 初始状态: results=[[]]
    // i = 0: results=[[], [1]]
    // i = 1: results = [[], [1], [2], [1, 2]]
    // i = 2: nums[1] == nums[2]，所以results中，只使用i=1新产生的数组
    // [2], [1, 2]，i=1之前i=0的数组不使用
    int last_count = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        int count = results.size();
        int start = 0;
        if (i > 0 && nums[i] == nums[i - 1])
        {
            start = last_count;
        }

        for (int j = start; j < count; ++j)
        {
            vector<int> tmp;
            if (results[j].size() > 0)
            {
                tmp.assign(results[j].begin(), results[j].end());
            }
            tmp.push_back(nums[i]);
            results.push_back(tmp);
        }

        Print();

        // 存储的是nums[i]之前的结果
        last_count = count;
    }

    cout << "subsets size: " << results.size() << endl;
    Print();
    return results;
}


int main(int argc, char* argv[])
{
    vector<int> vec{1, 3, 5};
    vector<int> vec1{ 1, 2, 2 };
    vector<int> vec2{ 1, 2, 5, 2 };
    subsets(vec);
    subsets(vec1);
    subsets(vec2);
    cout << "非递归：" << endl;
    //subsets1(vec);
    //subsets1(vec1);
    subsets1(vec2);
    return 0;
}
