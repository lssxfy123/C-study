// Copyright 2017.刘珅珅
// author：刘珅珅
// condition variable实现多线程Queue
#include <condition_variable>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
using namespace std;

queue<int> queue_;
mutex queue_mutex;
condition_variable queue_condition_variable;

void Provider(int value)
{
    for (int i = 0; i < 6; ++i)
    {
        {
            lock_guard<mutex> lg(queue_mutex);
            queue_.push(value + i);
        }  // release lock
        queue_condition_variable.notify_one();
        //queue_condition_variable.notify_all();
        this_thread::sleep_for(chrono::microseconds(value));
    }
}

void Consumer(int number)
{
    while (true)
    {
        int value;
        {
            unique_lock<mutex> ul(queue_mutex);
            queue_condition_variable.wait(ul, [] {return !queue_.empty(); });
            value = queue_.front();
            queue_.pop();
        }  // release lock
        cout << "consumer " << number << ": " << value << endl;
    }
}

int main(int argc, char* argv[])
{
    // start three providers for values 100+, 300+, and 500+
    auto p1 = async(launch::async, Provider, 100);
    auto p2 = async(launch::async, Provider, 300);
    auto p3 = async(launch::async, Provider, 500);

    // start two consumers printing the values
    auto c1 = async(launch::async, Consumer, 1);
    auto c2 = async(launch::async, Consumer, 2);
    return 0;
}
