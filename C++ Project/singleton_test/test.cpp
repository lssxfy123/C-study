// Copyright 2017.刘珅珅
// author：刘珅珅
// C++中的单例模式
#include <iostream>
#include "locker.h"
using std::cout;
using std::endl;

class CSingleton
{
  private:
    CSingleton();
    CSingleton(CSingleton&);  // 只声明不实现，防止拷贝
    CSingleton& operator=(const CSingleton&);  // 只声明不实现，防止拷贝
    ~CSingleton();

  public:
    static CSingleton& GetInstance();

  public:
    static int count;  // 用来测试是否实现了单例
    static Locker locker;
};

int CSingleton::count = 0;

CSingleton::CSingleton()
{
    ++count;
}

Locker CSingleton::locker;

CSingleton::~CSingleton()
{
}

CSingleton& CSingleton::GetInstance()
{
    // C++11中不需要加锁，编译器保证静态变量的多线程安全
    locker.lock();
    static CSingleton instance;
    locker.unlock();
    return instance;  // 返回一个局部静态变量给引用
}

int main(int argc, char* argv[])
{
    CSingleton& singleton = CSingleton::GetInstance();
    cout << "count = " << singleton.count << endl;

    CSingleton& singleton_1 = CSingleton::GetInstance();
    cout << "count = " << singleton_1.count << endl;
    return 0;
}
