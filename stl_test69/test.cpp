// Copyright 2017.刘珅珅
// author：刘珅珅
// 非更易型算法5
#include "../include/algostuff.hpp"

int main(int argc, char* argv[])
{
    // is_sorted, is_sorted_until
    vector<int> coll1 = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    PrintElements(coll1, "coll1:   ");
    if (is_sorted(coll1.begin(), coll1.end()))
    {
        cout << "coll1 is sorted" << endl;
    }
    else
    {
        cout << "coll1 is not sorted" << endl;
    }

    map<int, string> coll2 = { {1, "Bill"}, {2, "Jim"}, {3, "Nico"}, {4, "Liu"}, {5, "Ai"} };
    PrintMappedElements(coll2, "coll2:   ");

    auto CompareName = [](const pair<int, string>& e1,
        const pair<int, string>& e2) {
        return e1.second < e2.second;
    };

    if (is_sorted(coll2.cbegin(), coll2.cend(), CompareName))
    {
        cout << "names in coll2 are sorted" << endl;
    }
    else
    {
        cout << "names in coll2 are not sorted" << endl;
    }

    auto pos = is_sorted_until(coll2.cbegin(), coll2.cend(), CompareName);
    if (pos != coll2.end())
    {
        cout << "first unsorted name:  " << pos->second << endl;
    }
    cout << endl;

    // is_partitioned, partition_point
    vector<int> coll3 = {5, 3, 9, 1, 3, 4, 8};
    PrintElements(coll3, "coll3:   ");
    auto IsOdd = [](int elem) {
        return elem % 2 == 1;
    };

    if (is_partitioned(coll3.cbegin(), coll3.cend(), IsOdd))
    {
        cout << "coll3 is partitioned" << endl;

        // find first even element
        auto pos1 = partition_point(coll3.cbegin(), coll3.cend(), IsOdd);
        cout << "first even element: " << *pos1 << endl;
    }
    else
    {
        cout << "coll3 is not partitioned" << endl;
    }
    cout << endl;

    vector<int> coll4 = {6, 4, 5, 3, 9, 1, 4, 8 };
    PrintElements(coll4, "coll4:   ");
    auto IsEven = [](int elem) {
        return elem % 2 == 0;
    };

    if (is_partitioned(coll4.cbegin(), coll4.cend(), IsEven))
    {
        cout << "coll4 is partitioned" << endl;
    }
    else
    {
        cout << "coll4 is not partitioned" << endl;
    }

    // 区间不为分割的情况下，返回第1个分割点的位置
    auto pos2 = partition_point(coll4.cbegin(), coll4.cend(), IsEven);
    cout << "first partitioned element: " << *pos2 << endl;
    cout << endl;

    // is_heap, is_heap_until
    vector<int> coll5 = {9, 8, 7, 7, 7, 5, 4, 2, 1};
    vector<int> coll6 = {5, 3, 2, 1, 4, 7, 9, 8, 6};
    PrintElements(coll5, "coll5:   ");
    PrintElements(coll6, "coll6:   ");
    cout << boolalpha << "coll5 is heap: "
        << is_heap(coll5.cbegin(), coll5.cend()) << endl;
    cout << boolalpha << "coll6 is heap: "
        << is_heap(coll6.cbegin(), coll6.cend()) << endl;
    auto pos3 = is_heap_until(coll6.cbegin(), coll6.cend());
    if (pos3 != coll6.end())
    {
        cout << "first non-heap element: " << *pos3 << endl;
    }
    return 0;
}
