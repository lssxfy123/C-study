// Copyright 2017.刘珅珅
// author：刘珅珅
// 非更易型算法1
#include <cstdlib>
#include "../include/algostuff.hpp"
using namespace std::placeholders;
bool AbsLess(int elem1, int elem2)
{
    return abs(elem1) < abs(elem2);
}

int main(int argc, char* argv[])
{
    // 元素计数count
    vector<int> coll;
    InsertElements(coll, 1, 9);
    PrintElements(coll, "coll:   ");
    int number = count(coll.cbegin(), coll.cend(), 4);
    cout << "count():  " << endl;
    cout << "number of elements equal to 4:   " << number << endl;

    number = count_if(coll.cbegin(), coll.cend(), [](int elem) {
        return elem % 2 == 0;
    });
    cout << "number of elements with even value:   " << number << endl;

    number = count_if(coll.cbegin(), coll.cend(), [](int elem) {
        return elem > 4;
    });
    cout << "number of elements greater than 4:   " << number << endl;

    // 最小值和最大值
    deque<int> coll1;
    InsertElements(coll1, 2, 6);
    InsertElements(coll1, -3, 6);
    cout << "min and max:  " << endl;
    PrintElements(coll1, "coll1:   ");

    cout << "minimum:  "
        << *min_element(coll1.cbegin(), coll1.cend()) << endl;
    cout << "maximum:  "
        << *max_element(coll1.cbegin(), coll1.cend()) << endl;

    auto mm = minmax_element(coll1.cbegin(), coll1.cend());
    // 第1个最小元素
    cout << "min:    " << *(mm.first) << endl;
    // 最后一个最大元素
    cout << "max:   " << *(mm.second) << endl;
    cout << "distance between min and max:   " << distance(mm.first, mm.second) << endl;

    cout << "minimun of absolute values:  "
        << *min_element(coll1.cbegin(), coll1.cend(), AbsLess) << endl;
    cout << "maximum of absolute values:   "
        << *max_element(coll1.cbegin(), coll1.cend(), AbsLess) << endl;

    cout << endl;

    // 查找元素find
    cout << "find " << endl;
    list<int> coll2;
    InsertElements(coll2, 1, 9);
    InsertElements(coll2, 1, 9);
    PrintElements(coll2, "coll2:  ");

    //find first element with value 4
    list<int>::iterator pos1 = find(coll2.begin(), coll2.end(), 4);

    //find second element with value 4
    list<int>::iterator pos2;
    if (pos1 != coll2.cend())
    {
        pos2 = find(next(pos1), coll2.end(), 4);
    }

    // print all elements from first to second 4
    if (pos1 != coll2.end() && pos2 != coll2.end())
    {
        copy(pos1, next(pos2), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    cout << endl;
    vector<int> coll3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    PrintElements(coll3, "coll3:  ");

    // find first element greater than 3
    vector<int>::iterator pos = find_if(coll3.begin(), coll3.end(),
        bind(greater<int>(), _1, 3));
    cout << "the "
        << distance(coll3.begin(), pos) + 1
        << ". element is the first greater than 3" << endl;

    // find first element divisible by 3
    pos = find_if(coll3.begin(), coll3.end(), [](int elem) {
        return elem % 3 == 0;
    });
    cout << "the "
        << distance(coll3.begin(), pos) + 1
        << ". element is the first divisible by 3" << endl;

    // find first element not < 5
    pos = find_if_not(coll3.begin(), coll3.end(), bind(less<int>(), _1, 5));
    cout << "first value >= 5:  " << *pos << endl;
    return 0;
}
