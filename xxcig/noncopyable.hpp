//  Copyright 2013 xxcig group

//
//  noncopyable.hpp
//  ժ���� boost 1.49.0
//  �� noncopyable ��һ�����ࡣ
//  �������ֹ���ƹ���͸��Ƹ�ֵʱ�����Դ� noncopyable ��������ࡣ
//

//  Boost noncopyable.hpp header file  --------------------------------------//

//  (C) Copyright Beman Dawes 1999-2003. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/utility for documentation.

#ifndef NONCOPYABLE_HPP
#define NONCOPYABLE_HPP

// ժ��Google��̹淶
// ɾ�����캯���궨�壬����������������Ϊprivate��
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
TypeName(const TypeName&); \
void operator=(const TypeName&)

namespace xxcig {

//  Private copy constructor and copy assignment ensure classes derived from
//  class noncopyable cannot be copied.

//  Contributed by Dave Abrahams

namespace noncopyable_  {

class noncopyable {
  protected:
    noncopyable() {}
    ~noncopyable() {}

  private:
    noncopyable(const noncopyable&);
    const noncopyable& operator=(const noncopyable&);
};

}  // namespace noncopyable_

typedef noncopyable_::noncopyable noncopyable;

}  // namespace xxcig

#endif  // NONCOPYABLE_HPP
