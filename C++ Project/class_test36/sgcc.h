
#ifndef SGCC_H
#define SGCC_H

namespace sgcc
{
    extern int n;  // 命名空间和全局命名空间类似，不能在头文件中定义变量

    class A
    {
      public:
        A();
        ~A();

      public:
        A& Set();
    };
}

#endif  // SGCC_H
