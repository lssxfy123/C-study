// Copyright 2017.刘珅珅
// author：刘珅珅
// 重载对命名空间的影响
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
    Display(d);  // 调用Display(const Derive& d)

    sgcc::Base b;
    // Display(b);  // error，Display调用不明确，原因是全局作用域中有个与命名空间sgcc完全相同的函数

    sgcc::main();

    return 0;
}
