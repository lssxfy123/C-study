#ifndef FOPOW_H
#define FOPOW_H

#include <cmath>

template <typename T, typename V>
struct fopow
{
    T operator() (T base, V exp) const
    {
        return std::pow(base, exp);
    }
};

#endif
