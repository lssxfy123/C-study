// Copyright 2019.刘珅珅
// author：刘珅珅
// 二叉树中的最大路径和
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
        // 如果最大路径通过某一结点，分几种情况：
        // 1.是从该结点的左孩子到达该结点，
        // 2.从该结点的右孩子到达该结点，
        // 3.通过左孩子->该结点->右孩子
        // 4.该结点就是路径的起点或终点，不延伸到其子结点树
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
            // 以左孩子为终点的子path
            left_sum = getPath(root->left);
        }

        if (root->right != nullptr)
        {
            // 以右孩子为终点的子path
            right_sum = getPath(root->right);
        }

        // 取路径通过左孩子->根结点，右孩子->根结点，只包含根结点三种情况的最大值
        int max_single = max(max(left_sum, right_sum) + root->val, root->val);

        // 左孩子->根->右结点的路径和与上述三种情况比较
        // 左孩子->根->右孩子不需要递归时向上层返回，因为这种情况的最大路径中
        // 不会再包含上层结点了
        int max_top = max(max_single, left_sum + right_sum + root->val);
        result = max(result, max_top);

        // 返回值取路径通过左孩子->根结点，右孩子->根结点，只包含根结点三种情况的最大值
        // 这三种情况下，最大路径还会继续向上寻找结点
        return max_single;
    }

private:
    int result;
};

int main(int argc, char* argv[])
{
    return 0;
}
