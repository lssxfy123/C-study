// Copyright 2019.���|�|
// author�����|�|
// ȫ����
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

        // ���ǰ������������ͬ������ʺ�һ������ʱ��ǰһ������
        // �����Ѿ����ʹ������������ͬ������
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

    // �������������������ظ�Ԫ��
    // ��϶�����һ��
    sort(nums.begin(), nums.end());
    vector<int> mark(nums.size(), 0);
    vector<int> result;
    dfs(nums, mark, result, 0, results);
    return results;
}

// �ǵݹ鷽ʽ
// ʹ��next_permutation����
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

// ��������������ĳɷǵݹ���ʽ
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

    // tmp�洢�Ѿ�ʹ�õ�Ԫ�ص�����
    // Ĭ�����-1���Ա������������
    tmp.push_back(-1);

    while (tmp.size() > 0)
    {
        // ����nums = {1, 3, 5}
        // ��ʼ�ǣ�tmp = {-1}
        // ��һ��whileѭ����
        // tmp = {0, 1, 2}
        // result = {1, 3, 5}
        // markȫ��true
        // �ڶ���whileѭ����
        // last������2��mark[2]=false
        // ��1��forѭ������next=-1�����Ž��е�3��whileѭ��
        // lastΪ1��mark[1]=false��next=2
        // tmp={0, 2, 1},result={1, 5, 3}
        // ��������
        int last = tmp.back();
        tmp.pop_back();
        if (last != -1)
        {
            mark[last] = false;
        }

        // ����δʹ�õ�Ԫ��
        int next = -1;
        for (int i = last + 1; i < n; ++i)
        {
            // ���ǰ������������ͬ������ʺ�һ������ʱ��ǰһ������
            // �����Ѿ����ʹ������������ͬ������
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

        // ���һ������
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
    cout << "�ǵݹ�" << endl;
    permute1(vec2);
    cout << "�ǵݹ�2" << endl;
	permute2(vec);
    permute2(vec2);
    return 0;
}
