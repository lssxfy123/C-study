// Copyright 2017.刘珅珅
// author：刘珅珅
// 多线程中的文件读写
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "../include/locker.hpp"
using namespace std;

bool flag = false;
Locker locker;

void ReadFileInThread()
{
    string file_name = "11.txt";
    ifstream in;
    in.open(file_name);
    if (!in)
    {
        cout << "read file failed " << file_name << endl;
        return;
    }

    std::stringstream buffer;
    buffer << in.rdbuf();
    string content(buffer.str());
    in.close();

    cout << "read content " << content << endl;
}

void WriteFileInThread()
{
    string file_name = "11.txt";
    ofstream out(file_name.c_str());
    if (out.is_open())
    {
        cout << "save file name " << file_name << endl;;
        out << "abcd" << endl;
        out.close();
    }
    else {
        out.close();
        cout << "save file failed" << endl;
        remove(file_name.c_str());
    }
}

void ReadThread(void* p)
{
    while (!flag)
    {
        locker.lock();
        ReadFileInThread();
        locker.unlock();

        Sleep(10);
    }

    cout << "exit read thread " << endl;
}

void WriteThread(void* p)
{
    while (!flag)
    {
        locker.lock();
        WriteFileInThread();
        locker.unlock();
        Sleep(10);
    }

    cout << "exit write thread " << endl;
}

int main(int argc, char* argv[])
{
    _beginthread(&ReadThread, NULL, NULL);
    _beginthread(&WriteThread, NULL, NULL);

    while (1)
    {
        Sleep(1000);
        flag = true;
    }
    return 0;
}


