// Copyright 2017.刘珅珅
// author：刘珅珅
// atomic
#include <atomic>
#include <chrono>
#include <future>
#include <iostream>
#include <thread>
using namespace std;

long data_;
atomic<bool> ready_flag;

void Provider()
{
    // after reading a character
    cout << "<return>" << endl;
    cin.get();
    data_ = 42;
    // atomic不需要mutex和lock
    ready_flag.store(true);
}

void Consumer()
{
    while (!ready_flag.load())
    {
        cout.put('.').flush();
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    cout << "\nvalue : " << data_ << endl;
}

int main(int argc, char* argv[])
{
    // 初始化atomic变量
    atomic_init(&ready_flag, false);
    auto p = async(launch::async, Provider);
    auto c = async(launch::async, Consumer);
    return 0;
}
