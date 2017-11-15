// C++�еĵ���ģʽ

#include <iostream>
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
