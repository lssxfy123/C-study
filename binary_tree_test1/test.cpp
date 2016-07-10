// Copyright 2016.���|�|
// author�����|�|
// �����������ú�׺���ʽ���ɣ��������׺���ʽ������ת��Ϊ��׺���ʽ
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

// ����������:���ݺ�׺���ʽ����
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
            // ��������ΪҶ�ڵ㣬���ҽڵ㶼Ϊ��
            temp = new BinaryNode(last[i]);
            data_stack_.push(temp);
        }
    }
    return data_stack_.top();
}

// ����׺���ʽת��Ϊ��׺���ʽ
string MiddleToLast(string middle)
{
    string last;  // ת���ĺ�׺���ʽ
    stack<char> operator_stack_;
    for (int i = 0; i < middle.size(); ++i)
    {
        char c = middle[i];
        if (!IsOperator(c))
        {
            // �ڵ�ǰ�ַ�����β���1���ַ�
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
                    operator_stack_.pop();  // ����'('
                } else {
                    if (operator_stack_.empty())
                    {
                        operator_stack_.push(c);
                    } else {
                        if (GetOperatorPriority(c) > GetOperatorPriority(operator_stack_.top()))
                        {
                            // ջ����ȳ������ȼ��ߵĺ��ȥ�ȳ���
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

// �ж��Ƿ�Ϊ�����
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

// �ж���������ȼ�
int GetOperatorPriority(char c)
{
    switch (c)
    {
    case '(':  // �����ŵ����ȼ���Ϊ��ͣ����䲻��������
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

// �������
void PostOrderTraverse(BinaryNode* root)
{
    if (root != NULL)
    {
        PostOrderTraverse(root->left_);
        PostOrderTraverse(root->right_);
        cout << root->data_ << ' ';
    }
}

// ǰ�����
void PreOrderTraverse(BinaryNode* root)
{
    if (root != NULL)
    {
        cout << root->data_ << ' ';
        PreOrderTraverse(root->left_);
        PreOrderTraverse(root->right_);
    }
}

// �������
void InOrderTraverse(BinaryNode* root)
{

}

int main(int argc, char* argv[])
{
    // ��׺���ʽ(��׼���ʽ)
    string expression = "(a+(b*c))+(((d*e)+f)*g)";
    string last = MiddleToLast(expression);
    cout << "last: " << last << endl;
    BinaryNode* root = CreateBinaryTree(last);
    PostOrderTraverse(root);
    cout << endl;
    PreOrderTraverse(root);
    return 0;
}
