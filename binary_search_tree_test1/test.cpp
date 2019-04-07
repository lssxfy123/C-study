// Copyright 2016.刘珅珅
// author：刘珅珅
// 二叉查找树
#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <regex>
#include <iterator>
using namespace std;

template <typename Object, typename Comparator = less<Object> >
class BinarySearchTree
{
public:
    BinarySearchTree()
    {
        root_ = NULL;
    }

    BinarySearchTree(const BinarySearchTree& rhs)
    {
        root_ = Clone(rhs.root_);
    }

    ~BinarySearchTree()
    {
        MakeEmpty();
    }

    const Object& FindMin() const
    {
        if (root_ == nullptr)
        {
            throw std::runtime_error("binary search tree is null");
        }
        return FindMin(root_)->element_;
    }

    const Object& FindMax() const
    {
        if (root_ == nullptr)
        {
            throw std::runtime_error("binary search tree is null");
        }
        return FindMax(root_)->element_;
    }

    bool Contains(const Object& x) const;

    bool IsEmpty() const
    {
        return root_ == NULL;
    }

    bool IsBalanced() const
    {
        IsBalanced(root_);
    }

    void PrintTree() const
    {
        PrintTree(root_);
    }

    void PrintTreeNoRecursion() const
    {
        PrintTreeNoRecursion(root_);
    }

    void PrePrintTree() const
    {
        PrePrintTree(root_);
    }

    void PrePrintTreeNoRecursion() const
    {
        PrePrintTreeNoRecursion(root_);
    }

    void PostPrintTree() const
    {
        PostPrintTree(root_);
    }

    void PostPrintTreeNoRecursion() const
    {
        PostPrintTreeNoRecursion(root_);
    }

    void LevelPrintTree() const
    {
        LevelPrintTree(root_);
    }

    void LevelPrintTreeNoRecursion() const
    {
        LevelPrintTreeNoRecursion(root_);
    }

    void MakeEmpty()
    {
        MakeEmpty(root_);
    }
    void Insert(const Object& x)
    {
        Insert(x, root_);
    }

    void InsertNoRecursion(const Object& x)
    {
        root_ = InsertNoRecursion(x, root_);
    }

    void Remove(const Object& x)
    {
        Remove(x, root_);
    }

    void RemoveNoRecursion(const Object& x)
    {
        root_ = RemoveNoRecursion(x, root_);
    }

	string Serialize() const
	{
		return Serialize(root_);
	}

	void Deserialize(string& data)
	{
		if (data == "{}")
		{
			root_ = nullptr;
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
		for (int i = 0; i < res.size(); ++i)
		{
			cout << res[i] << " ";
		}
		cout << endl;

		root_ = Deserialize(res);
	}

    const BinarySearchTree& operator= (const BinarySearchTree& rhs)
    {
        if (this != &rhs)
        {
            MakeEmpty();
            root_ = Clone(rhs.root_);
        }
        return *this;
    }

private:
    struct BinaryNode
    {
        Object element_;
        BinaryNode* left_;
        BinaryNode* right_;

        BinaryNode(const Object& element, BinaryNode* lt, BinaryNode* rt)
        : element_(element), left_(lt), right_(rt) {}
    };

    // 时间复杂度为O(n*logn)，结点的高度会被重复计算
    bool IsBalanced(BinaryNode* root) const
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftHeight = GetHeight(root->left_);
        int rightHeight = GetHeight(root->right_);
        if (abs(leftHeight - rightHeight) > 1)
        {
            return false;
        }
        return IsBalanced(root->left_) && IsBalanced(root->right_);
    }

    bool IsBalanced2(BinaryNode* root) const
    {
        return GetHeight2(root) == -1 ? false : true;
    }


    int GetHeight(BinaryNode* root) const 
    {
        if (root == nullptr)
        {
            return 0;
        }
        int height = max(GetHeight(root->left_), GetHeight(root->right_)) + 1;
    }

    // 时间复杂度为O(n)，所有结点都只会被计算一次
    int GetHeight2(BinaryNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftHeight = GetHeight2(root->left_);
        if (leftHeight == -1)
        {
            return -1;
        }

        int rightHeight = GetHeight2(root->right_);
        if (rightHeight == -1)
        {
            return -1;
        }

        if (abs(leftHeight - rightHeight) > 1)
        {
            return -1;
        }

        return max(leftHeight, rightHeight) + 1;
    }

    // 使用了指针的引用
    // 在递归调用过程中，修改t的指向会改变外层的t的指向，从而形成树
    void Insert(const Object& x, BinaryNode*& t) const
    {
        if (t == NULL)
        {
            t = new BinaryNode(x, NULL, NULL);
        } else if (IsLessThan(x, t->element_))
        {
            Insert(x, t->left_);
        } else if (IsLessThan(t->element_, x))
        {
            Insert(x, t->right_);
        }

        // 可以看出这个插入函数没法插入重复元
    }

    // 非递归插入
    BinaryNode* InsertNoRecursion(const Object& x, BinaryNode* root) const
    {
        if (root == nullptr)
        {
            root = new BinaryNode(x, nullptr, nullptr);
            return root;
        }

        BinaryNode* node = new BinaryNode(x, nullptr, nullptr);
        BinaryNode* tmp = root;
        while (true)
        {
            if (tmp->element_ > x)
            {
                if (tmp->left_ == nullptr)
                {
                    tmp->left_ = node;
                    return root;
                }
                tmp = tmp->left_;
            }
            else
            {
                if (tmp->right_ == nullptr)
                {
                    tmp->right_ = node;
                    return root;
                }
                tmp = tmp->right_;
            }
        }
    }

    void Remove(const Object& x, BinaryNode*& t) const
    {
        if (t == NULL)
        {
            return;
        }

        // 在const函数中不能修改类成员变量
        // 但对于指针而言，可以改变其指向的对象
        // root_ = nullptr;  // error

        if (IsLessThan(x, t->element_))
        {
            Remove(x, t->left_);
        } else if (IsLessThan(t->element_, x))
        {
            Remove(x, t->right_);
        } else if (t->left_ != NULL && t->right_ != NULL)  // 两个子结点
        {
            // 用右子树的最小结点代替该结点，
            // 以保证二叉查找树，结点数据必须小于其右子树全部结点数据的性质
            // 然后删除右子树的最小结点
            t->element_ = FindMin(t->right_)->element_;
            Remove(t->element_, t->right_);
            cout << "two children" << endl;
        } 
        else   // 一个子结点或没有子结点
        {
            BinaryNode* old = t;
            t = (t->left_ != NULL)?t->left_:t->right_;
            delete old;
        }
    }

    BinaryNode* RemoveNoRecursion(const Object& x, BinaryNode* root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        BinaryNode* tmp = root;
        while (tmp != nullptr)
        {
            if (tmp->element_ < x)
            {
                tmp = tmp->right_;
            }
            else if (tmp->element_ > x)
            {
                tmp = tmp->left_;
            }
            else
            {
                if (tmp->left_ != nullptr && tmp->right_ != nullptr)
                {
                    BinaryNode* delete_node = tmp->right_;
                    BinaryNode* parent = tmp;
                    while (delete_node->left_ != nullptr)
                    {
                        parent = delete_node;
                        delete_node = delete_node->left_;
                    }
                    tmp->element_ = delete_node->element_;

                    // 如果待删除结点为其父结点的左孩子
                    // delete_node没有左孩子
                    if (parent->left_ == delete_node)
                    {
                        parent->left_ = delete_node->right_;
                    }
                    else
                    {
                        parent->right_ = delete_node->right_;
                    }
                    
                    delete delete_node;
                    break;
                }
                else
                {
                    BinaryNode* old = tmp;
                    tmp = (tmp->left_ != nullptr) ? tmp->left_ : tmp->right_;
                    delete old;
                    break;
                }
            }
        }
        return root;
    }

    BinaryNode* FindMin(BinaryNode* t) const
    {
        if (t == NULL)
        {
            return NULL;
        }

        if (t->left_ == NULL)
        {
            return t;
        }

        return FindMin(t->left_);
    }

    BinaryNode* FindMax(BinaryNode* t) const
    {
        if (t != NULL)
        {
            while (t->right_ != NULL)
            {
                t = t->right_;
            }
        }
        return t;
    }
    bool Contains(const Object& x, BinaryNode* t) const
    {
        if (t == NULL)
        {
            return false;
        } else if (IsLessThan(x, t->element_)) {
            return Contains(x, t->left_);
        } else if (IsLessThan(t->element_, x)) {
            return Contains(x, t->right_);
        } else {
            return true;
        }
    }

    void MakeEmpty(BinaryNode*& t)
    {
        if (t != NULL)
        {
            MakeEmpty(t->left_);
            MakeEmpty(t->right_);
            delete t;
            t = NULL;
        }
    }

    // 中序遍历
    // 左子树->根->右子树
    void PrintTree(BinaryNode* t) const
    {
        if (t == NULL)
        {
            return;
        }

        PrintTree(t->left_);
        cout << t->element_ << ' ';
        PrintTree(t->right_);
    }

    // 非递归中序遍历
    // 核心思想是将树的根结点与左孩子压入栈，
    // 先压根结点，再压左孩子，因为栈先进后出，
    // 如果结点有右孩子，将右孩子看成根结点，
    // 循环之前的操作
    void PrintTreeNoRecursion(BinaryNode* root) const
    {
        if (root == nullptr)
        {
            return;
        }

        stack<BinaryNode*> tree_stack;
        BinaryNode* right = root->right_;
        BinaryNode* left = root->left_;
        tree_stack.push(root);

        // 将根结点与其左孩子压入栈
        while (left != nullptr)
        {
            tree_stack.push(left);
            root = left->left_;  // t,t->left_都已在 栈中，所以是left->left_
            if (root != nullptr)
            {
                tree_stack.push(root);
                left = root->left_;
            }
            else
            {
                break;
            }
        }

        while (tree_stack.size() > 0)
        {
            BinaryNode* tmp = tree_stack.top();
            tree_stack.pop();
            cout << tmp->element_ << ' ';
            right = tmp->right_;
            if (right != nullptr)
            {
                // 将右孩子看成根结点
                // 将根结点与左孩子压入栈
                tmp = right;
                left = tmp->left_;
                right = tmp->right_;
                tree_stack.push(tmp);
                while (left != nullptr)
                {
                    tree_stack.push(left);
                    tmp = left->left_;
                    if (tmp != nullptr)
                    {
                        tree_stack.push(tmp);
                        left = tmp->left_;
                        right = tmp->right_;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

    }

    // 前序遍历
    // 根->左子树->右子树
    void PrePrintTree(BinaryNode* t) const
    {
        if (t == NULL)
        {
            return;
        }

        cout << t->element_ << ' ';
        PrePrintTree(t->left_);
        PrePrintTree(t->right_);
    }

    // 非递归前序遍历
    // 将根结点压入栈中
    // 弹出栈顶元素并输出
    // 如果其右孩子不为空，压入栈
    // 如果其左孩子不为空，输出并
    // 遍历其左子树，将每个结点的左
    // 孩子输出，右孩子压入栈
    void PrePrintTreeNoRecursion(BinaryNode* t) const
    {
        if (t == nullptr)
        {
            return;
        }

        stack<BinaryNode*> tree_stack;
        BinaryNode* left = nullptr;
        BinaryNode* right = nullptr;
        tree_stack.push(t);

        while (tree_stack.size() > 0)
        {
            BinaryNode* tmp = tree_stack.top();
            tree_stack.pop();
            cout << tmp->element_ << ' ';
            left = tmp->left_;
            right = tmp->right_;
            if (right != nullptr)
            {
                tree_stack.push(right);
            }

            while (left != nullptr)
            {
                cout << left->element_ << ' ';
                tmp = tmp->left_;
                left = tmp->left_;
                right = tmp->right_;
                if (right != nullptr)
                {
                    tree_stack.push(right);
                }
            }
        }
    }

    // 后序遍历
    // 左子树->右子树->根
    void PostPrintTree(BinaryNode* t) const
    {
        if (t == NULL)
        {
            return;
        }

        PostPrintTree(t->left_);
        PostPrintTree(t->right_);
        cout << t->element_ << ' ';
    }

    void PostPrintTreeNoRecursion(BinaryNode* root) const
    {
        if (root == nullptr)
        {
            return;
        }

        BinaryNode* tmp = root;
        BinaryNode* assist = nullptr;  // 辅助结点
        stack<BinaryNode*> tree_stack;

        // 核心思想:由于后序遍历是左子树->右子树->根
        // 根结点不为nullptr，将其压入栈中，并将其左子结点
        // 也压入栈中，访问栈顶元素时，如果其右子树存在，则
        // 将其右孩子看成根结点并重复之前的压栈操作
        // 需要辅助元素assist的原因是:某结点右子树存在，需要
        // 再次进行压栈操作，该结点并未出栈，后续还会再次访问
        // 到该结点，利用栈后进先出的特性，访问到该元素之前弹出
        // 的栈元素肯定为该结点的右孩子，以此来判断是否已遍历过
        // 其右子树
        while (tmp != nullptr || !tree_stack.empty())
        {
            if (tmp != nullptr)
            {
                // 记录tmp的所有左子结点
                tree_stack.push(tmp);
                tmp = tmp->left_;
            }
            else
            {
                tmp = tree_stack.top();

                // 右子树存在且未被访问
                if (tmp->right_ != nullptr
                    && tmp->right_ != assist)
                {
                    tmp = tmp->right_;
                }
                else
                {
                    tree_stack.pop();
                    cout << tmp->element_ << ' ';
                    assist = tmp;
                    tmp = nullptr;
                }
            }
        }
    }

    // 层次遍历
    void LevelPrintTree(BinaryNode* root) const
    {
        vector<vector<Object>> result;
        unordered_map<int, vector<Object>> level_map;
        DFS(root, 1, level_map);
        for (int i = 1; i <= level_map.size(); ++i)
        {
            result.push_back(level_map[i]);
        }
    }

    void DFS(BinaryNode* node, int level,unordered_map<int, vector<Object>>& level_map) const
    {
        if (node == nullptr)
        {
            return;
        }

        if (level_map.find(level) != level_map.end())
        {
            level_map[level].push_back(node->element_);
        }
        else
        {
            vector<Object> level_result;
            level_result.push_back(node->element_);
            level_map.insert(pair<int, vector<Object>>(level, level_result));
        }

        DFS(node->left_, level + 1, level_map);
        DFS(node->right_, level + 1, level_map);

    }

    void LevelPrintTreeNoRecursion(BinaryNode* root) const
    {
        vector<vector<Object>> result;
        if (root == nullptr)
        {
            return;
        }

        queue<BinaryNode*> node_queue;
        node_queue.push(root);
        while (!node_queue.empty())
        {
            int size = node_queue.size();
            vector<Object> level_result;

            // 循环的结束值是size，即上个
            // 循环插入的结点数目，由于二叉树
            // 每个结点最多有两个子结点，所以
            // 一次循环就将其左右子结点都入队，
            // 循环完毕后其实是将下一层的所有子
            // 结点都入队
            for (int i = 0; i < size; ++i)
            {
                BinaryNode* head = node_queue.front();
                node_queue.pop();
                level_result.push_back(head->element_);
                if (head->left_ != nullptr)
                {
                    node_queue.push(head->left_);
                }

                if (head->right_ != nullptr)
                {
                    node_queue.push(head->right_);
                }
            }

            result.push_back(level_result);
        }
    }

	string Serialize(BinaryNode* root) const
	{
		string result = {};
		if (root == nullptr)
		{
			return result;
		}

		vector<BinaryNode*> array;
		array.push_back(root);

		// 类似二叉树的层次遍历，但不需要遍历输出，
	    // 所以不需要使用queue
		for (int i = 0; i < array.size(); ++i)
		{
			BinaryNode* node = array[i];
			if (node == nullptr)
			{
				continue;
			}

			array.push_back(node->left_);
			array.push_back(node->right_);
		}

		// 去掉末尾的nullptr
		while (array.size() > 0 && array.back() == nullptr)
		{
			array.pop_back();
		}

		stringstream ss;
		ss << "{";
		for (int i = 0; i < array.size(); ++i)
		{
			if (array[i] == nullptr)
			{
				ss << "#,";
			}
			else
			{
				if (i < array.size() - 1)
					ss << array[i]->element_ << ",";
				else
					ss << array[i]->element_;
			}
		}
		ss << "}";
		result = ss.str();
		return result;
	}

	Object Convert(const string & t) {
		stringstream stream;
		stream << t;  // 向流中传值
		Object result;  // 这里存储转换结果
		stream >> result;  // 向result中写入值
		return result;
	}

	BinaryNode* Deserialize(vector<string>& nodes)
	{
		if (nodes.size() == 0)
		{
			return nullptr;
		}

		BinaryNode* root = new BinaryNode(Convert(nodes[0]), nullptr, nullptr);
		bool is_left_child = true;

		// 反序列化的思想：
		// 将根结点插入队列中，然后判断下一个nodes字符串是否是有效结点
		// 如果不为"#"，就当成上一个结点的左孩子，再下一个就是右孩子
		// 然后把根结点出队，序列化是按层序列的
		queue<BinaryNode*> node_queue;
		node_queue.push(root);
		for (int i = 1; i < nodes.size(); ++i)
		{
			if (nodes[i] != "#")
			{
				BinaryNode* node = new BinaryNode(Convert(nodes[i]), nullptr, nullptr);
				if (is_left_child)
				{
					node_queue.front()->left_ = node;
				}
				else
				{
					node_queue.front()->right_ = node;
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

    BinaryNode* Clone(BinaryNode* t) const
    {
        if (t == NULL)
        {
            return NULL;
        }

        return new BinaryNode(t->element_, Clone(t->left_), Clone(t->right_));
    }

private:
    BinaryNode* root_;
    Comparator IsLessThan;
};

template<typename Object, typename Comparator> 
bool BinarySearchTree<Object, Comparator>:: Contains(const Object& x) const
{
    return Contains(x, root_);
}

int main(int argc, char* argv[])
{
    BinarySearchTree<float> binary_search_tree;
    BinarySearchTree<float> binary_search_tree1;
    binary_search_tree.Insert(3.2f);
    binary_search_tree.Insert(3.5f);
    binary_search_tree.Insert(3.3f);
    binary_search_tree.Insert(4.6f);
    binary_search_tree.Insert(3.9f);
    binary_search_tree.Insert(5.1f);
    binary_search_tree.Insert(2.9f);
    binary_search_tree.Insert(5.4f);

    binary_search_tree1.InsertNoRecursion(3.2f);
    binary_search_tree1.InsertNoRecursion(3.5f);
    binary_search_tree1.InsertNoRecursion(3.3f);
    binary_search_tree1.InsertNoRecursion(4.6f);
    binary_search_tree1.InsertNoRecursion(2.9f);
    binary_search_tree1.InsertNoRecursion(5.4f);

	string serialize = binary_search_tree1.Serialize();
	BinarySearchTree<float> deserialize_tree;

	cout << "序列化二叉树: " << serialize  << endl;
	deserialize_tree.Deserialize(serialize);
	cout << "反序列化二叉树: " << endl;
	deserialize_tree.PrintTree() ;
	cout << endl;

    cout << "中序遍历：左子树->根->右子树" << endl;
    binary_search_tree.PrintTree();
    cout << endl;
    binary_search_tree.PrintTreeNoRecursion();
    cout << endl;
    binary_search_tree1.PrintTree();
    cout << endl;
    cout << "前序遍历：根->左子树->右子树" << endl;
    binary_search_tree.PrePrintTree();
    cout << endl;
    binary_search_tree.PrePrintTreeNoRecursion();
    cout << endl;
    cout << "后序遍历：左子树->右子树->根" << endl;
    binary_search_tree.PostPrintTree();
    cout << endl;
    binary_search_tree.PostPrintTreeNoRecursion();
    cout << endl;
    cout << "层次遍历" << endl;
    binary_search_tree.LevelPrintTree();

    cout << "删除测试" << endl;
    binary_search_tree.RemoveNoRecursion(3.5f);
    cout << "删除后的中序遍历：左子树->根->右子树" << endl;
    binary_search_tree.PrintTree();
    cout << endl;
    binary_search_tree1.RemoveNoRecursion(3.5f);
    cout << "删除后的中序遍历：左子树->根->右子树" << endl;
    binary_search_tree1.PrintTree();
    cout << endl;

    if (binary_search_tree.Contains(3.2f))
    {
        cout << "exist" << endl;
    } else {
        cout << "not exist" << endl;
    }

    if (binary_search_tree.Contains(3.1f))
    {
        cout << "exist" << endl;
    } else {
        cout << "not exist" << endl;
    }

    cout << "Min " << binary_search_tree.FindMin() << endl;
    cout << "Max " << binary_search_tree.FindMax() << endl;

    BinarySearchTree<float> binary_search_tree2(binary_search_tree);
    binary_search_tree2.PrintTree();
    cout << endl;

    BinarySearchTree<float> binary_search_tree3;
    binary_search_tree3 = binary_search_tree;
    binary_search_tree3.PrintTree();
    cout << endl;

    binary_search_tree3.Remove(3.5f);
    binary_search_tree3.PrintTree();
    cout << endl;
    return 0;
}
