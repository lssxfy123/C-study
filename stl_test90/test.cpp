// Copyright 2017.刘珅珅
// author：刘珅珅
// 多线程
#include <chrono>
#include <exception>
#include <future>
#include <iostream>
#include <random>
#include <thread>
using namespace std;

int DoSomething(char c)
{
    default_random_engine dre(c);
    uniform_int_distribution<int> id(10, 1000);

    // loop to print character after a random period of time
    for (int i = 0; i < 10; ++i)
    {
        this_thread::sleep_for(chrono::milliseconds(id(dre)));
        cout.put(c).flush();
    }

    return c;
}

int Func1()
{
    return DoSomething('.');
}

int Func2()
{
    return DoSomething('+');
}

int main(int argc, char* argv[])
{
    cout << "starting Func1() in background"
        << " and Func2() in foreground:" << endl;

    // start Func1() asynchronously
    // (now or later or never)
    // 尝试将Func1异步启动于
    // 一个分离线程内
    future<int> result1(async(Func1));

    // call Func2() synchronously
    int result2 = Func2();

    // print result(wait for Func1()
    // to finish and add its result to
    // result2
    int result = result1.get() + result2;
    cout << "\nresult of Func1() + Func2(): " << result
        << endl;
    return 0;
}
