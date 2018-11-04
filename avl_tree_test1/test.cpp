// Copyright 2018.刘珅珅
// author：刘珅珅
// AVL自平衡二叉树
#include <algorithm>
#include <iostream>
//#include <functional>
using namespace std;

template<typename T, typename Comparator = less<T>>
class AVLTree
{
public:
    AVLTree() : root_(nullptr)
    {
    }

    ~AVLTree()
    {
        Destroy(root_);
    }

public:
    int Height() const  // 树的高度
    {
        return Height(root_);
    }

    bool Contains(T value) const 
    {
        return Contains(value, root_);
    }

    void Insert(T value)
    {
        Insert(value, root_);
    }

    void Remove(T value)
    {
        Remove(value, root_);
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

private:
    struct AVLTreeNode
    {
        AVLTreeNode(T value, AVLTreeNode* left, AVLTreeNode* right)
            : value_(value), left_child_(left), right_child_(right)
        {
        }

        T value_;
        int height_;  // 节点高度
        AVLTreeNode* left_child_;
        AVLTreeNode* right_child_;
    };

    // 结点的高度
    int Height(AVLTreeNode* node)
    {
        if (node != nullptr)
        {
            return node->height_;
        }
        return -1;  // 空树的高度为-1
    }

    // 左旋转
    // root为最小失衡子树的根结点
    // 即导致AVL失衡的插入结点与根结点
    // 路径上第1个失衡的结点
    // 返回旋转后的子树的根结点
    AVLTreeNode* LeftRotation(AVLTreeNode* root)
    {
        cout << "向左旋转" << endl;

        // 左旋转
        // 将失衡子树的根结点的右孩子作为新的根结点
        // 原根结点作为新根结点的左孩子
        // 类似于将整个失衡子树向左旋转了一格
        AVLTreeNode* right_child = root->right_child_;

        // 新根结点的左孩子为原根结点的右孩子
        // 新根结点的左孩子的值肯定比原根结点的值大
        root->right_child_ = right_child->left_child_;
        right_child->left_child_ = root;

        // 参考C++算法学习8-AVL树.docx中结点的高度计算
        root->height_ = max(Height(root->left_child_), Height(root->right_child_)) + 1;
        right_child->height_ = max(Height(right_child->left_child_), Height(right_child->right_child_)) + 1;
        return right_child;
    }

    // 右旋转
    // root为最小失衡子树的根结点
    // 返回旋转后的子树的根结点
    AVLTreeNode* RightRotation(AVLTreeNode* root)
    {
        cout << "向右旋转" << endl;
        // 右旋转
        // 将失衡子树的根结点的左孩子作为新的根结点
        // 原根结点作为新根结点的右孩子
        // 类似于将整个失衡子树向右旋转了一格
        AVLTreeNode* left_child = root->left_child_;

        // 新根结点的右孩子的值肯定比原根结点的值小
        root->left_child_ = left_child->right_child_;
        left_child->right_child_ = root;

        root->height_ = max(Height(root->left_child_), Height(root->right_child_)) + 1;
        left_child->height_ = max(Height(left_child->left_child_), Height(left_child->right_child_)) + 1;
        return left_child;
    }

    // 先左旋后右旋
    AVLTreeNode* LeftRightRotation(AVLTreeNode* root)
    {
        cout << "先左旋后右旋" << endl;
        // 先左旋后右旋是为了解决
        // 左子树插入右孩子导致的失衡
        // root为失衡子树的根结点
        // 先对root的左子树进行左旋，
        // 是为了将root子树变成左子树插入左孩子的问题
        root->left_child_  = LeftRotation(root->left_child_);
        return RightRotation(root);
    }

    // 先右旋后左旋
    // root为失衡子树的根结点
    // 在右子树上插入了左孩子导致失衡
    AVLTreeNode* RightLeftRotation(AVLTreeNode* root)
    {
        cout << "先右旋后左旋" << endl;

        // 先将失衡子树的根结点的右子树进行右旋转
        // 将整个失衡子树变成类似右子树插入右孩子导致失衡的情形
        // 然后再用左旋转解决失衡问题
        root->right_child_ = RightRotation(root->right_child_);
        return LeftRotation(root);
    }

    bool Contains(T value, AVLTreeNode* node) const
    {
        while (node != nullptr)
        {
            if (node->value_ == value)
            {
                return true;
            }
            else if (node->value_ < value)
            {
                node = node->right_child_;
            }
            else
            {
                node = node->left_child_;
            }
        }
        return false;
    }

    // 插入指定的元素
    AVLTreeNode* Insert(T value, AVLTreeNode*& node)
    {
        if (!Contains(value, node))
        {
            if (node == nullptr)
            {
                node = new AVLTreeNode(value, nullptr, nullptr);
            }
            else if (IsLessThan(node->value_, value))  // 插入右子树
            {
                node->right_child_ = Insert(value, node->right_child_);

                // AVL树失衡
                if (Height(node->right_child_) - Height(node->left_child_) == 2)
                {
                    // 右子树插入右孩子
                    if (IsLessThan(node->right_child_->value_, value))
                    {
                        node = LeftRotation(node);
                    }
                    else if (IsLessThan(value, node->right_child_->value_))
                    {
                        // 右子树插入左孩子
                        node = RightLeftRotation(node);
                    }
                }
            }
            else if (IsLessThan(value, node->value_))  // 插入左子树
            {
                node->left_child_ = Insert(value, node->left_child_);

                // AVL树失衡
                if (Height(node->left_child_) - Height(node->right_child_) == 2)
                {
                    // 左子树插入左孩子
                    if (IsLessThan(value, node->left_child_->value_))
                    {
                        node = RightRotation(node);
                    }
                    else if (IsLessThan(node->left_child_->value_, value))
                    {
                        // 左子树插入右孩子
                        node = LeftRightRotation(node);
                    }
                }
            }

            // 更新结点的高度
            node->height_ = max(Height(node->left_child_), Height(node->right_child_)) + 1;
            return node;
        }

        return nullptr;
    }

    // 删除指定的元素
    AVLTreeNode* Remove(T value, AVLTreeNode*& node)
    {
        // AVL树是二叉查找树
        if (node != nullptr)
        {
            if (node->value_ == value)  // 找到删除结点
            {
                // 左右结点均不为空
                if (node->right_child_ != nullptr && node->left_child_ != nullptr)
                {
                    if (Height(node->left_child_) > Height(node->right_child_))
                    {
                        // 左子树比右子树高
                        // 查找左子树的最大结点
                        // 用其值代替node根结点的值
                        // 然后删除左子树的最大结点
                        // 这样可以保证平衡性
                        AVLTreeNode* left_max_node = FindMax(node->left_child_);
                        node->value_ = left_max_node->value_;
                        node->left_child_ = Remove(left_max_node->value_, node->left_child_);
                    }
                    else
                    {
                        // 用右子树的最小结点值代替根结点的值
                        // 然后删除右子树的最小结点
                        AVLTreeNode* right_min_node = FindMin(node->right_child_);
                        node->value_ = right_min_node->value_;
                        node->right_child_ = Remove(value, node->right_child_);
                    }
                }
                else
                {
                    AVLTreeNode* temp = node;
                    if (node->left_child_ != nullptr)
                    {
                        node = node->left_child_;
                    }
                    else if (node->right_child_ != nullptr)
                    {
                        node = node->right_child_;
                    }
                    delete temp;
                    return nullptr;
                }
            }
            else if (node->value_ < value)
            {
                // 要删除的结点比当前结点大
                // 在右子树进行删除
                node->right_child_ = Remove(value, node->right_child_);

                // 删除右子树结点导致不平衡
                // 左子树的高度大于右子树的高度
                if (Height(node->left_child_) - Height(node->right_child_) == 2)
                {
                    // 相当于在左子树上插入右孩子
                    // node左孩子的右子树高度大于左子树
                    // (画图就能看明白)
                    if (Height(node->left_child_->right_child_) > 
                        Height(node->left_child_->left_child_))
                    {
                        node = LeftRightRotation(node);
                    }
                    else
                    {
                        // 相当于在左子树上插入左孩子
                        node = RightRotation(node);
                    }
                }
            }
            else if (node->value_ > value)
            {
                // 要删除的结点比当前结点小
                node->left_child_ = Remove(value, node->left_child_);

                // 删除左子树导致的不平衡
                // 右子树的高度大于左子树
                if (Height(node->right_child_) - Height(node->left_child_) == 2)
                {
                    // node右孩子的左子树的高度大于右子树的高度
                    // 相当于node右子树上插入左孩子
                    if (Height(node->right_child_->left_child_) > 
                        Height(node->right_child_->right_child_))
                    {
                        node = RightLeftRotation(node);
                    }
                    else
                    {
                        // 相当于node右子树上插入右孩子
                        node = LeftRotation(node);
                    }
                }
            }
            return node;
        }

        return nullptr;
    }

    AVLTreeNode* FindMin(AVLTreeNode* node) const
    {
        if (node != nullptr)
        {
            while (node->left_child_ != nullptr)
            {
                node = node->left_child_;
            }

            return node;
        }
        return nullptr;
    }

    AVLTreeNode* FindMax(AVLTreeNode* node) const
    {
        if (node != nullptr)
        {
            while (node->right_child_ != nullptr)
            {
                node = node->right_child_;
            }
            return node;
        }
        return nullptr;
    }

    // 销毁AVL树
    void Destroy(AVLTreeNode* node)
    {
        if (node != nullptr)
        {
            Destroy(node->left_child_);
            Destroy(node->right_child_);
            delete node;
            node = nullptr;
        }
    }

    // 中序遍历
    void PrintTree(AVLTreeNode* node) const
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
    void PrePrintTree(AVLTreeNode* node) const
    {
        if (node != nullptr)
        {
            cout << node->value_ << ' ';
            PrePrintTree(node->left_child_);
            PrePrintTree(node->right_child_);
        }
    }

    // 后序遍历
    void PostPrintTree(AVLTreeNode* node) const
    {
        if (node == nullptr)
        {
            return;
        }

        PostPrintTree(node->left_child_);
        PostPrintTree(node->right_child_);
        cout << node->value_ << ' ';
    }
private:
    AVLTreeNode* root_;
    Comparator IsLessThan;
};

int main(int argc, char* argv[])
{
    AVLTree<int> avl_tree;
    avl_tree.Insert(5);
    avl_tree.Insert(3);
    avl_tree.Insert(7);
    avl_tree.Insert(2);
    avl_tree.Insert(4);
    avl_tree.Insert(6);
    avl_tree.Insert(8);
    avl_tree.Insert(0);
    avl_tree.Insert(1);
    avl_tree.Remove(2);
    avl_tree.PrintTree();
    cout << endl;
    avl_tree.PrePrintTree();
    cout << endl;
    avl_tree.PostPrintTree();
    cout << endl;
    return 0;
}
