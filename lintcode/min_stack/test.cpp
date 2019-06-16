// Copyright 2019.���|�|
// author�����|�|
// ������Сֵ������ջ
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
            // ������֮���С��Ԫ��ѹ��min_stack_��
            // ����min_stack_�����ж����ֵͬ��data_stack_
            // ��min_stack_�ĳ�������ͬ�ġ�������
            // ��ԭ������pop()ʱ��data_stack_��min_stack_ͬʱpop()
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

        // ֻ��С�ڵ���min_stack_.top()��Ԫ��ѹ��ջ
        // ע��һ��Ҫ���ǵ��ڵ��������Ϊ��pop()ʱ
        // data_stack_.top()����min_stack_.top()ʱ��
        // �Ż��min_stack_.pop()�������ж��Ԫ����ͬ�����
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
