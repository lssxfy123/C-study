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
        Destroy(root_);
    }

public:
    int Height() const  // ���ĸ߶�
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

        // �¸���������Ϊԭ�������Һ���
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
        cout << "������ת" << endl;
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
        cout << "������������" << endl;
        // ��������������Ϊ�˽��
        // �����������Һ��ӵ��µ�ʧ��
        // rootΪʧ�������ĸ����
        // �ȶ�root������������������
        // ��Ϊ�˽�root��������������������ӵ�����
        root->left_child_  = LeftRotation(root->left_child_);
        return RightRotation(root);
    }

    // ������������
    // rootΪʧ�������ĸ����
    // ���������ϲ��������ӵ���ʧ��
    AVLTreeNode* RightLeftRotation(AVLTreeNode* root)
    {
        cout << "������������" << endl;

        // �Ƚ�ʧ�������ĸ�������������������ת
        // ������ʧ������������������������Һ��ӵ���ʧ�������
        // Ȼ����������ת���ʧ������
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

    // ����ָ����Ԫ��
    AVLTreeNode* Insert(T value, AVLTreeNode*& node)
    {
        if (!Contains(value, node))
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
                node->left_child_ = Insert(value, node->left_child_);

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

        return nullptr;
    }

    // ɾ��ָ����Ԫ��
    AVLTreeNode* Remove(T value, AVLTreeNode*& node)
    {
        // AVL���Ƕ��������
        if (node != nullptr)
        {
            if (node->value_ == value)  // �ҵ�ɾ�����
            {
                // ���ҽ�����Ϊ��
                if (node->right_child_ != nullptr && node->left_child_ != nullptr)
                {
                    if (Height(node->left_child_) > Height(node->right_child_))
                    {
                        // ����������������
                        // �����������������
                        // ����ֵ����node������ֵ
                        // Ȼ��ɾ���������������
                        // �������Ա�֤ƽ����
                        AVLTreeNode* left_max_node = FindMax(node->left_child_);
                        node->value_ = left_max_node->value_;
                        node->left_child_ = Remove(left_max_node->value_, node->left_child_);
                    }
                    else
                    {
                        // ������������С���ֵ���������ֵ
                        // Ȼ��ɾ������������С���
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
                // Ҫɾ���Ľ��ȵ�ǰ����
                // ������������ɾ��
                node->right_child_ = Remove(value, node->right_child_);

                // ɾ����������㵼�²�ƽ��
                // �������ĸ߶ȴ����������ĸ߶�
                if (Height(node->left_child_) - Height(node->right_child_) == 2)
                {
                    // �൱�����������ϲ����Һ���
                    // node���ӵ��������߶ȴ���������
                    // (��ͼ���ܿ�����)
                    if (Height(node->left_child_->right_child_) > 
                        Height(node->left_child_->left_child_))
                    {
                        node = LeftRightRotation(node);
                    }
                    else
                    {
                        // �൱�����������ϲ�������
                        node = RightRotation(node);
                    }
                }
            }
            else if (node->value_ > value)
            {
                // Ҫɾ���Ľ��ȵ�ǰ���С
                node->left_child_ = Remove(value, node->left_child_);

                // ɾ�����������µĲ�ƽ��
                // �������ĸ߶ȴ���������
                if (Height(node->right_child_) - Height(node->left_child_) == 2)
                {
                    // node�Һ��ӵ��������ĸ߶ȴ����������ĸ߶�
                    // �൱��node�������ϲ�������
                    if (Height(node->right_child_->left_child_) > 
                        Height(node->right_child_->right_child_))
                    {
                        node = RightLeftRotation(node);
                    }
                    else
                    {
                        // �൱��node�������ϲ����Һ���
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

    // ����AVL��
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

    // ǰ�����
    void PrePrintTree(AVLTreeNode* node) const
    {
        if (node != nullptr)
        {
            cout << node->value_ << ' ';
            PrePrintTree(node->left_child_);
            PrePrintTree(node->right_child_);
        }
    }

    // �������
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
