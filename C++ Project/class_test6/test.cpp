// const static ���Ա����

#include <iostream>

class Account
{
  public:
    const static int number = 30;  // �������ඨ�����г�ʼ��
    double array[number];
};

class Bar
{
  public:
    Bar(int number = i)  // ��̬������Ϊ�βε�Ĭ��ֵ
    {

    }

  private:
    static int i;
    static Bar bar1;  // ok������Bar����ʱ���������⣬��Ϊ��̬������ռ��ʵ�����ڴ�
        
    // Bar bar2;  // error��ʹ�����ڶ����Bar���ͣ��ڴ���Bar����ʱ���������캯��������ݹ�
};

int Bar::i = 9;
Bar Bar::bar1;

int main(int argc, char* argv[])
{
    Account a;
    std::cout << Account::number << std::endl;

    Bar bar1;
    return 0;
}
