// ������̳е��µĶ�����
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
    // ���Կ���������������Furniture�Ĺ��캯��
    SleepSofa ss;
    // ss.SetWeight(20);  // error���Ժ���SetWeight�ķ��ʲ���ȷ
    return 0;
}

