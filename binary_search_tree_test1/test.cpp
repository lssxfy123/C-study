// Copyright 2016.���|�|
// author�����|�|
// �����������ú�׺���ʽ���ɣ��������׺���ʽ������ת��Ϊ��׺���ʽ
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
    // ��׺���ʽ(��׼���ʽ)
    string expression = "(a+(b*c))+(((d*e)+f)*g)";
    string last = MiddleToLast(expression);
    cout << "last: " << last << endl;
    BinaryNode* root = CreateBinaryTree(last);

    cout << "���������" << endl;
    PostOrderTraverse(root);
    cout << endl;

    cout << "���������" << endl;
    PreOrderTraverse(root);
    cout << endl;

    cout << "���������" << endl;
    InOrderTraverse(root);

    cout << endl;
    return 0;
}
