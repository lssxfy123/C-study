// Copyright 2017.���|�|
// author�����|�|
// ��������ת��
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
    operator int() const  // ת������������SmallIntת��Ϊint��
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
    // compute(si);  // error�����غ������ô��ڶ����ԣ�SmallInt�ȿ���ת��Ϊint��Ҳ����ת��Ϊdouble
    compute(static_cast<int>(si));  // ok��ǿ��������������

    // manip(10);  // �������غ������ڶ����ԣ�ʵ��10�ȿ���ƥ��Integeral���ͣ�Ҳ����ƥ��SmallInt
    manip(SmallInt(10));  // ok����ʾ���ù��캯������������
    manip(Integeral(10));  // ok
}
