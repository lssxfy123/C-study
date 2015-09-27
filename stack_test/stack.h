#ifndef STACK_H
#define STACK_H

// 定义栈中的节点
typedef struct Node
{
    int element;
    Node* next;
} Node;

class Stack
{
  public:
    Stack();
    ~Stack();

  public:
    bool IsEmpty();
    void Push(int element);
    int Pop(bool& ok);
    int Size() const;

  private:
    void ClearStack();

  private:
    Node* top_ptr_;  // 栈顶指针
    int size_;
};

#endif  // STACK_H
