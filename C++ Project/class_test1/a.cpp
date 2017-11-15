#include "a.h"

A::A()
{

}

A::~A()
{

}

A::Index A::func()  // 返回值的类型为类的私有变量
{
    return cursor_;
}
