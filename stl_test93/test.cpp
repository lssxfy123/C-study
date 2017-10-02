// Copyright 2017.���|�|
// author�����|�|
// condition variable
#include <condition_variable>
#include <future>
#include <iostream>
#include <mutex>
using namespace std;

bool ready_flag;
mutex ready_mutex;
condition_variable ready_condition_variable;

// �������������߳�
void Thread1()
{
    cout << "<return>" << endl;
    cin.get();

    // ���{}�����޶�lock_guard��������
    {
        lock_guard<mutex> lg(ready_mutex);
        ready_flag = true;
    }  // release lock
    ready_condition_variable.notify_one();
}

// �ȴ�������������߳�
void Thread2()
{
    {
        unique_lock<mutex> ul(ready_mutex);
        ready_condition_variable.wait(ul, [] {return ready_flag; });
    }  // release lock

    cout << "done" << endl;
}

int main(int argc, char* argv[])
{
    auto f1 = async(launch::async, Thread1);
    auto f2 = async(launch::async, Thread2);
    return 0;
}
