// Copyright 2017.���|�|
// author�����|�|
// ת����������
#include <iostream>

class SmallInt
{
  public:
    SmallInt(int i = 0): val(i)
    {
        if ((i < 0) || (i > 255))
        {
            throw std::out_of_range("Bad SmallInt initializer");  // ������Χ
        }
    }

  public:
    operator int() const  // ת������������SmallIntת��Ϊint�ͣ������з���ֵ���������β�
    {
        return val;
    }

  private:
    std::size_t val;
};

int main(int argc, char* argv[])
{
    SmallInt si = 3;
    double f = si + 3.14;  // ��siת��Ϊint��Ȼ����ת��Ϊdouble

    if (si >= f)
    {
    }

    if (si)
    {
    }
    return 0;
}
