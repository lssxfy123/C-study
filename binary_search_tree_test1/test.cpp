// Copyright 2016.刘珅珅
// author：刘珅珅
// 二叉树：利用后缀表达式生成，如果是中缀表达式，则先转换为后缀表达式
#include <iostream>
#include <stack>
#include <string>
using namespace std;

template <typename Comparable>
class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& rhs);
    ~BinarySearchTree();

    const Comparable& FindMin() const;
    const Comparable& FindMax() const;
    bool Contains(const Comparable& x) const;
    bool IsEmpty() const;
    void PrintTree() const;

    void MakeEmpty();
    void Insert(const Comparable& x);
    void Remove(const Comparable& x);

    const BinarySearchTree& operator= (const BinarySearchTree& rhs);

private:
    struct BinaryNode
    {
        Comparable element_;
        BinaryNode* left_;
        BinaryNode* right_;

        BinaryNode(const Comparable& element, BinaryNode* lt, BinaryNode* rt)
        : element_(element), left_(lt), right(rt) {}
    };

    BinaryNode* root_;
    void Insert(const Comparable& x, BinaryNode*& t) const;
    void Remove(const Comparable& x, BinaryNode*& t) const;
    BinaryNode* FindMin(BinaryNode* t) const;
    BinaryNode* FindMax(BinaryNode* t) const;
    bool Contains(const Comparable& x, BinaryNode* t) const;
    void MakeEmpty(BinaryNode*& t);
    void PrintTree(BinaryNode* t) const;
    BinaryNode* Clone(BinaryNode* t) const;
};

int main(int argc, char* argv[])
{
    // 中缀表达式(标准表达式)
    string expression = "(a+(b*c))+(((d*e)+f)*g)";
    string last = MiddleToLast(expression);
    cout << "last: " << last << endl;
    BinaryNode* root = CreateBinaryTree(last);

    cout << "后序遍历：" << endl;
    PostOrderTraverse(root);
    cout << endl;

    cout << "先序遍历：" << endl;
    PreOrderTraverse(root);
    cout << endl;

    cout << "中序遍历：" << endl;
    InOrderTraverse(root);

    cout << endl;
    return 0;
}
