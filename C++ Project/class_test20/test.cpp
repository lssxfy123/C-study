// �̳��еĹ��캯��

#include <iostream>
using namespace std;

class animal
{
  public:
    animal(int height,int weight)  // ���캯��
    {
        cout << "animal construct" << endl;
    }

    ~animal()  // ��������
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
    fish() : animal(400,300)//����Ĺ��캯�������˲�������Ҫ������Ĺ��캯������
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
