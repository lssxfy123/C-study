// Copyright 2017.���|�|
// author�����|�|
// C++�еĵ���ģʽ
#include <iostream>
#include "locker.h"
using std::cout;
using std::endl;

class CSingleton
{
  private:
    CSingleton();
    CSingleton(CSingleton&);  // ֻ������ʵ�֣���ֹ����
    CSingleton& operator=(const CSingleton&);  // ֻ������ʵ�֣���ֹ����
    ~CSingleton();

  public:
    static CSingleton& GetInstance();

  public:
    static int count;  // ���������Ƿ�ʵ���˵���
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
    // C++11�в���Ҫ��������������֤��̬�����Ķ��̰߳�ȫ
    locker.lock();
    static CSingleton instance;
    locker.unlock();
    return instance;  // ����һ���ֲ���̬����������
}

int main(int argc, char* argv[])
{
    CSingleton& singleton = CSingleton::GetInstance();
    cout << "count = " << singleton.count << endl;

    CSingleton& singleton_1 = CSingleton::GetInstance();
    cout << "count = " << singleton_1.count << endl;
    return 0;
}
