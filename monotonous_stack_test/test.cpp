// Copyright 2020.刘珅珅
// author：刘珅珅
// 单调栈：求直方图的最大矩形面积

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int monotonous_stack(vector<int> arr)
{
    int max_rect = 0;
    stack<int> tmp;

    // 将第1个元素位置(计算矩形宽度)压入栈
    // 如果栈顶元素小于第i个元素，则i直接入栈
    // 这样在栈中的所有元素中，栈顶元素就是最大值
    for (int i = 0; i < arr.size(); ++i)
    {
        // 如果栈顶元素大于第i个元素，则说明栈顶元素已经是
        // 直方图的某个局部最大值，包含它的矩形(包含是指矩形将该元素对应的直方图包含在内)
        // 到达右边界,它的高度就是矩形的高度
        while (tmp.size() > 0 && arr[tmp.top()] >= arr[i])
        {
            int current = tmp.top();
            tmp.pop();  // 栈顶元素出栈

            // 它的左边界就是栈顶的下一个元素（即下一个栈顶）的位置
            // 下一个栈顶next肯定比arr[current]小，否则在current入栈之前就会出栈
            // current对应的矩形是指完全包含current直方图的矩形，
            // 矩形的高度必须大于等于arr[current]
            // 所以next对应的索引就是左边界
            // 如果栈中有多个元素，则就有多个左边界（右边界都是i）
            int left = tmp.empty() ? -1 : tmp.top();
            int height = arr[current];
            int width = (i - left - 1);
            int area = width * height;
            max_rect = std::max(max_rect, area);
        }
        tmp.push(i);
    }

    while (!tmp.empty())
    {
        int current = tmp.top();
        tmp.pop();
        int left = tmp.empty() ? -1 : tmp.top();
        int width = arr.size() - left - 1;
        int height = arr[current];
        int area = width * height;
        max_rect = max(max_rect, area);
    }
    return max_rect;
}

int main(int argc, char* argv[])
{
    vector<int> arr{ 3, 2, 5, 6, 1, 4, 4 };
    cout << monotonous_stack(arr) << endl;
    return 0;
}
