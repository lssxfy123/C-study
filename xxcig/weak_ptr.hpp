//  Copyright 2013 xxcig group

//  weak_ptr.hpp
//  ժ���� boost 1.49.0 Smart Pointers ����ָ��
//  weak_ptr ��ģ��洢һ�������ѱ� shared_ptr ����Ķ���� "weak reference"�������ã���
//  Ϊ�˷����������һ�� weak_ptr �������� shared_ptr �Ĺ��캯�����Ա���� lock ת��Ϊ shared_ptr��
//  �����һ��ָ������ shared_ptr ��ʧ��������Ҳ��ɾ���󣬴�һ�������ѱ�ɾ������� weak_ptr ʵ����ȡ shared_ptr ����ͼ�ͻ�ʧ�ܣ�
//  ���캯�����׳�һ�� boost::bad_weak_ptr ���͵��쳣���� weak_ptr::lock �᷵��һ�� empty shared_ptr��
//  ÿһ�� weak_ptr ������ C++ ��׼��� CopyConstructible �� Assignable �ı�Ҫ������������ܹ����ڱ�׼����������Ϊ�ṩ�˱Ƚϲ�������� weak_ptr ���Ժͱ�׼���еĹ���ʽ����һ������
//  weak_ptr �Ĳ����������׳��쳣�� �����ģ�屻 T ��������T �Ǳ�ָ��Ķ�������͡�
//  ����� shared_ptr��weak_ptr �ṩ��һ���ǳ����޵Ĳ����Ӽ�����Ϊ�ڶ��̳߳����з��������洢��ָ���Ƿǳ�Σ�յģ�������ʱ��һ�����̳߳�����Ҳ�ǲ���ȫ�ģ�Ҳ����˵������������δ������Ϊ����
//  ���Ҽ��� weak_ptr ��һ������ raw pointer����ָ�룩�� get ��Ա����
//

#ifndef WEAK_PTR_HPP
#define WEAK_PTR_HPP

//
//  weak_ptr.hpp
//
//  Copyright (c) 2001, 2002, 2003 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
//  See http://www.boost.org/libs/smart_ptr/weak_ptr.htm for documentation.
//

#include <shared_count.hpp>
#include <shared_ptr.hpp>

#include <algorithm>

namespace xxcig {

template<class Y>
class shared_ptr;

template<class Y>
class weak_ptr;

template<class T>
class weak_ptr {
    template<class Y> friend class shared_ptr;
    template<class Y> friend class weak_ptr;

  private:
    T* px;          // contained pointer
    weak_count pn;  // reference counter

  private:
    // Borland 5.5.1 specific workarounds
    typedef weak_ptr<T> this_type;

  public:
    typedef T element_type;

    weak_ptr() : px(0), pn() {}

    weak_ptr(weak_ptr const& r) : px(r.px), pn(r.pn) {}  // NOLINT

    weak_ptr& operator=(weak_ptr const& r)
    {
        px = r.px;
        pn = r.pn;
        return *this;
    }

//    template<class Y>
//    weak_ptr(weak_ptr<Y> const& r)
//        : px(r.lock().get()), pn(r.pn) {}

//    template<class Y>
//    weak_ptr(weak_ptr<Y> && r): px(r.lock().get()), pn(static_cast< weak_count && >(r.pn))
//    {
//        r.px = 0;
//    }

//    weak_ptr(weak_ptr && r): px(r.px), pn(static_cast< weak_count && >(r.pn))
//    {
//        r.px = 0;
//    }

//    weak_ptr& operator=(weak_ptr && r)
//    {
//        this_type(static_cast< weak_ptr && >(r)).swap(*this);
//        return *this;
//    }

    template<class Y>
    weak_ptr(shared_ptr<Y> const& r) : px(r.px), pn(r.pn) {}  // NOLINT

    shared_ptr<T> lock() const
    {
        return shared_ptr<element_type>(*this, sp_nothrow_tag());
    }

    int use_count() const
    {
        return pn.use_count();
    }

    bool expired() const
    {
        return pn.use_count() == 0;
    }

    bool _empty() const
    {
        return pn.empty();
    }

    void reset()
    {
        this_type().swap(*this);
    }

    void swap(this_type& other)
    {
        std::swap(px, other.px);
        pn.swap(other.pn);
    }

//    void _internal_assign(T * px2, shared_count const& pn2)
//    {
//        px = px2;
//        pn = pn2;
//    }

    template<class Y>
    bool owner_before(weak_ptr<Y> const& rhs) const
    {
        return pn < rhs.pn;
    }

    template<class Y>
    bool owner_before(shared_ptr<Y> const& rhs) const
    {
        return pn < rhs.pn;
    }
};  // weak_ptr

template<class T, class U>
inline bool operator<(weak_ptr<T> const& a, weak_ptr<U> const& b)
{
    return a.owner_before(b);
}

template<class T>
void swap(weak_ptr<T>& a, weak_ptr<T>& b)
{
    a.swap(b);
}

}  // namespace xxcig

#endif  // #ifndef WEAK_PTR_HPP
