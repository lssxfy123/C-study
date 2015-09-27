#ifndef LIST_HPP
#define LIST_HPP

template <class Object>
class List
{

// 私有的嵌套类
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
        // 外围类对嵌套类的访问控制没有任何特殊性
        // 嵌套类对外围类也是如此
        friend class List<Object>;

    public:
        const_iterator() : current_(NULL)
        {

        }

        const Object& operator* () const
        {
            return retrieve();
        }

        // 前缀++运算符重载
        const_iterator& operator++ ()
        {
            current_ = current_->next_;
            return *this;
        }

        // 后缀++运算符重载
        // int参数永远不使用
        // 只是为了区分前缀++和后缀++
        const_iterator& operator++(int)
        {
            const_iterator old = *this;
            ++(*this);  // 调用前缀++运算符重载函数
            return old;
        }

        bool operator==(const const_iterator& rhs) const
        {
            return current_ == rhs.current_;
        }

        bool operator!=(const const_iterator& rhs) const
        {
            // 调用重载的==运算符
            return !(*this == rhs);
        }

    protected:
        Node* current_;

        Object& retrieve() const
        {
            // Node是私有嵌套类，但其成员为公有
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

        // 运算符++重载不是虚函数
        // 会隐藏基类的++运算符重载
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
        // head_结点是头结点，不是list链表中的有效结点
        // 其data_没有值
        return iterator(head_->next_);
    }

    const_iterator begin() const
    {
        return const_iterator(head_->next_);
    }

    iterator end()
    {
        // tail_结点是尾结点，同样不是有效结点
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
    Node* head_;  // 表头结点
    Node* tail_;  // 尾结点

};

#endif  // LIST_HPP
