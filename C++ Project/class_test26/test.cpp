// Copyright 2017.刘珅珅
// author：刘珅珅
// 类类型与转换
#include <iostream>

class SmallInt
{
  public:
    SmallInt(int i = 0): val(i)
    {
    }

    SmallInt(double f) : val(f)
    {

    }

  public:
    operator int() const  // 转换操作符，将SmallInt转换为int型
    {
        return val;
    }

    operator double() const
    {
        return val;
    }

  private:
    std::size_t val;
};

void compute(int i)
{

}

void compute(double f)
{

}

class Integeral
{
  public:
    Integeral(int i = 0)
    {

    }
};

void manip(const Integeral& intergeral)
{

}

void manip(const SmallInt& small_int)
{

}

int main(int argc, char* argv[])
{
    SmallInt si;
    // compute(si);  // error，重载函数调用存在二义性，SmallInt既可以转换为int，也可以转换为double
    compute(static_cast<int>(si));  // ok，强制性消除二义性

    // manip(10);  // 调用重载函数存在二义性，实参10既可以匹配Integeral类型，也可以匹配SmallInt
    manip(SmallInt(10));  // ok，显示调用构造函数消除二义性
    manip(Integeral(10));  // ok
}
