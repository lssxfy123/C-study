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

        //ǰ׺--���������
        const_iterator& operator-- ()
        {
            current_ = current_->prev_;
            return *this;
        }

        // ��׺--���������
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

        //ǰ׺--���������
        iterator& operator-- ()
        {
            current_ = current_->prev_;
            return *this;
        }

        // ��׺--���������
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
        *this = rhs; // ���������ص������=
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

    const_iterator end() const
    {
        // tail_�����β��㣬ͬ��������Ч���
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

    // ����β��
    void push_back(const Object& x)
    {
        insert(end(), x);
    }

    // ����ͷ��
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

    // �ڱ�׼��STLģ���У�insert�������ڵ�����ָ��
    // ��λ��֮ǰ����Ԫ�أ�ԭ���ǵ���������
    iterator insert(iterator itr, const Object& x)
    {
        Node* p = itr.current_;

        // ����ڵ��ǰ���ڵ�Ϊ�ڵ�p��ǰ���ڵ�
        // ���̽ڵ�Ϊp
        Node* new_node = new Node(x, p->prev_, p);

        // ��p��ǰ���ڵ�ĺ�̽ڵ�ָ�����ڵ�
        // Ȼ��p��ǰ���ڵ�ָ�����ڵ㣬����
        // �ͽ��ڵ���뵽������
        p->prev_->next_ = new_node;
        p->prev_ = new_node;
        ++size_;

        return iterator(p->prev_);
        // ������һ���򻯵�д��
        // return iterator(p->prev_ = p->prev_->next_ = new Node(x, p->prev_, p));
    }

    // ɾ��������ָ��Ľڵ�
    iterator erase(iterator itr)
    {
        Node* p = itr.current_;

        // ��Ҫɾ���Ľڵ�ĺ�̽ڵ㷵��
        iterator itr1(p->next_);

        // ����ǰ�ڵ��ǰ���ڵ�ĺ�̽ڵ�ָ��ǰ�ڵ�ĺ�̽ڵ�
        p->prev_->next_ = p->next_;

        // ����ǰ�ڵ�ĺ�̽ڵ��ǰ���ڵ�ָ��ǰ�ڵ��ǰ���ڵ�
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
    Node* head_;  // ��ͷ���
    Node* tail_;  // β���

};

#endif  // LIST_HPP
