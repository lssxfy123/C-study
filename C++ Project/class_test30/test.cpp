// �����

#include <iostream>

class Base  // ����
{
  public:
    virtual void func() const
    {
        std::cout << "Base::func()" << std::endl;
    }

    virtual void Print()
    {
        std::cout << "Base::Print()" << std::endl;
    }

    // clone()�������麯�����ο���C++ѧϰ14-��Ķ�̬��.docx���麯����Ҫ��
    // ����Ҫ�������ھ����Handle����δ֪����ʱ���ܹ���ȷ�Ŀ�������ĸ���
    virtual Base* clone() const
    {
        return new Base(*this);
    }
};

class Dervie : public Base  // ������
{
  public:
    void func() const
    {
        std::cout << "Dervie::func()" << std::endl;
    }

    void Print()
    {
        std::cout << "Dervie::Print()" << std::endl;
    }

    Dervie* clone() const
    {
        return new Dervie(*this);
    }
};

class Handle  // ����࣬����һ������ָ��
{
  public:
    Handle() : p(NULL), use(new std::size_t(1))  // ���ü�����ʼ��Ϊ1
    {

    }

    Handle(const Handle& rhs) : p(rhs.p), use(rhs.use)
    {
        ++*use;  // ����ͬ����ı�rhs��useָ����ָ��Ķ����ֵ��rhs��һ������ 
    }

    // ����δ֪���͵Ĺ��캯�������ǿ������캯��,���Ǵ������Ĺ��캯��
    Handle(const Base& b) : p(b.clone()), use(new std::size_t(1))
    {

    }

    Handle& operator=(const Handle&);

    const Base* operator->() const  // ���ؼ�ͷ��������const�汾
    {
        if (p)
        {
            return p;
        }
        else
        {
            throw std::logic_error("unbound Handle");
        }
    }

    Base* operator->()  // ��const�汾
    {
        if (p)
        {
            return p;
        }
        else
        {
            throw std::logic_error("unbound Handle");
        }
    }

    const Base& operator*() const  // ���ؽ����ò�����
    {
        if (p)
        {
            return *p;
        }
        else
        {
            throw std::logic_error("unbound Handle");
        }
    }

    Base& operator*()  // ��const�汾�����ؽ����ò�����
    {
        if (p)
        {
            return *p;
        }
        else
        {
            throw std::logic_error("unbound Handle");
        }
    }

    ~Handle()
    {
        decr_use();
    }

  private:
    void decr_use()
    {
        if (--*use == 0)
        {
            delete p;
            delete use;
            p = NULL;
            use = NULL;
        }
    }

  private:
    Base* p;
    std::size_t* use;
};

Handle& Handle::operator=(const Handle& rhs)
{
    ++*rhs.use;

    decr_use();

    p = rhs.p;
    use = rhs.use;

    return *this;
}

void f(Handle handle)
{
    handle->func();
    handle->Print();
}

int main(int argc, char* argv[])
{
    Base b;
    Dervie d;

    Handle handle1(b);

    // handle1->func()�൱��ִ��
    // (handle1.operator->())->func()
    handle1->func();  // ִ�л���Base��func()
    handle1->Print();  // ִ�л���Base��Print()

    Handle handle2(d);
    handle2->func();  // ִ��������Derive��func()
    handle2->Print();  // ִ��������Derive��Print()

    f(b);
    f(d);

    return 0;
}
