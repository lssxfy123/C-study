// 多重继承和虚拟继承

#include <iostream>
using namespace std;

class Furniture
{
  public:
    Furniture(int w)
    {
        weight_ = w;
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

class Bed : virtual public Furniture  // 通常情况下，将中间基类进行虚派生
{
  public:
    Bed(int h) : Furniture(20)
    {
        height_ = h;
        cout << "Bed()" << endl;
    }

    void sleep()
    {
        cout << "Sleeping...\n";
    }

  protected:
    int height_;
};

class Sofa : virtual public Furniture
{
  public:
    Sofa(int t) : Furniture(30)
    {
        time_ = t;
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
    // 在SleepSofa的构造函数中，必须显示初始化基类Furniture
    // 而不能只初始化SleepSofa的直接基类
    SleepSofa() : Bed(50), Sofa(60), Furniture(80)
    {
        cout << "SleepSofa() " << "weight = " << weight_ << endl;
        cout << "height = " << height_ << endl;
        cout << "time = " << time_ << endl;
    }

    void FoldOut()
    {
        cout << "fold out the sofa.\n";
    }
};


int main(int argc, char* argv[])
{
    SleepSofa ss;
    ss.SetWeight(20);
    return 0;
}
