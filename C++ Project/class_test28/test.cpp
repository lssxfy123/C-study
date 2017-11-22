// Copyright 2017.���|�|
// author�����|�|
// ���麯��
#include <iostream>
using namespace std;

class Display
{
  public:
    virtual void init() = 0;  // ���麯��
    virtual void write() = 0;  // ���麯��
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

    // ColorAdapter ca;  // error��ColorAdapter��ֻ�����˻���Display�е�һ�����麯��������Ȼ�ǳ�����
    return 0;
}
