// Copyright 2019.刘珅珅
// author：刘珅珅
// 用栈实现队列
#include <iostream>
#include <stack>
#include "../../include/print.hpp"
using namespace std;

class MyQueue {
public:
    MyQueue() {
        // do intialization if necessary
    }

    /*
    * @param element: An integer
    * @return: nothing
    */
    void push(int element) {
        // write your code here
        data_stack_.push(element);
    }

    /*
    * @return: An integer
    */
    int pop() {
        // write your code here
        int result = -1;
        if (tmp_stack_.empty())
        {
            while (data_stack_.size() > 1)
            {
                tmp_stack_.push(data_stack_.top());
                data_stack_.pop();
            }
            result = data_stack_.top();
            data_stack_.pop();
        }
        else
        {
            result = tmp_stack_.top();
            tmp_stack_.pop();
        }
        return result;
    }

    /*
    * @return: An integer
    */
    int top() {
        // write your code here
        int result = -1;
        if (tmp_stack_.empty())
        {
            while (data_stack_.size() > 0)
            {
                tmp_stack_.push(data_stack_.top());
                data_stack_.pop();
            }
            result = tmp_stack_.top();
        }
        else
        {
            result = tmp_stack_.top();
        }
        return result;
    }

private:
    stack<int> data_stack_;
    stack<int> tmp_stack_;
};

int main(int argc, char* argv[])
{
    MyQueue queue;
    queue.push(1);
    cout << queue.pop() << endl;
    queue.push(2);
    queue.push(3);
    cout << queue.top() << endl;
    cout << queue.pop() << endl;
    return 0;
}
