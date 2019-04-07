// Copyright 2016.���|�|
// author�����|�|
// ���������
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

    // ʱ�临�Ӷ�ΪO(n*logn)�����ĸ߶Ȼᱻ�ظ�����
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

    // ʱ�临�Ӷ�ΪO(n)�����н�㶼ֻ�ᱻ����һ��
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

    // ʹ����ָ�������
    // �ڵݹ���ù����У��޸�t��ָ���ı�����t��ָ�򣬴Ӷ��γ���
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

        // ���Կ���������뺯��û�������ظ�Ԫ
    }

    // �ǵݹ����
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

        // ��const�����в����޸����Ա����
        // ������ָ����ԣ����Ըı���ָ��Ķ���
        // root_ = nullptr;  // error

        if (IsLessThan(x, t->element_))
        {
            Remove(x, t->left_);
        } else if (IsLessThan(t->element_, x))
        {
            Remove(x, t->right_);
        } else if (t->left_ != NULL && t->right_ != NULL)  // �����ӽ��
        {
            // ������������С������ý�㣬
            // �Ա�֤�����������������ݱ���С����������ȫ��������ݵ�����
            // Ȼ��ɾ������������С���
            t->element_ = FindMin(t->right_)->element_;
            Remove(t->element_, t->right_);
            cout << "two children" << endl;
        } 
        else   // һ���ӽ���û���ӽ��
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

                    // �����ɾ�����Ϊ�丸��������
                    // delete_nodeû������
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

    // �������
    // ������->��->������
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

    // �ǵݹ��������
    // ����˼���ǽ����ĸ����������ѹ��ջ��
    // ��ѹ����㣬��ѹ���ӣ���Ϊջ�Ƚ������
    // ���������Һ��ӣ����Һ��ӿ��ɸ���㣬
    // ѭ��֮ǰ�Ĳ���
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

        // ���������������ѹ��ջ
        while (left != nullptr)
        {
            tree_stack.push(left);
            root = left->left_;  // t,t->left_������ ջ�У�������left->left_
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
                // ���Һ��ӿ��ɸ����
                // �������������ѹ��ջ
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

    // ǰ�����
    // ��->������->������
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

    // �ǵݹ�ǰ�����
    // �������ѹ��ջ��
    // ����ջ��Ԫ�ز����
    // ������Һ��Ӳ�Ϊ�գ�ѹ��ջ
    // ��������Ӳ�Ϊ�գ������
    // ����������������ÿ��������
    // ����������Һ���ѹ��ջ
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

    // �������
    // ������->������->��
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
        BinaryNode* assist = nullptr;  // �������
        stack<BinaryNode*> tree_stack;

        // ����˼��:���ں��������������->������->��
        // ����㲻Ϊnullptr������ѹ��ջ�У����������ӽ��
        // Ҳѹ��ջ�У�����ջ��Ԫ��ʱ����������������ڣ���
        // �����Һ��ӿ��ɸ���㲢�ظ�֮ǰ��ѹջ����
        // ��Ҫ����Ԫ��assist��ԭ����:ĳ������������ڣ���Ҫ
        // �ٴν���ѹջ�������ý�㲢δ��ջ�����������ٴη���
        // ���ý�㣬����ջ����ȳ������ԣ����ʵ���Ԫ��֮ǰ����
        // ��ջԪ�ؿ϶�Ϊ�ý����Һ��ӣ��Դ����ж��Ƿ��ѱ�����
        // ��������
        while (tmp != nullptr || !tree_stack.empty())
        {
            if (tmp != nullptr)
            {
                // ��¼tmp���������ӽ��
                tree_stack.push(tmp);
                tmp = tmp->left_;
            }
            else
            {
                tmp = tree_stack.top();

                // ������������δ������
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

    // ��α���
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

            // ѭ���Ľ���ֵ��size�����ϸ�
            // ѭ������Ľ����Ŀ�����ڶ�����
            // ÿ���������������ӽ�㣬����
            // һ��ѭ���ͽ��������ӽ�㶼��ӣ�
            // ѭ����Ϻ���ʵ�ǽ���һ���������
            // ��㶼���
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

		// ���ƶ������Ĳ�α�����������Ҫ���������
	    // ���Բ���Ҫʹ��queue
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

		// ȥ��ĩβ��nullptr
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
		stream << t;  // �����д�ֵ
		Object result;  // ����洢ת�����
		stream >> result;  // ��result��д��ֵ
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

		// �����л���˼�룺
		// ��������������У�Ȼ���ж���һ��nodes�ַ����Ƿ�����Ч���
		// �����Ϊ"#"���͵�����һ���������ӣ�����һ�������Һ���
		// Ȼ��Ѹ������ӣ����л��ǰ������е�
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
			is_left_child = !is_left_child;  // ���ӵ���һ�������Һ���
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

	cout << "���л�������: " << serialize  << endl;
	deserialize_tree.Deserialize(serialize);
	cout << "�����л�������: " << endl;
	deserialize_tree.PrintTree() ;
	cout << endl;

    cout << "���������������->��->������" << endl;
    binary_search_tree.PrintTree();
    cout << endl;
    binary_search_tree.PrintTreeNoRecursion();
    cout << endl;
    binary_search_tree1.PrintTree();
    cout << endl;
    cout << "ǰ���������->������->������" << endl;
    binary_search_tree.PrePrintTree();
    cout << endl;
    binary_search_tree.PrePrintTreeNoRecursion();
    cout << endl;
    cout << "���������������->������->��" << endl;
    binary_search_tree.PostPrintTree();
    cout << endl;
    binary_search_tree.PostPrintTreeNoRecursion();
    cout << endl;
    cout << "��α���" << endl;
    binary_search_tree.LevelPrintTree();

    cout << "ɾ������" << endl;
    binary_search_tree.RemoveNoRecursion(3.5f);
    cout << "ɾ��������������������->��->������" << endl;
    binary_search_tree.PrintTree();
    cout << endl;
    binary_search_tree1.RemoveNoRecursion(3.5f);
    cout << "ɾ��������������������->��->������" << endl;
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
