// Copyright 2017.���|�|
// author�����|�|
// ����������
#include <algorithm>
#include <deque>
#include <functional>
#include <iterator>
#include <list>
#include <iostream>
#include <set>
#include "../include/print.hpp"
using namespace std;
using namespace std::placeholders;

int main(int argc, char* argv[])
{
    set<int, greater<int>> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> coll2;
    PrintElements(coll1, "initialized: ");

    // ��coll1����Ԫ�س���10���ݵ�coll2��
    // bind(multiplies<int>(), _1, 10)��һ����������
    // �� �Ͳ�ĺ�������multiplies<int>()��ռλ��_1�ϳ�
    transform(coll1.cbegin(), coll1.cend(),  // source��Դ
        back_inserter(coll2),  // destination��Ŀ��
        bind(multiplies<int>(), _1, 10));  // operation������
    PrintElements(coll2, "transformed: ");

    // �滻coll2��ֵΪ70��Ԫ��Ϊ42
    // bind(equal_to<int>(), _1, 70)��һ���ϳɵĺ�������
    replace_if(coll2.begin(), coll2.end(), 
        bind(equal_to<int>(), _1, 70), 
        42);
    PrintElements(coll2, "replaced:    ");

    // �Ƴ�x>=50 && x<=80
    // bind()���������������ӵ��ж�ʽ
    //logical_and, greater_equal, less_equal����struct�ṹ��
    // ���ṩ��operator()���أ� ���Զ��Ǻ�������
    coll2.erase(remove_if(coll2.begin(), coll2.end(), 
        bind(logical_and<bool>(),
        bind(greater_equal<int>(), _1, 50),
        bind(less_equal<int>(), _1, 80))), 
        coll2.end());
    PrintElements(coll2, "removed:    ");
    return 0;
}
