// Copyright 2019.���|�|
// author�����|�|
// ��ͬ��������
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

    //����start��end���в�ͬ�Ķ�����
    vector<TreeNode *> generateTrees(int start, int end) {
        // write your code here
        vector<TreeNode*> result;
        if (start > end)
        {
            result.push_back(nullptr);
            return result;
        }

        //����i,������Ϊstart��i-1,������Ϊi+1��end
        //���ұ�������������ÿһ�����
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
