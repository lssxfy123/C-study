// ���ؼ̳к�����̳�

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

class Bed : virtual public Furniture  // ͨ������£����м�������������
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
    // ��SleepSofa�Ĺ��캯���У�������ʾ��ʼ������Furniture
    // ������ֻ��ʼ��SleepSofa��ֱ�ӻ���
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
