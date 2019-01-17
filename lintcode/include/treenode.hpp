#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <regex>
#include <iterator>
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

int Convert(const string & t) {
	stringstream stream;
	stream << t;  // �����д�ֵ
	int result;  // ����洢ת�����
	stream >> result;  // ��result��д��ֵ
	return result;
}

TreeNode* Deserialize(string& data)
{
	if (data == "{}")
	{
		return nullptr;
	}

	if (data.back() == '}')
	{
		data.pop_back();
	}

	if (data.front() == '{')
	{
		data.erase(data.begin());
	}

	regex re{ "," };
	vector<string> res(sregex_token_iterator(data.begin(), data.end(), re, -1), sregex_token_iterator());

	if (res.size() == 0)
	{
		return nullptr;
	}

	TreeNode* root = new TreeNode(Convert(res[0]));
	bool is_left_child = true;

	// �����л���˼�룺
	// ��������������У�Ȼ���ж���һ��nodes�ַ����Ƿ�����Ч���
	// �����Ϊ"#"���͵�����һ���������ӣ�����һ�������Һ���
	// Ȼ��Ѹ������ӣ����л��ǰ������е�
	queue<TreeNode*> node_queue;
	node_queue.push(root);
	for (int i = 1; i < res.size(); ++i)
	{
		if (res[i] != "#")
		{
			TreeNode* node = new TreeNode(Convert(res[i]));
			if (is_left_child)
			{
				node_queue.front()->left = node;
			}
			else
			{
				node_queue.front()->right = node;
			}
			node_queue.push(node);
		}

		if (!is_left_child)
		{
			node_queue.pop();
		}
		is_left_child = !is_left_child;  // ���ӵ���һ�������Һ���
	}
	return root;
}

#endif // TREENODE_H
