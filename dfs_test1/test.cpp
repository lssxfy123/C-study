// Copyright 2018.刘珅珅
// author：刘珅珅
// 深度优先搜索-全排列
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void DFS(vector<int> array, vector<int> book, int step)
{
    if (step == array.size())
    {
        // 输出一种排列
        for (int i = 0; i < array.size(); ++i)
        {
            cout << array[i] << "";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= array.size(); ++i)
    {
        if (book[i - 1] == 0)  // 表示i还没有使用
        {
            array[step] = i;
            book[i - 1] = 1;  // 将数字i标记为已使用
            DFS(array, book, step + 1);
            book[i - 1] = 0;  // 将数字i恢复为未使用，以便后续的搜索
        }
    }
}

// 非递归深度优先搜索
void DFSNoRecursion()
{
    
}

int main(int argc, char* argv[])
{
    int n = 3;  // n的全排列
    vector<int> array(n, 0);
    vector<int> book(n, 0);
    DFS(array, book, 0);
    return 0;
}
