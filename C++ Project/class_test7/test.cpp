// Copyright 2017.���|�|
// author�����|�|
// ��Ԫ
#include <iostream>

class A;  // ǰ����������������

class C
{
  public:
    void SetNumber(A& a);  // �˴�ֻ���к��������������к�����ʵ��

    void output(A& a);
};

class A
{
    friend class B;  // ��B�����г�Ա�������ɷ�����A��private��Ա
    friend void C::output(A& a);  // ��C�ĳ�Ա����output()���Է�����A��private��Ա�������Ա���������ɷ�����A��private��Ա

  private:
    int number;
};

class B
{
  public:
    void SetNumber(A& a)
    {
        a.number = 5;
    }

    void output(A& a)
    {
        std::cout << a.number << std::endl;
    }
};

void C::output(A& a)
{
    std::cout << a.number << std::endl;
}

void C::SetNumber(A& a)
{
    // a.number = 5;  // error���޷�����A��private��Ա
}

int main(int argc, char* argv[])
{
    return 0;
}

