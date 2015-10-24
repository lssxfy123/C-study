#ifndef SINGLE_LIST_HPP
#define SINGLE_LIST_HPP

#include <iostream>
using namespace std;

template<class Object>
struct Node
{
    Object data_;
    Node* next_;
    Node(const Object& data = Object(), Node* p = NULL)
        : data_(data), next_(p)
    {
    }
};

template<class Object>
class SingleList
{
public:
    SingleList()
    {
        init();
    }

    ~SingleList()
    {
        eraseList(head_);
    }

    // �����ݽṹ���㷨����C++���������桷��.pdf��15ҳ�Ŀ������캯��������
    // ������ʱ������ڴ����ԭ����Դ����Ϳ������������ڴ�
    SingleList(const SingleList& rhs)
    {
        // ��Debugģʽ�²��ܵ���eraseList
        // ԭ������Debugģʽ�£�δ��ʼ����ָ��head_Ĭ�ϲ�Ϊ��
        // ��Releaseģʽ��û����
        // eraseList(head_);
        init();
        Node<Object>* ptr = rhs.head_->next_;

        // ������Ҫ�ȴ���һ����ʱ������
        // ԭ������������һ��ջ�ˣ�����ȳ�
        // �����������ԭ�����˳�����෴��e
        SingleList temp;
        for (int i = 0; i != rhs.size(); ++i)
        {
            temp.add(ptr->data_);
            ptr = ptr->next_;
        }

        Node<Object>* temp_ptr = temp.head_->next_;
        for (int i = 0; i != rhs.size(); ++i)
        {
            add(temp_ptr->data_);
            temp_ptr = temp_ptr->next_;
        }
        // head_ = rhs.head_;
    }

    bool add(Object x)
    {
        if (contains(x))
        {
            return false;
        }

        Node<Object>* ptr = new Node<Object>(x);
        ptr->next_ = head_->next_;
        head_->next_ = ptr;

        ++size_;
        return true;
    }

    bool remove(Object x)
    {
        if (!contains(x))
        {
            return false;
        }
        else {
            Node<Object>* ptr = head_->next_;
            Node<Object>* before;

            while (ptr->data_ != x)
            {
                before = ptr;
                ptr = ptr->next_;
            }

            before->next_ = ptr->next_;
            delete ptr;
            ptr = ptr->next_;
            --size_;
        }
        return true;
    }

    int size() const { return size_; }

    void print()
    {
        Node<Object>* ptr = head_->next_;
        while (ptr != NULL)
        {
            cout << ptr->data_ << ",";
            ptr = ptr->next_;
        }
        cout << endl;
    }

    bool contains(const Object& x)
    {
        Node<Object>* ptr = head_->next_;
        bool is_exist = false;

        while (ptr != NULL)
        {
            if (ptr->data_ == x)
            {
                is_exist = true;
                break;
            }
            ptr = ptr->next_;
        }
        return is_exist;
    }

    void eraseList(Node<Object>* head)
    {
        Node<Object>* next_ptr;
        while (head != NULL)
        {
            next_ptr = head->next_;
            delete head;
            head = next_ptr;
        }
    }

private:
    void init()
    {
        size_ = 0;
        head_ = new Node<Object>;
        head_->next_ = NULL;
    }

private:
    Node<Object>* head_;
    int size_;
};

#endif
