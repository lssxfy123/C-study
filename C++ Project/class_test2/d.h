#ifndef D_H
#define D_H

class D
{
  public:
    // 下面两个Display函数可以构成重载
    D& Display();
    const D& Display() const;
    void func();
};


#endif  // D_H
