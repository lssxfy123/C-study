//  Copyright 2013 xxcig group

//
//  next_prior.hpp
//  ժ���� boost 1.49.0
//  ��Щ�������ͣ���C++��׼���ǰ���˫������������ṩ operator+() �� operator-() �ļӷ��ͼ�����
//  ����ζ�ż�ʹ�Ѿ����� operator++() �� operator--()��������벻�޸�ԭֵ����� next �� prior ֵ����Ҫһ����ʱ�洢��
//  ��Ҳ��ζ����һ��ģ���б�д�� itr+1 �����Ĵ���������˵�������������������ʵ�������
//  next() �� prior() �����ṩ��һ���ƹ���Щ����ļ򵥷�����
//

//  Boost next_prior.hpp header file  ---------------------------------------//

//  (C) Copyright Dave Abrahams and Daniel Walker 1999-2003. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/utility for documentation.

//  Revision History
//  13 Dec 2003  Added next(x, n) and prior(x, n) (Daniel Walker)

#ifndef NEXT_PRIOR_HPP
#define NEXT_PRIOR_HPP

#include <iterator>

namespace xxcig {

//  Helper functions for classes like bidirectional iterators not supporting
//  operator+ and operator-
//
//  Usage:
//    const std::list<T>::iterator p = get_some_iterator();
//    const std::list<T>::iterator prev = boost::prior(p);
//    const std::list<T>::iterator next = boost::next(prev, 2);

//  Contributed by Dave Abrahams

template <class T>
inline T next(T x)
{
    return ++x;
}

template <class T, class Distance>
inline T next(T x, Distance n)
{
    std::advance(x, n);
    return x;
}

template <class T>
inline T prior(T x)
{
    return --x;
}

template <class T, class Distance>
inline T prior(T x, Distance n)
{
    std::advance(x, -n);
    return x;
}

}  // namespace xxcig

#endif  // NEXT_PRIOR_HPP
