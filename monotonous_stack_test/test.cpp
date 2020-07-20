// Copyright 2020.���|�|
// author�����|�|
// ����ջ����ֱ��ͼ�����������

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int monotonous_stack(vector<int> arr)
{
    int max_rect = 0;
    stack<int> tmp;

    // ����1��Ԫ��λ��(������ο��)ѹ��ջ
    // ���ջ��Ԫ��С�ڵ�i��Ԫ�أ���iֱ����ջ
    // ������ջ�е�����Ԫ���У�ջ��Ԫ�ؾ������ֵ
    for (int i = 0; i < arr.size(); ++i)
    {
        // ���ջ��Ԫ�ش��ڵ�i��Ԫ�أ���˵��ջ��Ԫ���Ѿ���
        // ֱ��ͼ��ĳ���ֲ����ֵ���������ľ���(������ָ���ν���Ԫ�ض�Ӧ��ֱ��ͼ��������)
        // �����ұ߽�,���ĸ߶Ⱦ��Ǿ��εĸ߶�
        while (tmp.size() > 0 && arr[tmp.top()] >= arr[i])
        {
            int current = tmp.top();
            tmp.pop();  // ջ��Ԫ�س�ջ

            // ������߽����ջ������һ��Ԫ�أ�����һ��ջ������λ��
            // ��һ��ջ��next�϶���arr[current]С��������current��ջ֮ǰ�ͻ��ջ
            // current��Ӧ�ľ�����ָ��ȫ����currentֱ��ͼ�ľ��Σ�
            // ���εĸ߶ȱ�����ڵ���arr[current]
            // ����next��Ӧ������������߽�
            // ���ջ���ж��Ԫ�أ�����ж����߽磨�ұ߽綼��i��
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
