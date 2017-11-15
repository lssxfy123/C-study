// 继承中的构造函数

#include <iostream>
using namespace std;

class animal
{
  public:
    animal(int height,int weight)  // 构造函数
    {
        cout << "animal construct" << endl;
    }

    ~animal()  // 析构函数
    {
        cout << "animal destruct" << endl;
    }

  public:
    void eat()
    {
        cout << "animal eat" << endl;
        //breathe();
    }

    void sleep()
    {
        cout<<"animal sleep"<<endl;
    }

  protected:
    void breathe()
    {
        cout << "animal breathe" <<endl;
    }
};

class fish: public animal
{
  public:
    fish() : animal(400,300)//基类的构造函数带有了参数，需要给基类的构造函数传参
    {
        cout << "fish construct" << endl;
        breathe();
    }

    ~fish()
    {
        cout << "fish destruct" << endl;
    }
};

int main(int argc, char* argv[])
{
    fish fh;
    return 0;
}
