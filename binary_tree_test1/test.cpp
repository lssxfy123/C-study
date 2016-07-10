// Copyright 2016.刘珅珅
// author：刘珅珅
// 二叉树：利用后缀表达式生成，如果是中缀表达式，则先转换为后缀表达式
#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct BinaryNode
{
    char data_;
    BinaryNode* left_;
    BinaryNode* right_;
    BinaryNode(char c) : data_(c), left_(NULL), right_(NULL) {}
};

BinaryNode* CreateBinaryTree(string expression);
bool IsOperator(char c);
int GetOperatorPriority(char c);

// 创建二叉树:根据后缀表达式创建
BinaryNode* CreateBinaryTree(string last)
{
    stack<char> operator_stack_;
    stack<BinaryNode*> data_stack_;
    BinaryNode* temp = NULL;

    for (int i = 0; i < last.length(); ++i)
    {
        if (IsOperator(last[i]))
        {
            temp = new BinaryNode(last[i]);
            temp->right_ = data_stack_.top();
            data_stack_.pop();
            temp->left_ = data_stack_.top();
            data_stack_.pop();
            data_stack_.push(temp);
        } else {
            // 操作数作为叶节点，左右节点都为空
            temp = new BinaryNode(last[i]);
            data_stack_.push(temp);
        }
    }
    return data_stack_.top();
}

// 将中缀表达式转换为后缀表达式
string MiddleToLast(string middle)
{
    string last;  // 转换的后缀表达式
    stack<char> operator_stack_;
    for (int i = 0; i < middle.size(); ++i)
    {
        char c = middle[i];
        if (!IsOperator(c))
        {
            // 在当前字符串结尾添加1个字符
            last.append(1, c);
        } else {
            if (c == '(')
            {
                operator_stack_.push(c);
            } else {
                if (c == ')')
                {
                    while (operator_stack_.top() != '(')
                    {
                        last.append(1, operator_stack_.top());
                        operator_stack_.pop();
                    }
                    operator_stack_.pop();  // 弹出'('
                } else {
                    if (operator_stack_.empty())
                    {
                        operator_stack_.push(c);
                    } else {
                        if (GetOperatorPriority(c) > GetOperatorPriority(operator_stack_.top()))
                        {
                            // 栈后进先出，优先级高的后进去先出来
                            operator_stack_.push(c);
                        } else {
                            while (!operator_stack_.empty() 
                                && GetOperatorPriority(c) <= GetOperatorPriority(operator_stack_.top()))
                            {
                                last.append(1, operator_stack_.top());
                                operator_stack_.pop();
                            }
                            operator_stack_.push(c);
                        }
                    }
                }
            }
        }
    }

    while (!operator_stack_.empty())
    {
        last.append(1, operator_stack_.top());
        operator_stack_.pop();
    }
    return last;
}

// 判断是否为运算符
bool IsOperator(char c)
{
    char operator_char[] = {'(', ')', '+', '-', '*', '/', '^'};
    for (int i = 0; i < sizeof(operator_char); ++i)
    {
        if (c == operator_char[i])
        {
            return true;
        }
    }
    return false;
}

// 判断运算符优先级
int GetOperatorPriority(char c)
{
    switch (c)
    {
    case '(':  // 左括号的优先级定为最低，因其不参与运算
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    case '^':
        return 4;
    default:
        return 0;
    }
}

// 后序遍历
void PostOrderTraverse(BinaryNode* root)
{
    if (root != NULL)
    {
        PostOrderTraverse(root->left_);
        PostOrderTraverse(root->right_);
        cout << root->data_ << ' ';
    }
}

// 前序遍历
void PreOrderTraverse(BinaryNode* root)
{
    if (root != NULL)
    {
        cout << root->data_ << ' ';
        PreOrderTraverse(root->left_);
        PreOrderTraverse(root->right_);
    }
}

// 中序遍历
void InOrderTraverse(BinaryNode* root)
{

}

int main(int argc, char* argv[])
{
    // 中缀表达式(标准表达式)
    string expression = "(a+(b*c))+(((d*e)+f)*g)";
    string last = MiddleToLast(expression);
    cout << "last: " << last << endl;
    BinaryNode* root = CreateBinaryTree(last);
    PostOrderTraverse(root);
    cout << endl;
    PreOrderTraverse(root);
    return 0;
}
