// Copyright 2019.���|�|
// author�����|�|
// �������е����·����
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
    }
};


class Solution {
public:
    /**
    * @param root: The root of binary tree.
    * @return: An integer
    */
    int maxPathSum(TreeNode * root) {
        // write your code here
        // ������·��ͨ��ĳһ��㣬�ּ��������
        // 1.�ǴӸý������ӵ���ý�㣬
        // 2.�Ӹý����Һ��ӵ���ý�㣬
        // 3.ͨ������->�ý��->�Һ���
        // 4.�ý�����·���������յ㣬�����쵽���ӽ����
        // https://www.cnblogs.com/grandyang/p/4280120.html
        result = INT_MIN;
        getPath(root);
        return result;
    }

    int getPath(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int left_sum = 0;
        int right_sum = 0;
        if (root->left != nullptr)
        {
            // ������Ϊ�յ����path
            left_sum = getPath(root->left);
        }

        if (root->right != nullptr)
        {
            // ���Һ���Ϊ�յ����path
            right_sum = getPath(root->right);
        }

        // ȡ·��ͨ������->����㣬�Һ���->����㣬ֻ���������������������ֵ
        int max_single = max(max(left_sum, right_sum) + root->val, root->val);

        // ����->��->�ҽ���·������������������Ƚ�
        // ����->��->�Һ��Ӳ���Ҫ�ݹ�ʱ���ϲ㷵�أ���Ϊ������������·����
        // �����ٰ����ϲ�����
        int max_top = max(max_single, left_sum + right_sum + root->val);
        result = max(result, max_top);

        // ����ֵȡ·��ͨ������->����㣬�Һ���->����㣬ֻ���������������������ֵ
        // ����������£����·�������������Ѱ�ҽ��
        return max_single;
    }

private:
    int result;
};

int main(int argc, char* argv[])
{
    return 0;
}
