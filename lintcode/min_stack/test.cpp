// Copyright 2019.刘珅珅
// author：刘珅珅
// 带有最小值操作的栈
#include <iostream>
#include <algorithm>
#include <stack>
#include "../../include/print.hpp"
using namespace std;

class MinStack {
public:
    MinStack() {
        // do intialization if necessary
    }

    /*
    * @param number: An integer
    * @return: nothing
    */
    void push(int number) {
        // write your code here
        data_stack_.push(number);
        if (min_stack_.empty())
        {
            min_stack_.push(number);
        }
        else
        {
            // 将二者之间较小的元素压入min_stack_中
            // 这样min_stack_可能有多个相同值，data_stack_
            // 和min_stack_的长度是相同的。这样做
            // 的原因是在pop()时，data_stack_和min_stack_同时pop()
            min_stack_.push(std::min(min_stack_.top(), number));
        }
    }

    /*
    * @return: An integer
    */
    int pop() {
        // write your code here
        auto result = data_stack_.top();
        data_stack_.pop();
        min_stack_.pop();
        return result;
    }

    /*
    * @return: An integer
    */
    int min() {
        // write your code here
        if (!data_stack_.empty())
        {
            return min_stack_.top();
        }
        return -1;
    }

private:
    stack<int> data_stack_;
    stack<int> min_stack_;
};

class MinStack1 {
public:
    MinStack1() {
        // do intialization if necessary
    }

    /*
    * @param number: An integer
    * @return: nothing
    */
    void push(int number) {
        // write your code here
        data_stack_.push(number);

        // 只把小于等于min_stack_.top()的元素压入栈
        // 注意一定要考虑等于的情况，因为在pop()时
        // data_stack_.top()等于min_stack_.top()时，
        // 才会把min_stack_.pop()，考虑有多个元素相同的情况
        if (min_stack_.empty() || number <= min_stack_.top())
        {
            min_stack_.push(number);
        }
    }

    /*
    * @return: An integer
    */
    int pop() {
        // write your code here
        auto result = data_stack_.top();
        data_stack_.pop();
        if (result == min_stack_.top())
        {
            min_stack_.pop();
        }
        
        return result;
    }

    /*
    * @return: An integer
    */
    int min() {
        // write your code here
        return min_stack_.top();
    }

private:
    stack<int> data_stack_;
    stack<int> min_stack_;
};

int main(int argc, char* argv[])
{
    return 0;
}
