// Copyright 2017.刘珅珅
// author：刘珅珅
// 辅助函数：min, max, minmax
#include <algorithm>
#include <iostream>
using namespace std;

// 通过指向的值比较两个指针大小
bool int_ptr_less(int* a, int* b)
{
    return *a < *b;
}

int main(int argc, char* argv[])
{
    int x = 17;
    int y = 42;
    int z = 33;
    int tmp = 99;
    int* ptr_x = &x;
    cout << "pointer x " << ptr_x << endl;
    int* ptr_y = &y;
    cout << "pointer y " << ptr_y << endl;
    int* ptr_z = &z;
    cout << "pointer z " << ptr_z << endl;

    // 两个实参的max,min,minmax返回的是引用
    // 在本例中返回的是指针的引用，而且是const引用
    // ptr_max引用的是ptr_y，当修改了ptr_y的指向后
    // ptr_max的指向也随之修改
    int* const& ptr_max = std::max(ptr_x, ptr_y, int_ptr_less);
    cout << "pointer max " << ptr_max << endl;
    ptr_y = &tmp;
    cout << "pointer y " << ptr_y << endl;
    cout << "pointer max " << ptr_max << endl;

    // 实参为初值列表版本返回的是比较值的拷贝
    int* ptr_min = std::min({ ptr_x, ptr_y }, int_ptr_less);

    pair<int*, int*> extremes = minmax({ ptr_x, ptr_y, ptr_z }, int_ptr_less);
    // first为最小值
    cout << "pointer min " << extremes.first << endl;
    // second为最大值
    cout << "pointer max " << extremes.second << endl;

    int i = 0;
    long k = 9;
    // std::max(i, k);  // error，实参类型不一致
    std::max<long>(i, k);  // ok，声明template实参类型，确定返回类型
    return 0;
}
