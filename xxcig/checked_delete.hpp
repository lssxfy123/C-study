//  Copyright 2013 xxcig group

//
//  checked_delete.hpp
//  摘抄自 boost 1.49.0
//  带完整性类型检查的删除操作避免前向声明造成的内存泄漏
//

#ifndef CHECKED_DELETE_HPP
#define CHECKED_DELETE_HPP

//
//  boost/checked_delete.hpp
//
//  Copyright (c) 2002, 2003 Peter Dimov
//  Copyright (c) 2003 Daniel Frey
//  Copyright (c) 2003 Howard Hinnant
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//  See http://www.boost.org/libs/utility/checked_delete.html for documentation.
//

namespace xxcig {
// verify that types are complete for increased safety

template<class T>
inline void checked_delete(T * x)
{
    // intentionally complex - simplification causes regressions
    typedef char type_must_be_complete[ sizeof(T)? 1: -1 ];
    (void) sizeof(type_must_be_complete);
    delete x;
}

template<class T>
inline void checked_ptr_array_delete(T * x)
{
    typedef char type_must_be_complete[ sizeof(T)? 1: -1 ];
    (void) sizeof(type_must_be_complete);
    delete [] x;
}

template<class T>
struct checked_deleter {
    typedef void result_type;
    typedef T * argument_type;

    void operator()(T * x) const
    {
        checked_delete(x);
    }
};

template<class T>
struct checked_ptr_array_deleter {
    typedef void result_type;
    typedef T * argument_type;

    void operator()(T * x) const
    {
        checked_ptr_array_delete(x);
    }
};

template<class T>
inline void destroy(T*& p)
{
    delete p;
    p = 0;
}

}  // namespace xxcig

#endif  // #ifndef CHECKED_DELETE_HPP
