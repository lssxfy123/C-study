// Copyright 2019.刘珅珅
// author：刘珅珅
// 不同的子序列
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

class Solution {
public:
    /**
    * @paramn n: An integer
    * @return: A list of root
    */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        vector<TreeNode*> result;
        result = generateTrees(0, n - 1);
        return result;
    }

    //构建start到end所有不同的二叉树
    vector<TreeNode *> generateTrees(int start, int end) {
        // write your code here
        vector<TreeNode*> result;
        if (start > end)
        {
            result.push_back(nullptr);
            return result;
        }

        //对于i,左子树为start到i-1,右子树为i+1到end
        //并且遍历左右子树的每一种情况
        for (int i = start; i <= end; ++i)
        {
            vector<TreeNode*> left = generateTrees(start, i - 1);
            vector<TreeNode*> right = generateTrees(i + 1, end);
            for (int j = 0; j < left.size(); ++j)
            {
                for (int k = 0; k < right.size(); ++k)
                {
                    TreeNode* node = new TreeNode(i + 1);
                    result.push_back(node);
                    node->left = left[j];
                    node->right = right[k];
                }
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    return 0;
}
