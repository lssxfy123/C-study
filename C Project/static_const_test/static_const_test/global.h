#ifndef GLOBAL_H
#define GLOBAL_H

static int i = 5;  // 可以这样在头文件中定义一个静态变量
// const int j = 6;  //error：在C语言中不能这样定义一个常量， 在C++中可以这样在头文件中定义一个常量
extern const int m;

#endif
