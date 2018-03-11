// Copyright 2018.刘珅珅
// author：刘珅珅
// 红黑树
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
            // 插入结点要涂成红色，以满足红黑平衡条件5
            RedBlackNode* new_node = new RedBlackNode(value, Red);
            new_node->left_child_ = new_node->right_child_ = null_node_;

            // 将红黑树看成二叉查找树，将结点插入
            RedBlackNode* tmp1 = null_node_;
            RedBlackNode* tmp2 = root_;
            while (tmp2 != null_node_)
            {
                tmp1 = tmp2;

                // tmp2->value_不可能与value相同
                // tmp1存储实际为跳出while循环的tmp2的父结点
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

            // 插入修正
            InsertFixUp(new_node);
        }
    }

    void Remove(const T& value)
    {
        if (Contains(value))
        {
            // 待删除的结点
            RedBlackNode* delete_node = Find(value);
            RedBlackNode* replace = delete_node;
            RedBlackColor original_color = replace->color_;

            // delete_node删除后，需要调整的结点
            RedBlackNode* adjust_node = nullptr;

            // 二叉查找树的删除
            // 要考虑红黑树的父子关系的对应
            if (delete_node->left_child_ == null_node_)  // 0个或1个孩子
            {
                // 0个或1个孩子，从delete_node的子结点开始调整
                adjust_node = delete_node->right_child_;
                Transplant(delete_node, delete_node->right_child_);
            }
            else if (delete_node->right_child_ == null_node_)
            {
                adjust_node = delete_node->left_child_;
                Transplant(delete_node, delete_node->left_child_);
            }
            else  // 两个孩子
            {
                // 查找delete_node结点的右子树的最小结点
                // 也可以寻找左子树的最大结点
                replace = replace->right_child_;
                while (replace->left_child_ != null_node_)
                {
                    replace = replace->left_child_;
                }

                // 保存取代结点的颜色
                original_color = replace->color_;

                // replace左孩子肯定为nullptr
                // replace完全取代了delete_node
                // 包括子结点和颜色，所以从
                // replace的子结点开始调整
                adjust_node = replace->right_child_;

                // delete_node的右孩子就是右子树最小结点
                if (replace->parent_ == delete_node)
                {
                    adjust_node->parent_ = replace;
                }
                else
                {
                    // 设置replace->parent_的子结点
                    Transplant(replace, replace->right_child_);
                    replace->right_child_ = delete_node->right_child_;
                    replace->right_child_->parent_ = replace;
                }

                Transplant(delete_node, replace);
                replace->left_child_ = delete_node->left_child_;
                replace->left_child_->parent_ = replace;
                replace->color_ = delete_node->color_;
            }

            // 如果delete_node有1个或0个孩子，则
            // original_color代表被删结点的颜色，如果
            // 为黑色，有可能会影响红黑性质2和5。
            // 如果delete_node有两个孩子，则
            // original_color代表顶替结点的颜色，如果
            //为黑色，有可能会影响红黑性质5
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

    // 左旋
    // node为被旋转子树的根结点
    // 旋转的方式同avl树、伸展树相同
    // 只是红黑树的旋转还需要设置父子关系
    void LeftRotation(RedBlackNode* node)
    {
        if (node->right_child_ == null_node_)
        {
            return;
        }

        RedBlackNode* new_sub_root = node->right_child_;

        // 新根结点的左孩子为原根结点的右孩子
        // 其父结点也就变成了原根结点
        node->right_child_ = new_sub_root->left_child_;
        if (new_sub_root->left_child_ != null_node_)
        {
            new_sub_root->left_child_->parent_ = node;
        }

        // 原根结点的父结点也是新根结点
        new_sub_root->parent_ = node->parent_;

        if (null_node_ == node->parent_)
        {
            // 空树，将new_sub_root设置为红黑树的根结点
            root_ = new_sub_root;
        }
        else
        {
            if (node->parent_->left_child_ == node)
            {
                // 原根结点为其父结点的左孩子，
                // 则将new_sub_root设置为其父结点的左孩子
                node->parent_->left_child_ = new_sub_root;
            }
            else
            {
                // 原根结点为其父结点的右孩子，
                // 则将new_sub_root设置为其父结点的右孩子
                node->parent_->right_child_ = new_sub_root;
            }
        }

        // 原根结点为新根结点的左孩子
        // 原根结点的父结点为新根结点
        new_sub_root->left_child_ = node;
        node->parent_ = new_sub_root;
    }

    // 右旋
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

    // 插入修正
    void InsertFixUp(RedBlackNode* node)
    {
        // 父结点，如果为空，表示node为红黑树的根结点
        RedBlackNode* parent = nullptr;

        // 祖父结点，如果为空，表示node或node->parent_
        // 为红黑树的根结点.
        RedBlackNode* grand = nullptr;

        // 父结点如果为黑色不需要修复操作
        // 当前结点node始终为红色，这样不会破坏平衡条件5
        // 参考http://blog.csdn.net/v_JULY_v/article/details/6105630
        while (node->parent_->color_ == Red)
        {
            parent = node->parent_;

            // 祖父结点肯定存在而且为黑色，否则就不是红黑树
            // 参考红黑树平衡条件2和4
            grand = parent->parent_;

            // 父结点是祖父结点的左孩子
            if (parent == grand->left_child_)
            {
                // 叔叔结点
                RedBlackNode* uncle = grand->right_child_;

                // Case1：叔叔结点为红色
                if (uncle->color_ == Red)
                {
                    // 父亲和叔叔涂黑，祖父涂红
                    // 是为了满足红黑色的平衡条件4和5
                    uncle->color_ = Black;
                    parent->color_ = Black;
                    grand->color_ = Red;

                    // 涂色完成后，grand以及其子树肯定平衡
                    // 所以将当前结点指向grand结点重新开始平衡修复
                    node = grand;
                }
                else
                {
                    // 叔叔结点有可能不存在，在红黑色中NIL结点为黑色
                    // Case2：叔叔结点为黑色，当前结点为父结点的右孩子
                    if (parent->right_child_ == node)
                    {
                        // 将当前结点的父结点作为新的当前结点进行旋转
                        // 不能直接旋转当前结点，会破坏平衡条件5
                        node = node->parent_;
                        LeftRotation(node);
                    }

                    // Case3：叔叔结点为黑色，当前结点为父结点的左孩子
                    // node的祖父结点初始肯定是黑的，否则无法满足平衡条件4
                    // 红黑树在进行涂色修复和旋转时，一般都是在当前结点的
                    // 父、叔和祖父层完成，这样不会破坏子树的平衡条件
                    node->parent_->color_ = Black;
                    node->parent_->parent_->color_ = Red;

                    // node的祖父结点的平衡条件5被破坏
                    // 通过右旋将黑色结点的node->parent_作为新的子树根结点
                    // 从而保持子树的红黑平衡
                    RightRotation(node->parent_->parent_);
                }
            }
            else  // 父结点是祖父结点的右孩子
            {
                RedBlackNode* uncle = grand->left_child_;

                // Case1：叔叔结点为红色
                if (uncle->color_ == Red)
                {
                    uncle->color_ = Black;
                    parent->color_ = Black;
                    grand->color_ = Red;
                    node = grand;
                }
                else
                {
                    // Case2：叔叔结点为黑色，当前结点为父结点的右孩子
                    if (parent->left_child_ == node)
                    {
                        node = node->parent_;
                        RightRotation(node);
                    }

                    // Case3：叔叔结点为黑色，当前结点为父结点的左孩子
                    node->parent_->color_ = Black;
                    node->parent_->parent_->color_ = Red;
                    LeftRotation(node->parent_->parent_);
                }
            }
        }

        // 根结点设置为黑色
        root_->color_ = Black;
    }

    // 删除修正
    // node为用来顶替被删结点的结点或其子结点
    void RemoveFixUp(RedBlackNode* node)
    {
        while (node != root_ && node->color_ == Black)
        {
            if (node == node->parent_->left_child_)
            {
                // 兄弟结点，肯定存在否则破坏红黑平衡条件5
                // 结点本身为黑色
                RedBlackNode* brother = node->parent_->right_child_;

                // Case1：兄弟结点是红色
                // 父结点和兄弟结点的子结点肯定为黑
                if (brother->color_ == Red)
                {
                    brother->color_ = Black;
                    node->parent_->color_ = Red;  // 父结点涂成红色
                    LeftRotation(node->parent_);

                    // 继续判断是否符合Case2，Case 3，Case4
                    brother = node->parent_->right_child_;
                }

                if (brother->left_child_->color_ == Black
                    && brother->right_child_->color_ == Black)
                {
                    // Case 2：兄弟结点是黑色，其两个子结点为黑色
                    // nullptr结点视为黑色
                    brother->color_ = Red;
                    node = node->parent_;
                }
                else
                {
                    if (brother->right_child_->color_ == Black)
                    {
                        // Case3：兄弟结点为黑色，其左孩子为红色，
                        // 右孩子为黑色
                        brother->left_child_->color_ = Black;
                        brother->color_ = Red;
                        RightRotation(brother);
                        brother = node->parent_->right_child_;
                    }

                    // Case4：兄弟结点为黑色，其右孩子为红色，左孩子任意
                    // Case3经过RightRotation后，满足Case4
                    brother->color_ = node->parent_->color_;
                    node->parent_->color_ = Black;
                    brother->right_child_->color_ = Black;
                    LeftRotation(node->parent_);
                    node = root_;  // 调整结束
                    break;
                }
            }
            else
            {
                RedBlackNode* brother = node->parent_->left_child_;
                if (brother->color_ == Red)
                {
                    // Case1：兄弟结点为红色
                    brother->color_ = Black;
                    node->parent_->color_ = Red;
                    RightRotation(node->parent_);
                    brother = node->parent_->left_child_;
                }

                if (brother->left_child_->color_ == Black
                    && brother->right_child_->color_ == Black)
                {
                    // Case 2：兄弟结点是黑色，其两个子结点为黑色
                    // nullptr结点视为黑色
                    brother->color_ = Red;
                    node = node->parent_;  // 尽可能向根移动
                }
                else
                {
                    if (brother->left_child_->color_ == Black)
                    {
                        // Case3：兄弟结点为黑色，左孩子为黑色，右孩子为红色
                        brother->right_child_->color_ = Black;
                        brother->color_ = Red;
                        LeftRotation(brother);
                        brother = node->parent_->left_child_;
                    }

                    // Case4：兄弟为黑色，左孩子为红色，右孩子任意
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
            if (direction == 0)    // 根节点
            {
                cout << setw(2) << node->value_ << "(Black) is root" << endl;
            }
            else                // 分支节点
            {
                cout << setw(2) << node->value_ << (node->color_ == Red ? "(Red)" : "(Black)") << " is " 
                    << setw(2) << value << "'s " 
                    << setw(12) << (direction == 1 ? "right child" : "left child") << endl;
            }
            
            Print(node->left_child_, node->value_, -1);
            Print(node->right_child_, node->value_, 1);
        }
    }

    // 红黑子树的移植
    // 用replace替换src
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

    // 插入测试
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

    // 删除测试
    // 将nullptr改成null_node，删除修复要用
    red_black_tree.Remove(8);
    red_black_tree.Print();
    return 0;
}
