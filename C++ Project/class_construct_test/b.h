#ifndef B_H
#define B_H

#include "a.h"

class B
{
  public:
    B(int& i);
    ~B();

  public:
    void PrintValue();

  private:
    const int ten;
    int& ref;

    A a;
};

#endif  // B_H
