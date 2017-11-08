// Copyright 2017.刘珅珅
// author：刘珅珅
// reverse_iterator的插入和删除
#include <iostream>
#include <vector>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int>::reverse_iterator r_iter = find(v.rbegin(), v.rend(), 3);

    // 反向迭代器的插入
    // 容器的insert()不接受reverse_iterator，
    // 所以需要通过base()转换。
    // insert()会把元素插入到迭代器指向的元素的前面
    // 在反向遍历时，99会出现在3的前面，正向遍历时
    // 它出现在4的前面，即：插入时，r_iter与r_iter.base()等价
    v.insert(r_iter.base(), 99);
    PrintElements(v, "Insert by reverse_iterator: ");
    cout << endl;

    // 反向迭代器的删除
    // erase()同样不接受reverse_iterator
    // 删除时r_iter指向的元素时，r_iter与r_iter.base()不再等价
    // r_iter与(++r_iter).base()等价
    r_iter = find(v.rbegin(), v.rend(), 3);  // 之前的r_iter因为插入操作失效
    v.erase((++r_iter).base());
    PrintElements(v, "Erase by reverse_iterator: ");
    return 0;
}
