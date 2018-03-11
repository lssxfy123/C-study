// Copyright 2018.���|�|
// author�����|�|
// �Զ�������չ��
#include <algorithm>
#include <iostream>
using namespace std;

template<typename T, typename Comparator = less<T>>
class SplayTree
{
public:
    SplayTree()
    {
        root_ = nullptr;
        //null_node_ = new SplayTreeNode();
        //null_node_->left_child_ = null_node_->right_child_ = null_node_;
        //root_ = null_node_;
    }

    SplayTree(const SplayTree& rhs)
    {}

    ~SplayTree()
    {
        Destroy();
    }

    const SplayTree& operator=(const SplayTree& rhs)
    {
        return *this;
    }

    void Destroy()
    {
        Destroy(root_);
    }

    bool Find(const T& value)
    {
        return Find(value, root_);
    }

    T FindMin()
    {
        return FindMin(root_);
    }

    T FindMax()
    {
        return FindMax(root_);
    }

    void Insert(const T& value)
    {
        if (nullptr == root_)
        {
            root_ = new SplayTreeNode(value);
            return;
        }

        Splay(value);

        // value��Ӧ�Ľ�㲻����
        if (IsLessThan(value, root_->value_))
        {
            // �����µ�value��㲢��Ϊ�����
            SplayTreeNode* new_node = new SplayTreeNode(value);
            new_node->left_child_ = root_->left_child_;
            new_node->right_child_ = root_;
            root_->left_child_ = nullptr;
            root_ = new_node;
        }
        else if (IsLessThan(root_->value_, value))
        {
            SplayTreeNode* new_node = new SplayTreeNode(value);
            new_node->right_child_ = root_->right_child_;
            new_node->left_child_ = root_;
            root_->right_child_ = nullptr;
            root_ = new_node;
        }
        else
        {
            return;
        }
    }

    void Remove(const T& value)
    {
        if (nullptr == root_)
        {
            return;
        }

        // ��value�����չ�������
        Splay(value);
        SplayTreeNode* del_node;

        // value������
        if (IsLessThan(value, root_->value_) || IsLessThan(root_->value_, value))
        {
            return;
        }

        if (root_->left_child_ == nullptr)
        {
            del_node = root_;
            root_ = root_->right_child_;
        }
        else
        {
            del_node = root_;

            // ��root��������������չ
            // ����value����root�����������н���ֵ
            // ���Ի��root����������ֵ��չ�������
            Splay(value, root_->left_child_);
            root_->left_child_->right_child_ = root_->right_child_;
            root_ = root_->left_child_;
        }

        delete del_node;
    }

    void Print() const
    {
        Print(root_, T(), 0);
    }

    void PrintTree() const
    {
        PrintTree(root_);
    }

    void PrePrintTree() const
    {
        PrePrintTree(root_);
    }

    void PostPrintTree() const
    {
        PostPrintTree(root_);
    }

    void Splay(const T& value)
    {
        Splay(value, root_);
    }

private:
    struct SplayTreeNode
    {
        T value_;
        SplayTreeNode* left_child_;
        SplayTreeNode* right_child_;

        SplayTreeNode(const T& value = T(), SplayTreeNode* left = nullptr, 
            SplayTreeNode* right = nullptr)
            : value_(value), left_child_(left), right_child_(right)
        {}
    };

    void Destroy(SplayTreeNode*& node)
    {
        if (nullptr != node)
        {
            Destroy(node->left_child_);
            Destroy(node->right_child_);
            delete node;
            node = nullptr;
        }
    }

    bool Find(const T& value, SplayTreeNode*& node)
    {
        // ��value��չ�������
        Splay(value, node);

        if (IsLessThan(value, root_->value_) || IsLessThan(root_->value_, value))
        {
            return false;
        }
        return true;
    }

    T FindMin(SplayTreeNode*& node)
    {
        if (node == nullptr)
        {
            throw std::runtime_error("can't find min in SplayTree");
        }

        SplayTreeNode* min_node = node;
        while (nullptr != min_node->left_child_)
        {
            min_node = min_node->left_child_;
        }

        T result = min_node->value_;

        // ��չ
        Splay(result, node);
        return result;
    }

    T FindMax(SplayTreeNode*& node)
    {
        if (node == nullptr)
        {
            throw std::runtime_error("can't find max in SplayTree");
        }

        SplayTreeNode* max_node = node;
        while (nullptr != max_node->right_child_)
        {
            max_node = max_node->right_child_;
        }

        T result = max_node->value_;
        Splay(result, node);
        return result;
    }

    // ����ת
    // �൱�ڡ����ݽṹ���㷨������378ҳ������
    // ��rotateWithRightChild
    void LeftRotation(SplayTreeNode*& node)
    {
        SplayTreeNode* right = node->right_child_;
        node->right_child_ = right->left_child_;
        right->left_child_ = node;
        node = right;  // nodeΪ�����ĸ����
    }

    // ����ת
    // �൱�ڡ����ݽṹ���㷨������378ҳ������
    // ��rotateWithLeftChild
    void RightRotation(SplayTreeNode*& node)
    {
        SplayTreeNode* left = node->left_child_;
        node->left_child_ = left->right_child_;
        left->right_child_ = node;
        node = left;  // nodeΪ�����ĸ����
    }

    // �Զ����ӡ
    void Print(SplayTreeNode* node, const T& value, const int& direction) const
    {
        if (nullptr == node)
        {
            return;
        }

        if (node == root_)
        {
            cout << node->value_ << " is the root" << endl;
        }
        else
        {
            cout << node->value_ << " is " << value << "'s "
                << ((direction == 1) ? "left" : "right") << " son" << endl;
        }

        Print(node->left_child_, node->value_, 1);
        Print(node->right_child_, node->value_, 2);
    }

    // �������
    void PrintTree(SplayTreeNode* node) const
    {
        if (node == nullptr)
        {
            return;
        }

        PrintTree(node->left_child_);
        cout << node->value_ << ' ';
        PrintTree(node->right_child_);
    }

    // ǰ�����
    void PrePrintTree(SplayTreeNode* node) const
    {
        if (node == nullptr)
        {
            return;
        }

        cout << node->value_ << ' ';
        PrePrintTree(node->left_child_);
        PrePrintTree(node->right_child_);
    }

    // �������
    void PostPrintTree(SplayTreeNode* node) const
    {
        if (node == nullptr)
        {
            return;
        }

        PostPrintTree(node->left_child_);
        PostPrintTree(node->right_child_);
        cout << node->value_ << ' ';
    }

    // �Զ�����
    // nodeΪ�����ĸ����
    void Splay(const T& value, SplayTreeNode*& node)
    {
        if (nullptr == node)
        {
            return;
        }

        SplayTreeNode header;
        header.left_child_ = header.right_child_ = nullptr;

        // nodeΪ��ǰ��㣬���������ĸ�����Ϊ�м����
        // left�洢С��node�Ľ�㣬�����洢node�������Ľ��
        // right�洢����node�Ľ�㣬�����洢node�������Ľ��
        // ��ʼ״̬��nodeΪroot��㣬left��right���ǿ���
        SplayTreeNode* Left = &header;
        SplayTreeNode* Right = &header;

        for (;;)
        {
            if (IsLessThan(value, node->value_))
            {
                if (node->left_child_ == nullptr)
                {
                    break;
                }

                if (IsLessThan(value, node->left_child_->value_))
                {
                    // ��ת��Ϊ�˽�value��Ӧ�Ľ�������չ����
                    RightRotation(node);
                    if (node->left_child_ == nullptr)
                    {
                        break;
                    }
                }

                // ���ص�����Right����������
                // node�������������
                // ���ص�Right�ϵı�node->left_child_��
                Right->left_child_ = node;
                Right = node;
                node = node->left_child_;
            }
            else if (IsLessThan(node->value_, value))
            {
                if (node->right_child_ == nullptr)
                {
                    break;
                }

                if (IsLessThan(node->right_child_->value_, value))
                {
                    LeftRotation(node);
                    if (node->right_child_ == nullptr)
                    {
                        break;
                    }
                }

                // ���ص�����Left����������
                // node����������Һ���
                // ���ص�Left�ϵı�node->right_child_С
                Left->right_child_ = node;
                Left = node;
                node = node->right_child_;
            }
            else {
                break;
            }
        }

        // ���С��������
        Left->right_child_ = node->left_child_;
        Right->left_child_ = node->right_child_;

        // header.right_child_ΪLeft��
        node->left_child_ = header.right_child_;

        // header.left_child_ΪRight��
        node->right_child_ = header.left_child_;
    }

private:
    SplayTreeNode* root_;  // �����
    SplayTreeNode* null_node_;  // ����ս��

    Comparator IsLessThan;
};

int main(int argc, char* argv[])
{
    SplayTree<int> splay_tree;
    for (int i = 1; i <= 7; ++i)
    {
        splay_tree.Insert(i);
    }

    splay_tree.Print();
    cout << endl;
    splay_tree.Find(1);
    splay_tree.Print();
    cout << endl;

    // 8������������
    // ���7��չ�������
    splay_tree.Find(8);
    splay_tree.Print();
    cout << endl;

    splay_tree.Remove(7);
    splay_tree.Print();
    cout << endl;

    SplayTree<int> splay_tree1;
    for (int i = 1; i <= 32; ++i)
    {
        splay_tree1.Insert(i);
    }

    splay_tree1.Find(1);
    splay_tree1.Print();
    cout << endl;

    splay_tree1.Find(2);
    splay_tree1.Print();
    cout << endl;
    return 0;
}
