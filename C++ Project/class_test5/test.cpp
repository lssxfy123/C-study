// Copyright 2017.���|�|
// author�����|�|
// ���еľ�̬����
#include <iostream>
using namespace std;

class P
{
  public:
    static void init()
    {
        // ��̬��Ա����ֻ�ܵ��þ�̬��Ա�����;�̬��Ա������ԭ���Ǿ�̬��Ա�����������֮ǰ���Ѿ����ڴ�������
        // ���ʱ��Ǿ�̬��Ա��û�з����ڴ�ռ䣬�Ǿ�̬��Ա���������ʱ���ܷ����ڴ�ռ䡣
        // m = 4;  // error���޷����ʷǾ�̬��Ա����
        cout << "��̬��Ա����" << endl;
    }

    void output()
    {
        init();  // �Ǿ�̬��Ա�������Ե��þ�̬��Ա�����ͳ�Ա����

        x = 1;
        y = 1;
        cout << x << endl;
        cout << y << endl;

        cout <<" �Ǿ�̬��Ա����" << endl;
    }

    static double z;

  private:
    static int x;
    static int y;
    int m;
};

// ���Ҫ���ʾ�̬��Ա����ʱ����̬��Ա����������г�ʼ����
// �������ඨ��֮����У���������ʾ�̬��Ա��������̬��Ա��������Ҫ���г�ʼ��
int P::x = 0;
int P::y = 0;
double P::z = 0.0;

int main(int argc, char* argv[])
{
    P p1;
    p1.init();//�����������ʾ�̬��Ա����
    p1.output();
    P::init();//Ҳ�����������ʾ�̬��Ա����

    P::z = 1.0;//zΪ������̬��Ա������������������

    return 0;
}

