//  Copyright 2013 xxcig group

//
//  scoped_ptr.hpp
//  ժ���� boost 1.49.0 Smart Pointers ����ָ��
//  scoped_ptr class template��ģ��洢һ��ָ��̬��������ָ�루��̬����������� C++ new ���ʽ����ģ���
//  �� scoped_ptr �����������У����߾���һ����ʽ�� reset��Ҫ��֤����ָ��Ķ���ɾ��
//  scoped_ptr ģ���ǽ������Ҫ�ļ򵥷��������ṩ��һ�������ġ���Դ��ȡ���ǳ�ʼ�����Ļ��ƣ���������������Ȩ������Ȩת�����塣
//  �����������ֻ��������ϵ�ǿ��Ҫ����Ϊһ�� noncopyable��������ΨһĿ�ľ����ڵ�ǰ�������ڶ��Ա�������Ȩ��
//  ��Ϊ���� noncopyable�����ɿ����ģ������ڲ��ɿ�����ָ����˵������ shared_ptr �� std::auto_ptr ���Ӱ�ȫ��
//  ��Ϊ scoped_ptr �ܼ򵥣�������ͨ��ʵ���У�ÿһ�����������ڽ�ָ����ͬ�����ٶȣ����ҵ�����ռ�õĿռ�û�г����ڽ�ָ�롣
//  scoped_ptr �������� C++ ��׼���е������У��������Ҫһ����������������ָ�룬��ʹ�� shared_ptr��
//  scoped_ptr ������ȷ����ָ��һ����̬���������ָ�롣���������÷���μ� scoped_array��
//
//


#ifndef SCOPED_PTR_HPP
#define SCOPED_PTR_HPP

//  (C) Copyright Greg Colvin and Beman Dawes 1998, 1999.
//  Copyright (c) 2001, 2002 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//  http://www.boost.org/libs/smart_ptr/scoped_ptr.htm
//

#include <checked_delete.hpp>

#include <algorithm>

namespace xxcig {
//  scoped_ptr mimics a built-in pointer except that it guarantees deletion
//  of the object pointed to, either on destruction of the scoped_ptr or via
//  an explicit reset(). scoped_ptr is a simple solution for simple needs;
//  use shared_ptr or std::auto_ptr if your needs are more complex.

template<class T>
class scoped_ptr  {
  private:
    typedef scoped_ptr<T> this_type;

    T* px;

    explicit scoped_ptr(scoped_ptr const&);

    scoped_ptr& operator=(scoped_ptr const&);

    void operator==(scoped_ptr const&) const;

    void operator!=(scoped_ptr const&) const;

  public:
    typedef T element_type;

    explicit scoped_ptr(T* p = NULL): px(p)
    {}

    ~scoped_ptr()
    {
        checked_delete(px);
    }

    void reset(T* p = NULL)
    {
        this_type(p).swap(*this);
    }

    T& operator*() const
    {
        return *px;
    }

    T * operator->() const
    {
        return px;
    }

    T* get() const
    {
        return px;
    }

    void swap(scoped_ptr& b)
    {
        T* tmp = b.px;
        b.px = px;
        px = tmp;
    }
};

template<class T>
inline void swap(scoped_ptr<T>& a, scoped_ptr<T>& b)
{
    a.swap(b);
}

template<class T>
inline T* get_pointer(scoped_ptr<T> const& p)
{
    return p.get();
}

}  // namespace xxcig

#endif  // #ifndef SCOPED_PTR_HPP
