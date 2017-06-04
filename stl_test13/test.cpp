// Copyright 2017.���|�|
// author�����|�|
// pair��tuple
#include <iostream>
#include <tuple>
using namespace std;

class Foo {
public:
    Foo(tuple<int, float>)
    {
        cout << "Foo::Foo(tuple)" << endl;
    }

    // �䳤����ģ��
    template<typename... Args>
    Foo(Args... args)
    {
        cout << "Foo::Foo(args...)" << endl;

        // ����䳤����
        write(args...);
    }

private:
    // ��������ģ����Ƶ����ܣ�ÿ��ȡ����һ������t
    // �������Ĳ���������Ϊ�䳤����args
    // ����һ���ݹ�
    template<typename T, typename ...Args>
    void write(const T& t, Args... args)
    {
        cout << t << ",";
        write(args...);
    }

    // �ݹ�ĳ���
    // �䳤���������һ������
    template<typename T>
    void write(const T& t)
    {
        cout << t << endl;
    }
};

int main(int argc, char* argv[])
{
    // pair
    std::pair<int, float> p(42, 3.14f);
    cout << "first: " << p.first << " second: " << p.second << endl;
    cout << "first: " << get<0>(p) << " second: " << get<1>(p) << endl;

    tuple<int, float> t(1, 2.2f);
    tuple<int, string> t1(4, "a");
    pair<int, Foo> p1(42, t);

    // piecewise_construct��Ϊ��һʵ�Σ��ֶι���
    // ��������tuple��45ǿ��ת��Ϊtuple��Ϊp2��firstԪ��
    // p2��secondԪ����һ��Foo������������    template<typename... Args>
    // Foo(Args... args)���캯��������tupleԪ�ض�����tuple����
    pair<int, Foo> p2(piecewise_construct, make_tuple(45), t);

    make_pair(42, "a");
    return 0;
}
