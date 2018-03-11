// Copyright 2018.���|�|
// author�����|�|
// �����
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T, typename Comparator = less<T>>
class RedBlackTree
{
public:
    enum RedBlackColor
    {
        Red,
        Black
    };

private:
    struct RedBlackNode
    {
        RedBlackNode(T value = T(), RedBlackColor color = Black, RedBlackNode* parent = nullptr,
            RedBlackNode* left = nullptr, RedBlackNode* right = nullptr)
            : value_(value), color_(color), parent_(parent), left_child_(left), right_child_(right)
        {
        }

        T value_;
        RedBlackColor color_;
        RedBlackNode* parent_;
        RedBlackNode* left_child_;
        RedBlackNode* right_child_;
    };

public:
    RedBlackTree()
    {
        null_node_ = new RedBlackNode();
        root_ = null_node_;
    }

    ~RedBlackTree()
    {
    }

    bool Contains(const T& value) const
    {
        return Contains(value, root_);
    }

    RedBlackNode* Find(const T& value)
    {
        return Find(value, root_);
    }

    void Insert(const T& value)
    {
        if (!Contains(value))
        {
            // ������ҪͿ�ɺ�ɫ����������ƽ������5
            RedBlackNode* new_node = new RedBlackNode(value, Red);
            new_node->left_child_ = new_node->right_child_ = null_node_;

            // ����������ɶ������������������
            RedBlackNode* tmp1 = null_node_;
            RedBlackNode* tmp2 = root_;
            while (tmp2 != null_node_)
            {
                tmp1 = tmp2;

                // tmp2->value_��������value��ͬ
                // tmp1�洢ʵ��Ϊ����whileѭ����tmp2�ĸ����
                if (IsLessThan(value, tmp2->value_))
                {
                    tmp2 = tmp2->left_child_;
                }
                else if (IsLessThan(tmp2->value_, value))
                {
                    tmp2 = tmp2->right_child_;
                }
            }

            new_node->parent_ = tmp1;
            if (tmp1 != null_node_)
            {
                if (IsLessThan(value, tmp1->value_))
                {
                    tmp1->left_child_ = new_node;
                }
                else
                {
                    tmp1->right_child_ = new_node;
                }
            }
            else
            {
                root_ = new_node;
            }

            // ��������
            InsertFixUp(new_node);
        }
    }

    void Remove(const T& value)
    {
        if (Contains(value))
        {
            // ��ɾ���Ľ��
            RedBlackNode* delete_node = Find(value);
            RedBlackNode* replace = delete_node;
            RedBlackColor original_color = replace->color_;

            // delete_nodeɾ������Ҫ�����Ľ��
            RedBlackNode* adjust_node = nullptr;

            // �����������ɾ��
            // Ҫ���Ǻ�����ĸ��ӹ�ϵ�Ķ�Ӧ
            if (delete_node->left_child_ == null_node_)  // 0����1������
            {
                // 0����1�����ӣ���delete_node���ӽ�㿪ʼ����
                adjust_node = delete_node->right_child_;
                Transplant(delete_node, delete_node->right_child_);
            }
            else if (delete_node->right_child_ == null_node_)
            {
                adjust_node = delete_node->left_child_;
                Transplant(delete_node, delete_node->left_child_);
            }
            else  // ��������
            {
                // ����delete_node��������������С���
                // Ҳ����Ѱ���������������
                replace = replace->right_child_;
                while (replace->left_child_ != null_node_)
                {
                    replace = replace->left_child_;
                }

                // ����ȡ��������ɫ
                original_color = replace->color_;

                // replace���ӿ϶�Ϊnullptr
                // replace��ȫȡ����delete_node
                // �����ӽ�����ɫ�����Դ�
                // replace���ӽ�㿪ʼ����
                adjust_node = replace->right_child_;

                // delete_node���Һ��Ӿ�����������С���
                if (replace->parent_ == delete_node)
                {
                    adjust_node->parent_ = replace;
                }
                else
                {
                    // ����replace->parent_���ӽ��
                    Transplant(replace, replace->right_child_);
                    replace->right_child_ = delete_node->right_child_;
                    replace->right_child_->parent_ = replace;
                }

                Transplant(delete_node, replace);
                replace->left_child_ = delete_node->left_child_;
                replace->left_child_->parent_ = replace;
                replace->color_ = delete_node->color_;
            }

            // ���delete_node��1����0�����ӣ���
            // original_color����ɾ������ɫ�����
            // Ϊ��ɫ���п��ܻ�Ӱ��������2��5��
            // ���delete_node���������ӣ���
            // original_color�����������ɫ�����
            //Ϊ��ɫ���п��ܻ�Ӱ��������5
            if (original_color == Black)
            {
                RemoveFixUp(adjust_node);
            }

            delete delete_node;
        }
    }

    void Print()
    {
        if (root_ != null_node_)
        {
            Print(root_, root_->value_, 0);
        }
    }
private:
    RedBlackTree(const RedBlackTree& input) {}
    RedBlackTree& operator=(const RedBlackTree& input) {}

    bool Contains(const T& value, RedBlackNode* node) const
    {
        while (node != null_node_)
        {
            if (IsLessThan(value, node->value_))
            {
                node = node->left_child_;
            }
            else if (IsLessThan(node->value_, value))
            {
                node = node->right_child_;
            }
            else
            {
                return true;
            }
        }

        return false;
    }

    RedBlackNode* Find(const T& value, RedBlackNode* node)
    {
        while (node != null_node_)
        {
            if (IsLessThan(value, node->value_))
            {
                node = node->left_child_;
            }
            else if (IsLessThan(node->value_, value))
            {
                node = node->right_child_;
            }
            else
            {
                return node;
            }
        }
        return null_node_;
    }

    // ����
    // nodeΪ����ת�����ĸ����
    // ��ת�ķ�ʽͬavl������չ����ͬ
    // ֻ�Ǻ��������ת����Ҫ���ø��ӹ�ϵ
    void LeftRotation(RedBlackNode* node)
    {
        if (node->right_child_ == null_node_)
        {
            return;
        }

        RedBlackNode* new_sub_root = node->right_child_;

        // �¸���������Ϊԭ�������Һ���
        // �丸���Ҳ�ͱ����ԭ�����
        node->right_child_ = new_sub_root->left_child_;
        if (new_sub_root->left_child_ != null_node_)
        {
            new_sub_root->left_child_->parent_ = node;
        }

        // ԭ�����ĸ����Ҳ���¸����
        new_sub_root->parent_ = node->parent_;

        if (null_node_ == node->parent_)
        {
            // ��������new_sub_root����Ϊ������ĸ����
            root_ = new_sub_root;
        }
        else
        {
            if (node->parent_->left_child_ == node)
            {
                // ԭ�����Ϊ�丸�������ӣ�
                // ��new_sub_root����Ϊ�丸��������
                node->parent_->left_child_ = new_sub_root;
            }
            else
            {
                // ԭ�����Ϊ�丸�����Һ��ӣ�
                // ��new_sub_root����Ϊ�丸�����Һ���
                node->parent_->right_child_ = new_sub_root;
            }
        }

        // ԭ�����Ϊ�¸���������
        // ԭ�����ĸ����Ϊ�¸����
        new_sub_root->left_child_ = node;
        node->parent_ = new_sub_root;
    }

    // ����
    void RightRotation(RedBlackNode* node)
    {
        if (node->left_child_ == null_node_)
        {
            return;
        }

        RedBlackNode* new_sub_root = node->left_child_;
        node->left_child_ = new_sub_root->right_child_;
        if (new_sub_root->right_child_ != null_node_)
        {
            new_sub_root->right_child_->parent_ = node;
        }

        new_sub_root->parent_ = node->parent_;

        if (null_node_ == node->parent_)
        {
            root_ = new_sub_root;
        }
        else
        {
            if (node->parent_->right_child_ == node)
            {
                node->parent_->right_child_ = new_sub_root;
            }
            else
            {
                node->parent_->left_child_ = new_sub_root;
            }
        }

        new_sub_root->right_child_ = node;
        node->parent_ = new_sub_root;
    }

    // ��������
    void InsertFixUp(RedBlackNode* node)
    {
        // ����㣬���Ϊ�գ���ʾnodeΪ������ĸ����
        RedBlackNode* parent = nullptr;

        // �游��㣬���Ϊ�գ���ʾnode��node->parent_
        // Ϊ������ĸ����.
        RedBlackNode* grand = nullptr;

        // ��������Ϊ��ɫ����Ҫ�޸�����
        // ��ǰ���nodeʼ��Ϊ��ɫ�����������ƻ�ƽ������5
        // �ο�http://blog.csdn.net/v_JULY_v/article/details/6105630
        while (node->parent_->color_ == Red)
        {
            parent = node->parent_;

            // �游���϶����ڶ���Ϊ��ɫ������Ͳ��Ǻ����
            // �ο������ƽ������2��4
            grand = parent->parent_;

            // ��������游��������
            if (parent == grand->left_child_)
            {
                // ������
                RedBlackNode* uncle = grand->right_child_;

                // Case1��������Ϊ��ɫ
                if (uncle->color_ == Red)
                {
                    // ���׺�����Ϳ�ڣ��游Ϳ��
                    // ��Ϊ��������ɫ��ƽ������4��5
                    uncle->color_ = Black;
                    parent->color_ = Black;
                    grand->color_ = Red;

                    // Ϳɫ��ɺ�grand�Լ��������϶�ƽ��
                    // ���Խ���ǰ���ָ��grand������¿�ʼƽ���޸�
                    node = grand;
                }
                else
                {
                    // �������п��ܲ����ڣ��ں��ɫ��NIL���Ϊ��ɫ
                    // Case2��������Ϊ��ɫ����ǰ���Ϊ�������Һ���
                    if (parent->right_child_ == node)
                    {
                        // ����ǰ���ĸ������Ϊ�µĵ�ǰ��������ת
                        // ����ֱ����ת��ǰ��㣬���ƻ�ƽ������5
                        node = node->parent_;
                        LeftRotation(node);
                    }

                    // Case3��������Ϊ��ɫ����ǰ���Ϊ����������
                    // node���游����ʼ�϶��Ǻڵģ������޷�����ƽ������4
                    // ������ڽ���Ϳɫ�޸�����תʱ��һ�㶼���ڵ�ǰ����
                    // ��������游����ɣ����������ƻ�������ƽ������
                    node->parent_->color_ = Black;
                    node->parent_->parent_->color_ = Red;

                    // node���游����ƽ������5���ƻ�
                    // ͨ����������ɫ����node->parent_��Ϊ�µ����������
                    // �Ӷ����������ĺ��ƽ��
                    RightRotation(node->parent_->parent_);
                }
            }
            else  // ��������游�����Һ���
            {
                RedBlackNode* uncle = grand->left_child_;

                // Case1��������Ϊ��ɫ
                if (uncle->color_ == Red)
                {
                    uncle->color_ = Black;
                    parent->color_ = Black;
                    grand->color_ = Red;
                    node = grand;
                }
                else
                {
                    // Case2��������Ϊ��ɫ����ǰ���Ϊ�������Һ���
                    if (parent->left_child_ == node)
                    {
                        node = node->parent_;
                        RightRotation(node);
                    }

                    // Case3��������Ϊ��ɫ����ǰ���Ϊ����������
                    node->parent_->color_ = Black;
                    node->parent_->parent_->color_ = Red;
                    LeftRotation(node->parent_->parent_);
                }
            }
        }

        // ���������Ϊ��ɫ
        root_->color_ = Black;
    }

    // ɾ������
    // nodeΪ�������汻ɾ���Ľ������ӽ��
    void RemoveFixUp(RedBlackNode* node)
    {
        while (node != root_ && node->color_ == Black)
        {
            if (node == node->parent_->left_child_)
            {
                // �ֵܽ�㣬�϶����ڷ����ƻ����ƽ������5
                // ��㱾��Ϊ��ɫ
                RedBlackNode* brother = node->parent_->right_child_;

                // Case1���ֵܽ���Ǻ�ɫ
                // �������ֵܽ����ӽ��϶�Ϊ��
                if (brother->color_ == Red)
                {
                    brother->color_ = Black;
                    node->parent_->color_ = Red;  // �����Ϳ�ɺ�ɫ
                    LeftRotation(node->parent_);

                    // �����ж��Ƿ����Case2��Case 3��Case4
                    brother = node->parent_->right_child_;
                }

                if (brother->left_child_->color_ == Black
                    && brother->right_child_->color_ == Black)
                {
                    // Case 2���ֵܽ���Ǻ�ɫ���������ӽ��Ϊ��ɫ
                    // nullptr�����Ϊ��ɫ
                    brother->color_ = Red;
                    node = node->parent_;
                }
                else
                {
                    if (brother->right_child_->color_ == Black)
                    {
                        // Case3���ֵܽ��Ϊ��ɫ��������Ϊ��ɫ��
                        // �Һ���Ϊ��ɫ
                        brother->left_child_->color_ = Black;
                        brother->color_ = Red;
                        RightRotation(brother);
                        brother = node->parent_->right_child_;
                    }

                    // Case4���ֵܽ��Ϊ��ɫ�����Һ���Ϊ��ɫ����������
                    // Case3����RightRotation������Case4
                    brother->color_ = node->parent_->color_;
                    node->parent_->color_ = Black;
                    brother->right_child_->color_ = Black;
                    LeftRotation(node->parent_);
                    node = root_;  // ��������
                    break;
                }
            }
            else
            {
                RedBlackNode* brother = node->parent_->left_child_;
                if (brother->color_ == Red)
                {
                    // Case1���ֵܽ��Ϊ��ɫ
                    brother->color_ = Black;
                    node->parent_->color_ = Red;
                    RightRotation(node->parent_);
                    brother = node->parent_->left_child_;
                }

                if (brother->left_child_->color_ == Black
                    && brother->right_child_->color_ == Black)
                {
                    // Case 2���ֵܽ���Ǻ�ɫ���������ӽ��Ϊ��ɫ
                    // nullptr�����Ϊ��ɫ
                    brother->color_ = Red;
                    node = node->parent_;  // ����������ƶ�
                }
                else
                {
                    if (brother->left_child_->color_ == Black)
                    {
                        // Case3���ֵܽ��Ϊ��ɫ������Ϊ��ɫ���Һ���Ϊ��ɫ
                        brother->right_child_->color_ = Black;
                        brother->color_ = Red;
                        LeftRotation(brother);
                        brother = node->parent_->left_child_;
                    }

                    // Case4���ֵ�Ϊ��ɫ������Ϊ��ɫ���Һ�������
                    brother->color_ = node->parent_->color_;
                    node->parent_->color_ = Black;
                    brother->left_child_->color_ = Black;
                    RightRotation(node->parent_);
                    node = root_;
                    break;
                }
            }
        }

        node->color_ = Black;
    }

    void Print(RedBlackNode* node, T value, int direction)
    {
        if (node != null_node_)
        {
            if (direction == 0)    // ���ڵ�
            {
                cout << setw(2) << node->value_ << "(Black) is root" << endl;
            }
            else                // ��֧�ڵ�
            {
                cout << setw(2) << node->value_ << (node->color_ == Red ? "(Red)" : "(Black)") << " is " 
                    << setw(2) << value << "'s " 
                    << setw(12) << (direction == 1 ? "right child" : "left child") << endl;
            }
            
            Print(node->left_child_, node->value_, -1);
            Print(node->right_child_, node->value_, 1);
        }
    }

    // �����������ֲ
    // ��replace�滻src
    void Transplant(RedBlackNode* src, RedBlackNode* replace)
    {
        if (src->parent_ == null_node_)
        {
            root_ = replace;
        }
        else if (src == src->parent_->left_child_)
        {
            src->parent_->left_child_ = replace;
        }
        else
        {
            src->parent_->right_child_ = replace;
        }

        replace->parent_ = src->parent_;
    }

private:
    RedBlackNode* root_;
    Comparator IsLessThan;
    RedBlackNode* null_node_;
};

int main(int argc, char* argv[])
{
    RedBlackTree<int> red_black_tree;

    // �������
    red_black_tree.Insert(11);
    red_black_tree.Insert(2);
    red_black_tree.Insert(14);
    red_black_tree.Insert(1);
    red_black_tree.Insert(7);
    red_black_tree.Insert(15);
    red_black_tree.Insert(5);
    red_black_tree.Insert(8);
    red_black_tree.Insert(4);
    red_black_tree.Print();
    cout << endl;

    // ɾ������
    // ��nullptr�ĳ�null_node��ɾ���޸�Ҫ��
    red_black_tree.Remove(8);
    red_black_tree.Print();
    return 0;
}
