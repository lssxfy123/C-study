// ��Ԫ��̳�

#include <iostream>

class Base
{
    friend class Frnd;

  private:
    int number;
};

class Derive : public Base
{
    friend class Frnd1;

  private:
    int count;
};

class Frnd
{
  public:
      int mem(Base b)
      {
          return b.number; 
      }

      int mem(Derive d)
      {
          // return d.count;  // error���޷�����Derive�����е�private��Ա
          return d.number;  // ok�����Է���Derive��̳��Ի���Base��private��Ա
      }
};

class Derive1 : public Frnd
{
  public:
    int mem(Base b)
    {
        // ��ʹ����Frnd��Base�����Ԫ������������Derive1Ҳ�޷�����Base���private��Ա
        // return b.number;  // error�޷�����Base���private��Ա
        return 0;
    }
};

class Frnd1
{
  public:
    int mem(Base b)
    {
        // return b.number;  // error�����������ԪFrnd1�޷����ʻ���Base��private��Ա
        return 0;
    }

    int mem(Derive d)
    {
        return d.count;  // ok��������Derive����ԪFrnd1���Է���Derive�����е�private��Ա
        // return d.number;  // error��������Derive����ԪFrnd1�޷�����Derive��̳��Ի���Base��private��Ա
    }
};

int main(int argc, char* argv[])
{
    return 0;
}
