// C++中的单例模式

#include <iostream>
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

};

int CSingleton::count = 0;

CSingleton::CSingleton()
{
    ++count;
}

CSingleton::~CSingleton()
{
}

CSingleton& CSingleton::GetInstance()
{
    static CSingleton instance;
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
