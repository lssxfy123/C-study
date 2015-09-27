#ifndef LIST_HPP
#define LIST_HPP

template <class Object>
class List
{

// ˽�е�Ƕ����
private:
    struct Node
    {
        Object data_;
        Node* prev_;
        Node* next_;

        Node(const Object& d = Object(), Node* p = NULL, Node* n = NULL)
            : data_(d), prev_(p), next_(n)
        {

        }
    };

public:
    class const_iterator
    {
        // ��Χ���Ƕ����ķ��ʿ���û���κ�������
        // Ƕ�������Χ��Ҳ�����
        friend class List<Object>;

    public:
        const_iterator() : current_(NULL)
        {

        }

        const Object& operator* () const
        {
            return retrieve();
        }

        // ǰ׺++���������
        const_iterator& operator++ ()
        {
            current_ = current_->next_;
            return *this;
        }

        // ��׺++���������
        // int������Զ��ʹ��
        // ֻ��Ϊ������ǰ׺++�ͺ�׺++
        const_iterator& operator++(int)
        {
            const_iterator old = *this;
            ++(*this);  // ����ǰ׺++��������غ���
            return old;
        }

        bool operator==(const const_iterator& rhs) const
        {
            return current_ == rhs.current_;
        }

        bool operator!=(const const_iterator& rhs) const
        {
            // �������ص�==�����
            return !(*this == rhs);
        }

    protected:
        Node* current_;

        Object& retrieve() const
        {
            // Node��˽��Ƕ���࣬�����ԱΪ����
            return current_->data_;
        }

        const_iterator(Node* p) : current_(p)
        {

        }
    };

public:
    class iterator : public const_iterator
    {
        friend class List<Object>;
    public:
        iterator()
        {

        }

        Object& operator* ()
        {
            return retrieve();
        }

        const Object& operator* ()const
        {
            return const_iterator::operator *();
        }

        // �����++���ز����麯��
        // �����ػ����++���������
        iterator& operator++ ()
        {
            current_ = current_->next_;
            return *this;
        }

        iterator& operator++ (int)
        {
            iterator old = *this;
            ++(*this);
            return old;
        }

    protected:
        iterator(Node* p) : const_iterator(p)
        {
        }
    };

public:
    List()
    {
        init();
    }

    ~List()
    {

    }

    int size() const
    {
        return size_;
    }

    bool empty() const
    {
        return size_ == 0;
    }

    iterator begin()
    {
        // head_�����ͷ��㣬����list�����е���Ч���
        // ��data_û��ֵ
        return iterator(head_->next_);
    }

    const_iterator begin() const
    {
        return const_iterator(head_->next_);
    }

    iterator end()
    {
        // tail_�����β��㣬ͬ��������Ч���
        return iterator(tail_);
    }

private:
    void init()
    {
        size_ = 0;
        head_ = new Node;
        tail_ = new Node;
        head_->next_ = tail_;
        tail_->prev_ = head_;
    }

private:
    int size_;
    Node* head_;  // ��ͷ���
    Node* tail_;  // β���

};

#endif  // LIST_HPP
