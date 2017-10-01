// Copyright 2017.刘珅珅
// author：刘珅珅
// thread
#include <chrono>
#include <exception>
#include <future>
#include <iostream>
#include <random>
#include <thread>
using namespace std;

void DoSomething(int num, char c)
{
    try
    {
        default_random_engine dre(42 * c);
        uniform_int_distribution<int> id(10, 1000);
        for (int i = 0; i < num; ++i)
        {
            this_thread::sleep_for(chrono::milliseconds(id(dre)));
            cout.put(c).flush();
        }
    }
    catch (const exception& e)
    {
        cerr << "Thread-exception (thread "
            << this_thread::get_id() << ") : " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "Thread-exception (thread "
            << this_thread::get_id() << ")" << endl;
    }
}

int main(int argc, char* argv[])
{
    try {
        // 前台线程
        thread t1(DoSomething, 5, '.');
        cout << "- started fg thread " << t1.get_id() << endl;

        // print other characters in other background threads
        // 后台线程
        for (int i = 0; i < 5; ++i)
        {
            thread t(DoSomething, 10, 'a' + i);
            cout << "- detach started bg thread " << t.get_id() << endl;
            t.detach();
        }

        cin.get();
        cout << "- join fg thread " << t1.get_id() << endl;
        t1.join();  // wait for t1 finish
    }
    catch (const exception& e)
    {
        cerr << "exception: " << e.what() << endl;
    }

    cout << endl;
    cout << "main thread end" << endl;
    return 0;
}
