// Copyright 2017.���|�|
// author�����|�|
// auto��decltype������
#include <iostream>
#include <vector>
using namespace std;

// error��auto����Ϊ�����β�
//void func(auto a = 1) {}

// �������ηǾ�̬������Ա
struct MyStruct 
{
    //auto var = 1;  // error
    //const auto var3 = 3;  // error
    //static auto var4 = 4;  // error
    const static auto var2 = 2;  // ok
};

class A
{
public:
    static int Get()
    {
        return 0;
    }
};

class B
{
public:
    static string Get()
    {
        return "abc";
    }
};

template<class T>
void Func()
{
    // �˴��޷���ȡ��Get�ķ������ͣ�ʹ��auto
    auto val = T::Get();
}

// �������ͺ���
// auto��Ϊ����ֵ
// ͨ��decltype(t + u)�Ƶ�����ֵ������
template<typename T, typename U>
auto Add(T t, U u) -> decltype(t + u)
{
    return t + u;
}

int main(int argc, char* argv[])
{
    // auto
    auto x = 5;  // x��int��
    auto p = new auto(1);  // p��int*����
    const auto v = &x;  // v��int * const������ָ��
    const auto *v1 = &x;  // v1��const int*��ָ������ָ��
    v1 = nullptr;

    int m = 9;
    int& c = m;
    auto d = c;  // dΪint������������
    auto& h = c;  // hΪint&

    const int n = 8;
    auto e = n;  // eΪint��������const
    const auto f = n;  // fΪconst int

    const int& k = 6;
    auto& j = k;  // jΪconst int&
    auto* l = &k;  // lΪconst int*

    //auto r[10] = { 0 };  // error�� ���ܶ�������
    //vector<auto> vec = { 0 };  // error�� �����Ƶ�ģ�����
    Func<A>();
    Func<B>();

    // decltype
    // ����Ҫ��ʼ��
    int x1;
    decltype(x1) y1;  // y1Ϊint����

    int t = 1;
    float u = 2.0f;
    auto sum = Add(t, u);
    return 0;
}
