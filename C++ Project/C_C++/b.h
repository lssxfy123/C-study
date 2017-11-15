#ifndef B_H
#define B_H

// 头文件在编译时直接插入到源文件中
// cpp文件会默认定义__cplusplus
// 之所以采用两个条件指令#ifdef
// 是因为如果不是cpp文件，则直接
// 定义#include "a.h"
#ifdef __cplusplus

// extern "C"是提示编译器
// a.h中的函数按照C语言的方式编译
// C++中支持函数重载，而C语言不支持
// 这导致在编译时，函数被内部命名的方式
// 不同
extern "C"
{
#endif

#include "a.h"

#ifdef __cplusplus
};

#endif

void func();

#endif  // B_H
