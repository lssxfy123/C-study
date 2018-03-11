// Copyright 2018.刘珅珅
// author：刘珅珅
// 自顶向下伸展树
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

        // value对应的结点不存在
        if (IsLessThan(value, root_->value_))
        {
            // 创建新的value结点并作为根结点
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

        // 将value结点伸展到根结点
        Splay(value);
        SplayTreeNode* del_node;

        // value不存在
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

            // 对root的左子树进行伸展
            // 由于value大于root的左子树所有结点的值
            // 所以会把root左子树最大的值伸展到根结点
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
        // 将value伸展到根结点
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

        // 伸展
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

    // 左旋转
    // 相当于《数据结构与算法分析》378页例程中
    // 的rotateWithRightChild
    void LeftRotation(SplayTreeNode*& node)
    {
        SplayTreeNode* right = node->right_child_;
        node->right_child_ = right->left_child_;
        right->left_child_ = node;
        node = right;  // node为子树的根结点
    }

    // 右旋转
    // 相当于《数据结构与算法分析》378页例程中
    // 的rotateWithLeftChild
    void RightRotation(SplayTreeNode*& node)
    {
        SplayTreeNode* left = node->left_child_;
        node->left_child_ = left->right_child_;
        left->right_child_ = node;
        node = left;  // node为子树的根结点
    }

    // 自定义打印
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

    // 中序遍历
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

    // 前序遍历
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

    // 后序遍历
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

    // 自顶向下
    // node为子树的根结点
    void Splay(const T& value, SplayTreeNode*& node)
    {
        if (nullptr == node)
        {
            return;
        }

        SplayTreeNode header;
        header.left_child_ = header.right_child_ = nullptr;

        // node为当前结点，是其子树的根，称为中间的树
        // left存储小于node的结点，但不存储node的子树的结点
        // right存储大于node的结点，但不存储node的子树的结点
        // 初始状态下node为root结点，left和right都是空树
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
                    // 旋转是为了将value对应的结点更快伸展到根
                    RightRotation(node);
                    if (node->left_child_ == nullptr)
                    {
                        break;
                    }
                }

                // 挂载到右树Right的左子树上
                // node即将变成其左孩子
                // 挂载到Right上的比node->left_child_大
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

                // 挂载到左树Left的右子树上
                // node即将变成其右孩子
                // 挂载到Left上的比node->right_child_小
                Left->right_child_ = node;
                Left = node;
                node = node->right_child_;
            }
            else {
                break;
            }
        }

        // 左、中、右树组合
        Left->right_child_ = node->left_child_;
        Right->left_child_ = node->right_child_;

        // header.right_child_为Left树
        node->left_child_ = header.right_child_;

        // header.left_child_为Right树
        node->right_child_ = header.left_child_;
    }

private:
    SplayTreeNode* root_;  // 根结点
    SplayTreeNode* null_node_;  // 代表空结点

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

    // 8不存在于树中
    // 会把7伸展到根结点
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
