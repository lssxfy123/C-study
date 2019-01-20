// Copyright 2019.���|�|
// author�����|�|
// ���Ӽ�
// ��A = {1, 2, 3}
// �Ӽ���{{1, 2, 3}, {1, 2}, {1, 3} {1}, {2, 3}, {2}, {3}, {}}
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

    // ���ǰ������Ԫ����ͬ������level-1δѡȡ�����һ��levelҲ��ѡȡ,
    // ���levelѡȡ���ͻ���level-1ѡȡ��level��ѡȡ������ظ�
    if (level > 0 && nums[level] == nums[level - 1] && !marks[level - 1])
    {
        marks[level] = false;  // ��ȡ��level��Ԫ��
        dfs(nums, marks, level + 1, results);
    }
    else
    {
        marks[level] = true;  // ȡ��level��Ԫ��
        dfs(nums, marks, level + 1, results);
        marks[level] = false;  // ��ȡ��level��Ԫ��
        dfs(nums, marks, level + 1, results);
    }
}

// �����������
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
    vector<bool> mark(n, false);  // �������
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

// �ǵݹ�
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

    // ˼·��
    // nums[i]������֮ǰmums[i - 1]���ظ������results�е�ÿһ�����鶼���nums[i],
    // ����֮ǰ���ظ�����ֻʹ��results����һ��nums[i - 1]�²����Ľ����
    // ��Ϊnums[i - 1]֮ǰ�Ľ�����Ҳ���nums[i]����϶�����nums[i - 1]
    // �������½���ظ�
    // ����[1, 2, 2, 5]
    // ��ʼ״̬: results=[[]]
    // i = 0: results=[[], [1]]
    // i = 1: results = [[], [1], [2], [1, 2]]
    // i = 2: nums[1] == nums[2]������results�У�ֻʹ��i=1�²���������
    // [2], [1, 2]��i=1֮ǰi=0�����鲻ʹ��
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

        // �洢����nums[i]֮ǰ�Ľ��
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
    cout << "�ǵݹ飺" << endl;
    //subsets1(vec);
    //subsets1(vec1);
    subsets1(vec2);
    return 0;
}
