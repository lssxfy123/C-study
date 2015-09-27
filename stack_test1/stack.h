#ifndef STACK_H
#define STACK_H

#include "queue.h"

class Stack
{
  public:
    Stack();
    ~Stack();

  public:
    bool IsEmpty();
    void Push(int element);
    int Pop(bool& ok);

  private:
    Queue q1_;
    Queue q2_;
};

#endif  // STACK_H
