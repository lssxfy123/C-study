// Copyright 2019.���|�|
// author�����|�|
// ��������ͺ�����������������
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
            this->val = val;
            this->left = this->right = nullptr;
        }
};

TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
    // write your code here
    TreeNode* root = nullptr;
    if (inorder.size() == 0 || postorder.size() == 0 || inorder.size() != postorder.size())
    {
        return root;
    }

    // ������������һ��Ԫ���Ǹ�
    root = new TreeNode(postorder.back());
    int root_index = -1;  // ��������ĸ��������
    for (int i = 0; i < inorder.size(); ++i)
    {
        if (inorder[i] == root->val)
        {
            root_index = i;
            break;
        }
    }

    if (root_index < 0)
    {
        return nullptr;
    }

    vector<int> inorder_left, inorder_right;
    vector<int> postorder_left, postorder_right;

    // ���������������ߵĿ϶��Ǹ�����������Ԫ��
    // ������-��-������
    // ���������������-������-��
    for (int i = 0; i < root_index; ++i)
    {
        inorder_left.push_back(inorder[i]);

        // 0-root_index-1Ϊ�������ĺ������
        postorder_left.push_back(postorder[i]);
    }

    // ��������������ұߵĿ϶��Ǹ�����������Ԫ��
    for (int i = root_index + 1; i < inorder.size(); ++i)
    {
        inorder_right.push_back(inorder[i]);

        // �������ĺ��������postorder���һ��Ԫ��Ϊ����������i-1
        postorder_right.push_back(postorder[i - 1]);
    }

    root->left = buildTree(inorder_left, postorder_left);
    root->right = buildTree(inorder_right, postorder_right);
    return root;
}

TreeNode * buildTree1(vector<int> &preorder, vector<int> &inorder) {
    // write your code here
    TreeNode* root = nullptr;
    if (preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size())
    {
        return root;
    }

    root = new TreeNode(preorder[0]);
    int root_index = -1;
    for (int i = 0; i < inorder.size(); ++i)
    {
        if (inorder[i] == root->val)
        {
            root_index = i;
            break;
        }
    }

    vector<int> inorder_left, inorder_right;
    vector<int> preorder_left, preorder_right;
    for (int i = 0; i < root_index; ++i)
    {
        inorder_left.push_back(inorder[i]);
        preorder_left.push_back(preorder[i + 1]);
    }

    for (int i = root_index + 1; i < inorder.size(); ++i)
    {
        inorder_right.push_back(inorder[i]);
        preorder_right.push_back(preorder[i]);
    }

    root->left = buildTree1(preorder_left, inorder_left);
    root->right = buildTree1(preorder_right, inorder_right);
    return root;
}

int main(int argc, char* argv[])
{
    return 0;
}
