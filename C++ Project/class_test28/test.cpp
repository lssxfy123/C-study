// Copyright 2017.刘珅珅
// author：刘珅珅
// 纯虚函数
#include <iostream>
using namespace std;

class Display
{
  public:
    virtual void init() = 0;  // 纯虚函数
    virtual void write() = 0;  // 纯虚函数
};

class Monochrome : public Display
{
  public:
    void init()
    {
        cout << "Monochrome init" << endl;
    }

    void write()
    {
        cout << "Monochrome write" << endl;
    }
};

class ColorAdapter : public Display
{
  public:
    void write()
    {
        cout << "ColorAdapter write" << endl;
    }
};


int main(int argc, char* argv[])
{
    Monochrome mc;
    mc.init();

    // ColorAdapter ca;  // error，ColorAdapter类只是想了基类Display中的一个纯虚函数，其仍然是抽象类
    return 0;
}
