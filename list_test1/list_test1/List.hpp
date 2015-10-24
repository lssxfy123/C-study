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

        //前缀--运算符重载
        const_iterator& operator-- ()
        {
            current_ = current_->prev_;
            return *this;
        }

        // 后缀--运算符重载
        const_iterator& operator-- (int)
        {
            const_iterator old = *this;
            --(*this);
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

        //前缀--运算符重载
        iterator& operator-- ()
        {
            current_ = current_->prev_;
            return *this;
        }

        // 后缀--运算符重载
        iterator& operator-- (int)
        {
            const_iterator old = *this;
            --(*this);
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

    List(const List& rhs)
    {
        init();
        *this = rhs; // 调用了重载的运算符=
    }

    ~List()
    {
        clear();
        delete head_;
        delete tail_;
    }

    const List& operator=(const List& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }

        clear();

        for (const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
        {
            push_back(*itr);
        }
    }

    int size() const
    {
        return size_;
    }

    bool empty() const
    {
        return size_ == 0;
    }

    void clear()
    {
        while (!empty())
        {
            pop_front();
        }
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

    const_iterator end() const
    {
        // tail_结点是尾结点，同样不是有效结点
        return const_iterator(tail_);
    }

    Object& front()
    {
        return *begin();
    }

    const Object& front() const
    {
        return *begin();
    }

    Object& back()
    {
        return *--end();
    }

    const Object& back() const
    {
        return *--end();
    }

    // 插入尾部
    void push_back(const Object& x)
    {
        insert(end(), x);
    }

    // 插入头部
    void push_front(const Object& x)
    {
        insert(begin(), x);
    }

    void pop_front()
    {
        erase(begin());
    }

    void pop_back()
    {
        erase(--end());
    }

    // 在标准的STL模板中，insert函数是在迭代器指向
    // 的位置之前插入元素，原因是迭代器可能
    iterator insert(iterator itr, const Object& x)
    {
        Node* p = itr.current_;

        // 插入节点的前驱节点为节点p的前驱节点
        // 其后继节点为p
        Node* new_node = new Node(x, p->prev_, p);

        // 将p的前驱节点的后继节点指向插入节点
        // 然后将p的前驱节点指向插入节点，这样
        // 就将节点插入到链表中
        p->prev_->next_ = new_node;
        p->prev_ = new_node;
        ++size_;

        return iterator(p->prev_);
        // 这里有一个简化的写法
        // return iterator(p->prev_ = p->prev_->next_ = new Node(x, p->prev_, p));
    }

    // 删除迭代器指向的节点
    iterator erase(iterator itr)
    {
        Node* p = itr.current_;

        // 将要删除的节点的后继节点返回
        iterator itr1(p->next_);

        // 将当前节点的前驱节点的后继节点指向当前节点的后继节点
        p->prev_->next_ = p->next_;

        // 将当前节点的后继节点的前驱节点指向当前节点的前驱节点
        p->next_->prev_ = p->prev_;
        delete p;
        --size_;

        return itr1;
    }

    iterator erase(iterator start, iterator end)
    {
        for (iterator itr = start; itr != end;)
        {
            itr = erase(itr);
        }

        return end;
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
