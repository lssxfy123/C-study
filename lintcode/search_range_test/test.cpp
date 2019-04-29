// Copyright 2019.���|�|
// author�����|�|
// �����������������
#include <iostream>
#include <stack>
#include <vector>
#include "..\include\treenode.hpp"
using namespace std;

// ���ƶԶ����������������
vector<int> searchRange(TreeNode * root, int k1, int k2) {
	// write your code here
	vector<int> result;
	if (root == nullptr || k1 > k2)
	{
		return result;
	}

	// ���ݶ�����������ص�
	// ���root���С��k1���������������϶���С��k1
	while (root != nullptr && root->val < k1)
	{
		root = root->right;
	}

	if (root == nullptr)
	{
		return result;
	}

	// ���root������k2���������������϶�������k2
	while (root != nullptr && root->val > k2)
	{
		root = root->left;
	}

	if (root == nullptr)
	{
		return result;
	}

	stack<TreeNode*> tree_stack;

	// Ҫ����Ϊ�������У����Խ����������
	while (root != nullptr)
	{
		tree_stack.push(root);
		root = root->left;
	}

	while (tree_stack.size() > 0)
	{
		TreeNode* tmp = tree_stack.top();
		tree_stack.pop();
		if (tmp->val >= k1 && tmp->val <= k2)
		{
			result.push_back(tmp->val);
		}
		TreeNode* right = tmp->right;
		if (right != nullptr)
		{
			tmp = right;
			while (tmp != nullptr && tmp->val < k1)
			{
				tmp = tmp->right;
			}

			if (tmp == nullptr)
			{
				continue;
			}

			while (tmp != nullptr && tmp->val > k2)
			{
				tmp = tmp->left;
			}

			if (tmp == nullptr)
			{
				continue;
			}

			while (tmp != nullptr)
			{
				tree_stack.push(tmp);
				tmp = tmp->left;
			}
		}
	}

	return result;
}

int main(int argc, char* argv[])
{
	string tree = "{20,8,22,4,12}";
	TreeNode* root = Deserialize(tree);
	vector<int> vec = searchRange(root, 10, 22);
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	return 0;
}
