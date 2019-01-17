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
	stream << t;  // 向流中传值
	int result;  // 这里存储转换结果
	stream >> result;  // 向result中写入值
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

	// 反序列化的思想：
	// 将根结点插入队列中，然后判断下一个nodes字符串是否是有效结点
	// 如果不为"#"，就当成上一个结点的左孩子，再下一个就是右孩子
	// 然后把根结点出队，序列化是按层序列的
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
		is_left_child = !is_left_child;  // 左孩子的下一个就是右孩子
	}
	return root;
}

#endif // TREENODE_H
