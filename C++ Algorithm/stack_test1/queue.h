// 队列

#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node
{
    int element;
    Node* next;
} Node;

class Queue
{
  public:
    Queue();
    ~Queue();

  public:
    void EnQueue(int element);
    int DeQueue(bool& ok);
    bool IsEmpty();
    int Size() const;

  private:
    void ClearQueue();

  private:
    Node* front_ptr_;  // 头节点
    Node* rear_ptr_;   // 尾节点
    int size_;
};

#endif  // QUEUE_H

