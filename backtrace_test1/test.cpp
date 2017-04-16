// Copyright 2017.���|�|
// author�����|�|
// �����㷨-���ݼ�
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > result;
vector<vector<int> > solution_tree;  // ��ռ���
vector<int> temp;

void DFS(vector<int>& array, int level)
{
    if (level == array.size())  // ֻ�������Ҷ�ӽ��
    {
        result.push_back(temp);
        return;
    }

    // tempҲ�ǽ�ռ���
    // �����Ĺ����ж�̬����
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
