#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        number_ = 1;
        cout << "Base的构造函数" << endl;
    }

    Base(const Base& b)
    {
        number_ = b.number_;
        cout << "Base的拷贝构造函数" << endl;
    }

    //Base& operator=(const Base& rhs)
    //{
    //    cout << "Base的赋值运算符重载" << endl;
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
//        cout << "Derive的构造函数" << endl;
//    }
//
//    Derive(const Derive& d) : Base(d)  // 派生类的拷贝构造函数应该显式调用基类的拷贝构造函数来初始化基类部分
//    {
//        cout << "Derive的拷贝构造函数" << endl;
//    }
//
//    // 如果不调用基类的拷贝构造函数，也不会报错，在拷贝构造时，
//    // 会调用基类的构造函数去构造派生类的基类部分，这是一个不完全的拷贝，
//    // 被拷贝对象的基类部分不会被拷贝过来
//    //Derive(const Derive& d)
//    //{
//    //    cout << "Derive的拷贝构造函数" << endl;
//    //}
//
//    Derive& operator=(const Derive& rhs)
//    {
//        if (this != &rhs)  // 防止自身赋值
//        {
//            Base::operator=(rhs);  // 调用基类的赋值运算符初始化基类部分
//        }
//
//        cout << "Derive的赋值运算符重载" << endl;
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
