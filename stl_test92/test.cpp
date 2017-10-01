// Copyright 2017.���|�|
// author�����|�|
// mutex��lock
#include <future>
#include <iostream>
#include <mutex>
using namespace std;

mutex print_mutex;

void Print(const string& s)
{
    // ���û��mutex��
    // ���������
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
