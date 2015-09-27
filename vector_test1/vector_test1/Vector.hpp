#ifndef VECTOR_HPP
#define VECTOR_HPP

template <class Object>
class Vector
{
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
        // 大于容量才会进行容量更改
        // 否则没有必要更改容量
        if (new_size > capacity_)
        {
            reserve(2 * new_size + 1);
        }
        size_ = new_size;
    }

    // 改变容量
    void reserve(int new_capacity)
    {
        if (new_capacity < size_)
        {
            return;
        }

        Object* old = objects;  // 保存之前的对象数组
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
        // 这里需要抛出异常
        // 在pop_back()中，只减少size_
        // 而没有改变objects
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

    typedef Object* iterator;
    typedef const Object* const_iterator;

    iterator begin()
    {
        return &objects[0];
    }

    const_iterator begin() const
    {
        return &objects[0];
    }

    iterator end()
    {
        return &objects[size()];
    }

    const_iterator end() const
    {
        return &objects[size()];
    }

    // 备用容量
    enum {
        SPARE_CAPACITY = 3
    };
private:
    int size_;
    int capacity_;
    Object* objects;
};

#endif  // VECTOR_HPP
