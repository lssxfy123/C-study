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
    }

public:
    int Height() const  // 树的高度
    {
        return Height(root_);
    }

    void Insert(T value)
    {
        Insert(value, root_);
    }

    void PrintTree() const
    {
        PrintTree(root_);
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

        // 原根结点的右孩子为新根结点的左孩子
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
        // 左旋转
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
        root->left_child_  = LeftRotation(root->left_child_);
        return RightRotation(root);
    }

    // 先右旋后左旋
    // root为失衡子树的根结点
    // 在右子树上插入了左孩子导致失衡
    AVLTreeNode* RightLeftRotation(AVLTreeNode* root)
    {
        // 先将失衡子树的根结点的右子树进行右旋转
        // 将整个失衡子树变成类似右子树插入右孩子导致失衡的情形
        // 然后再用左旋转解决失衡问题
        root->right_child_ = RightRotation(root->right_child_);
        return LeftRotation(root);
    }

    AVLTreeNode* Insert(T value, AVLTreeNode*& node)
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
            node->left_child_ = Insert(value, node);

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
private:
    AVLTreeNode* root_;
    Comparator IsLessThan;
};

int main(int argc, char* argv[])
{
    AVLTree<int> avl_tree;
    avl_tree.Insert(4);
    avl_tree.Insert(5);
    avl_tree.Insert(6);
    avl_tree.PrintTree();
    cout << endl;
    return 0;
}
