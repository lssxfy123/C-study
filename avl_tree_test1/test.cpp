// Copyright 2018.���|�|
// author�����|�|
// AVL��ƽ�������
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
    int Height() const  // ���ĸ߶�
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
        int height_;  // �ڵ�߶�
        AVLTreeNode* left_child_;
        AVLTreeNode* right_child_;
    };

    // ���ĸ߶�
    int Height(AVLTreeNode* node)
    {
        if (node != nullptr)
        {
            return node->height_;
        }
        return -1;  // �����ĸ߶�Ϊ-1
    }

    // ����ת
    // rootΪ��Сʧ�������ĸ����
    // ������AVLʧ��Ĳ�����������
    // ·���ϵ�1��ʧ��Ľ��
    // ������ת��������ĸ����
    AVLTreeNode* LeftRotation(AVLTreeNode* root)
    {
        cout << "������ת" << endl;

        // ����ת
        // ��ʧ�������ĸ������Һ�����Ϊ�µĸ����
        // ԭ�������Ϊ�¸���������
        // �����ڽ�����ʧ������������ת��һ��
        AVLTreeNode* right_child = root->right_child_;

        // ԭ�������Һ���Ϊ�¸���������
        // �¸��������ӵ�ֵ�϶���ԭ������ֵ��
        root->right_child_ = right_child->left_child_;
        right_child->left_child_ = root;

        // �ο�C++�㷨ѧϰ8-AVL��.docx�н��ĸ߶ȼ���
        root->height_ = max(Height(root->left_child_), Height(root->right_child_)) + 1;
        right_child->height_ = max(Height(right_child->left_child_), Height(right_child->right_child_)) + 1;
        return right_child;
    }

    // ����ת
    // rootΪ��Сʧ�������ĸ����
    // ������ת��������ĸ����
    AVLTreeNode* RightRotation(AVLTreeNode* root)
    {
        // ����ת
        // ��ʧ�������ĸ�����������Ϊ�µĸ����
        // ԭ�������Ϊ�¸������Һ���
        // �����ڽ�����ʧ������������ת��һ��
        AVLTreeNode* left_child = root->left_child_;

        // �¸������Һ��ӵ�ֵ�϶���ԭ������ֵС
        root->left_child_ = left_child->right_child_;
        left_child->right_child_ = root;

        root->height_ = max(Height(root->left_child_), Height(root->right_child_)) + 1;
        left_child->height_ = max(Height(left_child->left_child_), Height(left_child->right_child_)) + 1;
        return left_child;
    }

    // ������������
    AVLTreeNode* LeftRightRotation(AVLTreeNode* root)
    {
        root->left_child_  = LeftRotation(root->left_child_);
        return RightRotation(root);
    }

    // ������������
    // rootΪʧ�������ĸ����
    // ���������ϲ��������ӵ���ʧ��
    AVLTreeNode* RightLeftRotation(AVLTreeNode* root)
    {
        // �Ƚ�ʧ�������ĸ�������������������ת
        // ������ʧ������������������������Һ��ӵ���ʧ�������
        // Ȼ����������ת���ʧ������
        root->right_child_ = RightRotation(root->right_child_);
        return LeftRotation(root);
    }

    AVLTreeNode* Insert(T value, AVLTreeNode*& node)
    {
        if (node == nullptr)
        {
            node = new AVLTreeNode(value, nullptr, nullptr);
        }
        else if (IsLessThan(node->value_, value))  // ����������
        {
            node->right_child_ = Insert(value, node->right_child_);

            // AVL��ʧ��
            if (Height(node->right_child_) - Height(node->left_child_) == 2)
            {
                // �����������Һ���
                if (IsLessThan(node->right_child_->value_, value))
                {
                    node = LeftRotation(node);
                }
                else if (IsLessThan(value, node->right_child_->value_))
                {
                    // ��������������
                    node = RightLeftRotation(node);
                }
            }
        }
        else if (IsLessThan(value, node->value_))  // ����������
        {
            node->left_child_ = Insert(value, node);

            // AVL��ʧ��
            if (Height(node->left_child_) - Height(node->right_child_) == 2)
            {
                // ��������������
                if (IsLessThan(value, node->left_child_->value_))
                {
                    node = RightRotation(node);
                }
                else if (IsLessThan(node->left_child_->value_, value))
                {
                    // �����������Һ���
                    node = LeftRightRotation(node);
                }
            }
        }

        // ���½��ĸ߶�
        node->height_ = max(Height(node->left_child_), Height(node->right_child_)) + 1;
        return node;
    }

    // �������
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
