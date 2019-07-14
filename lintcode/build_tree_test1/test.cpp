// Copyright 2019.刘珅珅
// author：刘珅珅
// 中序遍历和后序遍历树构造二叉树
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

    // 后序遍历的最后一个元素是根
    root = new TreeNode(postorder.back());
    int root_index = -1;  // 中序遍历的根结点索引
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

    // 中序遍历根索引左边的肯定是根结点的左子树元素
    // 左子树-根-右子树
    // 后序遍历：左子树-右子树-根
    for (int i = 0; i < root_index; ++i)
    {
        inorder_left.push_back(inorder[i]);

        // 0-root_index-1为左子树的后序遍历
        postorder_left.push_back(postorder[i]);
    }

    // 中序遍历根索引右边的肯定是根结点的右子树元素
    for (int i = root_index + 1; i < inorder.size(); ++i)
    {
        inorder_right.push_back(inorder[i]);

        // 右子树的后序遍历，postorder最后一个元素为根，所以是i-1
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
