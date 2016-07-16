// Copyright 2016.刘珅珅
// author：刘珅珅
// 二叉查找树
#include <algorithm>
#include <functional>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

template <typename Object, typename Comparator = less<Object> >
class BinarySearchTree
{
public:
    BinarySearchTree()
    {
        root_ = NULL;
    }

    BinarySearchTree(const BinarySearchTree& rhs);
    ~BinarySearchTree()
    {
    }

    const Object& FindMin() const;
    const Object& FindMax() const;
    bool Contains(const Object& x) const;
    bool IsEmpty() const;
    void PrintTree() const
    {
        PrintTree(root_);
    }

    void MakeEmpty();
    void Insert(const Object& x)
    {
        Insert(x, root_);
    }

    void Remove(const Object& x);

    const BinarySearchTree& operator= (const BinarySearchTree& rhs);

private:
    struct BinaryNode
    {
        Object element_;
        BinaryNode* left_;
        BinaryNode* right_;

        BinaryNode(const Object& element, BinaryNode* lt, BinaryNode* rt)
        : element_(element), left_(lt), right_(rt) {}
    };

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

    void Remove(const Object& x, BinaryNode*& t) const;
    BinaryNode* FindMin(BinaryNode* t) const;
    BinaryNode* FindMax(BinaryNode* t) const;
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

    void MakeEmpty(BinaryNode*& t);
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

    BinaryNode* Clone(BinaryNode* t) const;

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
    binary_search_tree.Insert(3.2);
    binary_search_tree.Insert(3.5);
    binary_search_tree.Insert(4.6);
    binary_search_tree.Insert(2.9);
    binary_search_tree.Insert(5.4);
    binary_search_tree.PrintTree();
    cout << endl;
    return 0;
}
