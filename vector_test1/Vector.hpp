#ifndef VECTOR_HPP
#define VECTOR_HPP

template <class Object>
class Vector
{
// ���������
public:
    class const_iterator
    {
        friend class Vector<Object>;
    public:
        const Object& operator*() const
        {
            return retrieve();
        }

        // ǰ׺++
        const_iterator& operator++ ()
        {
            current_++;
            return *this;
        }

        // ��׺++
        const_iterator& operator++ (int)
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator== (const const_iterator& rhs) const 
        {
            return current_ == rhs.current_;
        }

        bool operator!= (const const_iterator& rhs) const
        {
            return !(*this == rhs);
        }

    protected:
        Object& retrieve() const
        {
            assertIsValid();
            return *current_;
        }

        const_iterator(const Vector<Object>& vec, Object* p)
            : vector_(&vec), current_(p)
        {

        }

        void assertIsValid() const
        {
            if (vector_ == NULL || current_ == NULL)
            {
                throw range_error("iterator is invalid!");
            }
        }
    protected:
        Object* current_;
        const Vector<Object>* vector_;
    };

    class iterator : public const_iterator
    {
        friend class Vector<Object>;

    public:
        Object& operator* ()
        {
            return retrieve();
        }

        const Object& operator* () const
        {
            return const_iterator::operator *();
        }

        iterator& operator++ ()
        {
            ++current_;
            return *this;
        }

        iterator& operator++ (int)
        {
            iterator old = *this;
            ++(*this);
            return old;
        }

    protected:
        iterator(const Vector<Object>& vect, Object* p)
            : const_iterator(vect, p)
        {

        }
    };

public:
    explicit Vector(int init_size = 0) : size_(init_size), capacity_(init_size + SPARE_CAPACITY)
    {
        objects = new Object[capacity_];
    }

    Vector(const Vector& rhs) : objects(NULL)
    {
        operator=(rhs);
    }

    ~Vector()
    {
        delete [] objects;
        objects = NULL;
    }

    const Vector& operator= (const Vector& rhs)
    {
        if (this != &rhs)
        {
            delete [] objects;
            size_ = rhs.size();
            capacity_ = rhs.capacity();
            objects = new Object[capacity_];
            for (int i = 0; i != size_; ++i)
            {
                objects[i] = rhs.objects[i];
            }
        }
        return *this;
    }

    void resize(int new_size)
    {
        // ���������Ż������������
        // ����û�б�Ҫ��������
        if (new_size > capacity_)
        {
            reserve(2 * new_size + 1);
        }
        size_ = new_size;
    }

    // �ı�����
    void reserve(int new_capacity)
    {
        if (new_capacity < size_)
        {
            return;
        }

        Object* old = objects;  // ����֮ǰ�Ķ�������
        objects = new Object[new_capacity];

        for (int i = 0; i != size_; ++i)
        {
            objects[i] = old[i];
        }

        capacity_ = new_capacity;
        delete [] old;
    }

    Object& operator[](int index)
    {
        // ������Ҫ�׳��쳣
        // ��pop_back()�У�ֻ����size_
        // ��û�иı�objects
        if ((index < 0) || (index > (size_ - 1)))
        {
            throw range_error("index is out of range!");
        }
        return objects[index];
    }

    const Object& operator[](int index) const
    {
        if ((index < 0) || (index > (size_ - 1)))
        {
            throw range_error("index is out of range!");
        }
        return objects[index];
    }

    bool empty() const
    {
        return size() == 0;
    }

    int size() const
    {
        return size_;
    }

    int capacity() const
    {
        return capacity_;
    }

    void push_back(const Object& x)
    {
        if (size_ == capacity_)
        {
            reserve(2 * size_ + 1);
        }

        objects[size_] = x;
        ++size_;
    }

    void pop_back()
    {
        if (size_ == 0)
        {
            throw runtime_error("size is 0");
        }
        --size_;
    }

    const Object& back()
    {
        if (size_ < 1)
        {
            throw runtime_error("size is 0");
        }
        return objects[size_ - 1];
    }

    //typedef Object* iterator;
    //typedef const Object* const_iterator;

    iterator begin()
    {
        return iterator(*this, &objects[0]);
        // return &objects[0];
    }

    const_iterator begin() const
    {
        return const_iterator(*this, &objects[0]);
        // return &objects[0];
    }

    iterator end()
    {
        return iterator(*this, &objects[size()]);
        // return &objects[size()];
    }

    const_iterator end() const
    {
        return const_iterator(*this, &objects[size()]);
        // return &objects[size()];
    }

    iterator insert(iterator pos, const Object& x)
    {
        iterator iter = begin();
        Object* old = objects;
        int index = 0;
        ++size_;

        if (capacity_ < size_)
        {
            capacity_ = size_;
        }

        objects = new Object[capacity_];

        while (iter != pos)
        {
            objects[index] = old[index];
            ++iter;
            ++index;
        }
        objects[index] = x;
        for (int k = index + 1; k < size_; ++k)
        {
            objects[k] = old[k - 1];
        }

        delete[] old;
        return iterator(*this, &objects[index]);
    }

    // ɾ��
    iterator erase(iterator pos)
    {
        if (pos == end())
        {
            return pos;
        }

        iterator iter = begin();
        Object* old = objects;
        --size_;
        objects = new Object[capacity_];
        int index = 0;

        while (iter != pos)
        {
            objects[index] = old[index];
            ++iter;
            ++index;
        }

        for (int j = index; j < size_; ++j)
        {
            objects[j] = old[j + 1];
        }

        return iterator(*this, &objects[index]);
    }

    // ��������
    enum {
        SPARE_CAPACITY = 3
    };
private:
    int size_;
    int capacity_;
    Object* objects;
};

#endif  // VECTOR_HPP
