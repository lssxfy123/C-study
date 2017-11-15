// 非虚拟继承导致的二义性
#include <iostream>
using namespace std;

class Furniture
{
public:
    Furniture()
    {
        cout << "Furniture()" << endl;
    }

    void SetWeight(int i)
    {
        weight_ = i;
    }

    int GetWeight()
    {
        return weight_;
    }

  protected:
    int weight_;
};

class Bed : public Furniture
{
  public:
    Bed()
    {
        cout << "Bed()" << endl;
    }

    void Sleep()
    {
        cout << "Sleeping...\n";
    }

  protected:
    int height_;
};

class Sofa : public Furniture
{
  public:
    Sofa()
    {
        cout << "Sofa()" << endl;
    }

    void WatchTV()
    {
        cout << "WatchTV.\n";
    }

  protected:
    int time_;
};

class SleepSofa : public Bed, public Sofa
{
  public:
    SleepSofa()
    {
    }

    void FoldOut()
    {
        cout << "fold out the sofa.\n";
    }
};


int main(int argc, char* argv[])
{
    // 可以看出，调用了两次Furniture的构造函数
    SleepSofa ss;
    // ss.SetWeight(20);  // error，对函数SetWeight的访问不明确
    return 0;
}

