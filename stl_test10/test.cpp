// Copyright 2017.���|�|
// author�����|�|
// C++11 Lambda�﷨
#include <iostream>
#include <functional>
using namespace std;

// ����ֵΪLambda���ʽ
function<int(int, int)> ReturnLambda()
{
    return[](int x, int y)
    {
        return x * y;
    };
}

int main(int argc, char* argv[])
{
    // lambda���ʽ
    [] {
        cout << "hello lambda" << endl;
    }();

    auto lambda = [] (const string& str) {
        cout << str.c_str() << endl;
    };
    lambda("test lambda");

    // ���з���ֵ��Lambda
    auto d_return = []() -> double {
        return 42;
    };
    double d = d_return();
    cout << d << endl;  // 42

    // ʹ���ⲿ������δ������Ϊʵ�ε�����
    int x = 0;
    int y = 42;

    // x��ֵ���ݴ��ݸ�lambda���ǿɶ����ݣ������ܸı�
    // y�����ô��ݸ�lambda�����Ըı���
    auto qqq = [x, &y] {
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
        // ++x;  // error�����ܸı�x��ֵ
        ++y;
    };

    x = y = 77;
    qqq();
    qqq();
    cout << "final y: " << y << endl;

    // �ɱ�Lambda�������޸İ�ֵ���ݵ��ⲿ���������
    int id = 0;
    auto lambda_mutable = [id] () mutable {
        cout << "id: " << id << endl;
        ++id;
    };
    id = 42;
    lambda_mutable();
    lambda_mutable();
    cout << "extern id: " << id << endl;

    auto lf = ReturnLambda();
    cout << lf(6, 7) << endl;
    return 0;
}
