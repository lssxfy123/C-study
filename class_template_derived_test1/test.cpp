// Copyright 2016.刘珅珅
// author：刘珅珅
// 类模板的继承
#include <iostream>
using namespace std;

template<class CountedType>
class ObjectCounter {
public:
    static size_t LiveCount()
    {
        return count;
    }

protected:
    ObjectCounter()
    {
        ++count;
    }

    ObjectCounter(CountedType const &)
    {
        ++count;
    }

    ~ObjectCounter() {
        --count;
    }

private:
    static size_t count;
};

template<class CountedType>
size_t ObjectCounter<CountedType>::count = 0;

// 递归模板继承：将派生类本身作为模板参数传递给基类
class MyClass : public ObjectCounter<MyClass>
{

};

int main(int argc, char* argv[])
{
    MyClass m1;
    cout << "The count of MyClass is " << MyClass::LiveCount() << endl;  // 1

    {
        MyClass m2;
        cout << "The count of MyClass is " << MyClass::LiveCount() << endl;  // 2
    }

    // m2已结析构掉
    cout << "The count of MyClass is " << MyClass::LiveCount() << endl;  // 1
    return 0;
}