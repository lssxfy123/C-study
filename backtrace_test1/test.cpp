// Copyright 2017.刘珅珅
// author：刘珅珅
// 回溯算法-求幂集
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > result;
vector<vector<int> > solution_tree;  // 解空间树
vector<int> temp;

void DFS(vector<int>& array, int level)
{
    if (level == array.size())  // 只输出树的叶子结点
    {
        result.push_back(temp);
        return;
    }

    // temp也是解空间树
    // 搜索的过程中动态产生
    temp.push_back(array[level]);
    solution_tree.push_back(temp);
    DFS(array, level + 1);
    temp.pop_back();
    solution_tree.push_back(temp);
    DFS(array, level + 1);
}

vector<vector<int> > SubSets(vector<int>& array)
{
    sort(array.begin(), array.end());
    DFS(array, 0);
    reverse(result.begin(), result.end());
    return result;
}

int main(int argc, char* argv[])
{
    vector<int> origin_array;
    origin_array.push_back(1);
    origin_array.push_back(2);
    origin_array.push_back(3);
    SubSets(origin_array);

    cout << "result: " << endl;
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << "";
        }
        cout << endl;
    }

    cout << "solution tree: " << endl;
    for (int i = 0; i < solution_tree.size(); ++i)
    {
        for (int j = 0; j < solution_tree[i].size(); ++j)
        {
            cout << solution_tree[i][j] << "";
        }
        cout << endl;
    }
    return 0;
}
