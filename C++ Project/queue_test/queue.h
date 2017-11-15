#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h"

class Queue
{
  public:
    Queue();
    ~Queue();

  public:
    void EnQueue(int element);
    int DeQueue(bool& ok);
    bool IsEmpty();

  private:
    Stack en_stack_;  // 
    Stack de_stack_;
};

#endif  // QUEUE_H

