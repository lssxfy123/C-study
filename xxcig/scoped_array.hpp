//  Copyright 2013 xxcig group

//
//  scoped_ptr.hpp
//  ժ���� boost 1.49.0 Smart Pointers ����ָ��
//  scoped_array ��ģ��洢һ��ָ��һ����̬���������ָ�루��̬������������ C++ new[] ���ʽ����ģ���
//  �� scoped_array �����������У����߾���һ����ʽ�� reset��Ҫ��֤����ָ������鱻ɾ����
//  scoped_array ģ���ǽ������Ҫ�ļ򵥷��������ṩ��һ�������ġ���Դ��ȡ���ǳ�ʼ�����Ļ��ƣ���������������Ȩ������Ȩת�����塣
//  �����������ֻ��������ϵ�ǿ��Ҫ����Ϊһ�� noncopyable��������ΨһĿ�ľ����ڵ�ǰ�������ڶ��Ա�������Ȩ��
//  ��Ϊ���� noncopyable�����ɿ����ģ������ڲ��ɿ�����ָ����˵������ shared_array ���Ӱ�ȫ��
//  ��Ϊ scoped_array �ܼ򵥣�������ͨ��ʵ���У�ÿһ�����������ڽ�����ָ����ͬ�����ٶȣ����ҵ�����ռ�õĿռ�û�г����ڽ�����ָ�롣
//  ���������� C++ ��׼���е������У���� scoped_array �������������Ҫ����ο� shared_array��
//  ��������ȷ�س���ָ�򵥶������ָ�롣���������÷���μ� scoped_ptr��
//  һ�� std::vector ��һ�ֿ��Դ��� scoped_array �Ŀ�ѡ������ֻ��Ҫ��΢һ��Ķ�����ۣ����Եõ����������ԡ�
//  һ�� boost::array ��һ�ֲ�ʹ�ö�̬����ʱ�Ŀ�ѡ������
//

#ifndef SCOPED_ptr_array_HPP
#define SCOPED_ptr_array_HPP

//  (C) Copyright Greg Colvin and Beman Dawes 1998, 1999.
//  Copyright (c) 2001, 2002 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//  http://www.boost.org/libs/smart_ptr/scoped_array.htm
//

#include <checked_delete.hpp>

#include <algorithm>
#include <cstddef>

namespace xxcig {
//  scoped_array extends scoped_ptr to arrays. Deletion of the array pointed to
//  is guaranteed, either on destruction of the scoped_array or via an explicit
//  reset(). Use shared_array or std::vector if your needs are more complex.

template<class T>
class scoped_array  {
  private:
    typedef scoped_array<T> this_type;

    T* px;

    explicit scoped_array(scoped_array const&);

    scoped_array& operator=(scoped_array const&);

    void operator==(scoped_array const&) const;

    void operator!=(scoped_array const&) const;

  public:
    typedef T element_type;

    explicit scoped_array(T* p = NULL) : px(p)
    {}

    ~scoped_array()
    {
        checked_ptr_array_delete(px);
    }

    void reset(T* p = NULL)
    {
        this_type(p).swap(*this);
    }

    T& operator[](ptrdiff_t i) const
    {
        return px[i];
    }

    T* get() const {
        return px;
    }

    void swap(scoped_array& b)
    {
        T* tmp = b.px;
        b.px = px;
        px = tmp;
    }
};

template<class T>
inline void swap(scoped_array<T>& a, scoped_array<T>& b)
{
    a.swap(b);
}

}  // namespace xxcig

#endif  // #ifndef SCOPED_ptr_array_HPP
