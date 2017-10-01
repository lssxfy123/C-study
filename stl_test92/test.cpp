// Copyright 2017.刘珅珅
// author：刘珅珅
// mutex和lock
#include <future>
#include <iostream>
#include <mutex>
using namespace std;

mutex print_mutex;

void Print(const string& s)
{
    // 如果没有mutex锁
    // 输出将混乱
    lock_guard<mutex> locker(print_mutex);
    for (char c : s)
    {
        cout.put(c);
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    auto f1 = async(launch::async, Print, 
        "Hello from a first thread");
    auto f2 = async(launch::async, Print,
        "Hello from a second thread");
    Print("Hello from the main thread");
    return 0;
}
