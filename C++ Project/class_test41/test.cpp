// Copyright 2017.���|�|
// author�����|�|
// ���ض������ռ��Ӱ��
#include <iostream>
using std::cout;
using std::endl;

namespace sgcc
{
    class Base
    {
      public:
        Base()
        {

        }
    };

    void Display(const Base& b)
    {
        cout << "sgcc::Display" << endl;
    }

    void main()
    {
        cout << "sgcc::main()" << endl;
    }
}

class Derive : public sgcc::Base
{
  public:
    Derive()
    {

    }
};

void Display(const Derive& d)
{
    cout << "Display(const Derive& d)" << endl;
}

void Display(const sgcc::Base& b)
{
    cout << "Display(const sgcc::Base& b)" << endl;
}

int main(int argc, char* argv[])
{
    Derive d;
    Display(d);  // ����Display(const Derive& d)

    sgcc::Base b;
    // Display(b);  // error��Display���ò���ȷ��ԭ����ȫ�����������и��������ռ�sgcc��ȫ��ͬ�ĺ���

    sgcc::main();

    return 0;
}
