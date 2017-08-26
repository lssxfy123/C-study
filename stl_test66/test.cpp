// Copyright 2017.刘珅珅
// author：刘珅珅
// 非更易型算法2
#include "../include/algostuff.hpp"

bool CheckEven(int elem, bool even)
{
    if (even)
    {
        return elem % 2 == 0;
    }
    else {
        return elem % 2 == 1;
    }
}

int main(int argc, char* argv[])
{
    //查找前n个连续匹配值search_n
    deque<int> coll = {1, 2, 7, 7, 6, 3, 9, 5, 7, 7, 7, 3, 6};
    deque<int>::iterator pos = search_n(coll.begin(), coll.end(), 3, 7);
    if (pos != coll.end())
    {
        cout << "first three consecutive elements with value 7 "
            << "start with " << distance(coll.begin(), pos) + 1
            << ". element" << endl;
    }
    else {
        cout << "no three consecutive elements with value 7 for found" << endl;
    }

    // find four consecutive odd elements
    // 自定义的Lambda必须接收两个参数
    // search_n()接收binary predicate op
    // 而不是unary predicate
    pos = search_n(coll.begin(), coll.end(),
        4,
        0,
        [](int elem, int value) {
        return elem % 2 == 1;
    });

    if (pos != coll.end())
    {
        cout << "first four consecutive odd elements are: ";
        for (int i = 0; i < 4; ++i, ++pos)
        {
            cout << *pos << ' ';
        }
    }
    else
    {
        cout << "no four consecutive odd elements found";
    }
    cout << endl;
    cout << endl;

    // 查找第1个子区间search
    deque<int> coll1;
    list<int> sub_coll;
    InsertElements(coll1, 1, 7);
    InsertElements(coll1, 1, 7);
    InsertElements(sub_coll, 3, 6);

    PrintElements(coll1, "coll1:   ");
    PrintElements(sub_coll, "sub coll:   ");
    // search first occurrence
    deque<int>::iterator pos1 = search(coll1.begin(), coll1.end(),  // range
        sub_coll.begin(), sub_coll.end());  // subrange

    while (pos1 != coll1.end())
    {
        cout << "subcoll found starting with element "
            << distance(coll1.begin(), pos1) + 1
            << endl;
        // search next occurrence of subcoll
        ++pos1;
        pos1 = search(pos1, coll1.end(),
            sub_coll.begin(), sub_coll.end());
    }

    cout << endl;
    vector<int> coll2;
    InsertElements(coll2, 1, 9);
    PrintElements(coll2, "coll2:   ");

    // check for "even odd even"
    bool check_even_args[3] = {true, false, true};
    // CheckEven(*coll2::iterator, check_even_args[i])
    // 返回true才是要查找的元素
    // check_even_args对应的end为check_even_args + 3
    vector<int>::iterator pos2 = search(coll2.begin(), coll2.end(),
        check_even_args, check_even_args + 3, CheckEven);
    while (pos2 != coll2.end())
    {
        cout << "subrange found starting with element "
            << distance(coll2.begin(), pos2) + 1
            << endl;
        ++pos2;
        pos2 = search(pos2, coll2.end(),
            check_even_args, check_even_args + 3,
            CheckEven);
    }

    return 0;
}
