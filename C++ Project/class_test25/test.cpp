// Copyright 2017.刘珅珅
// author：刘珅珅
// 转换与类类型
#include <iostream>

class SmallInt
{
  public:
    SmallInt(int i = 0): val(i)
    {
        if ((i < 0) || (i > 255))
        {
            throw std::out_of_range("Bad SmallInt initializer");  // 超出范围
        }
    }

  public:
    operator int() const  // 转换操作符，将SmallInt转换为int型，不能有返回值，不能有形参
    {
        return val;
    }

  private:
    std::size_t val;
};

int main(int argc, char* argv[])
{
    SmallInt si = 3;
    double f = si + 3.14;  // 将si转换为int，然后再转换为double

    if (si >= f)
    {
    }

    if (si)
    {
    }
    return 0;
}
