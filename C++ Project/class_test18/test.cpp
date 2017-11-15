// 友元与继承

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
          // return d.count;  // error，无法访问Derive类自有的private成员
          return d.number;  // ok，可以访问Derive类继承自基类Base的private成员
      }
};

class Derive1 : public Frnd
{
  public:
    int mem(Base b)
    {
        // 即使基类Frnd是Base类的友元，但其派生类Derive1也无法访问Base类的private成员
        // return b.number;  // error无法访问Base类的private成员
        return 0;
    }
};

class Frnd1
{
  public:
    int mem(Base b)
    {
        // return b.number;  // error，派生类的友元Frnd1无法访问基类Base的private成员
        return 0;
    }

    int mem(Derive d)
    {
        return d.count;  // ok，派生类Derive的友元Frnd1可以访问Derive类自有的private成员
        // return d.number;  // error，派生类Derive的友元Frnd1无法访问Derive类继承自基类Base的private成员
    }
};

int main(int argc, char* argv[])
{
    return 0;
}
