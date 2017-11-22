// Copyright 2017.���|�|
// author�����|�|
// ��ĸ�ֵ���������
#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        number_ = 1;
        cout << "Base�Ĺ��캯��" << endl;
    }

    Base(const Base& b)
    {
        number_ = b.number_;
        cout << "Base�Ŀ������캯��" << endl;
    }

    //Base& operator=(const Base& rhs)
    //{
    //    cout << "Base�ĸ�ֵ���������" << endl;
    //    return *this;
    //}

    void Print()
    {
        cout << "number = " << number_ << endl;
    }

    Base& SetNumber(int n)
    {
        number_ = n;
        return *this;
    }

private:
    int number_;
};

//class Derive : public Base
//{
//public:
//    Derive()
//    {
//        cout << "Derive�Ĺ��캯��" << endl;
//    }
//
//    Derive(const Derive& d) : Base(d)  // ������Ŀ������캯��Ӧ����ʽ���û���Ŀ������캯������ʼ�����ಿ��
//    {
//        cout << "Derive�Ŀ������캯��" << endl;
//    }
//
//    // ��������û���Ŀ������캯����Ҳ���ᱨ���ڿ�������ʱ��
//    // ����û���Ĺ��캯��ȥ����������Ļ��ಿ�֣�����һ������ȫ�Ŀ�����
//    // ����������Ļ��ಿ�ֲ��ᱻ��������
//    //Derive(const Derive& d)
//    //{
//    //    cout << "Derive�Ŀ������캯��" << endl;
//    //}
//
//    Derive& operator=(const Derive& rhs)
//    {
//        if (this != &rhs)  // ��ֹ����ֵ
//        {
//            Base::operator=(rhs);  // ���û���ĸ�ֵ�������ʼ�����ಿ��
//        }
//
//        cout << "Derive�ĸ�ֵ���������" << endl;
//        return *this;
//    }
//};

int main(int argc, char* argv[])
{
    Base b;
    b.SetNumber(10);
    Base b1;
    b1.SetNumber(20);

    b1 = b;
    b1.Print();
    return 0;
}
