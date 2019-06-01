// Copyright 2019.刘珅珅
// author：刘珅珅
// 模板实现单例模式
#include <iostream>
using namespace std;

class noncopyable {
protected:
    noncopyable() {}
    ~noncopyable() {}

private:
    noncopyable(const noncopyable&);
    const noncopyable& operator=(const noncopyable&);
};

template<typename T>
class Singleton : public noncopyable
{
public:
    static T& GetInstance()
    {
        static T instance;
        return instance;
    }
};


class Test
{
    friend class Singleton<Test>;
private:
    Test()
    {
        ++count_;
    }

    ~Test()
    {}

public:
    void Print()
    {
        cout << "instance count " << count_ << endl;
    }

public:
    static int count_;
};

int Test::count_ = 0;

int main(int argc, char* argv[])
{
    Test& s1 = Singleton<Test>::GetInstance();
    s1.Print();

    Test& s2 = Singleton<Test>::GetInstance();
    s2.Print();
    return 0;
}
