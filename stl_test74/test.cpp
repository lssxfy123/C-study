// Copyright 2017.刘珅珅
// author：刘珅珅
// 移除重复元素
#include "../include/algostuff.hpp"
using namespace std::placeholders;

int main(int argc, char* argv[])
{
    // unique
    int source[] = {1, 4, 4, 6, 1, 2, 2, 3, 1, 6, 6, 6, 5, 7, 5, 4, 4};
    list<int> coll;

    copy(begin(source), end(source), back_inserter(coll));
    PrintElements(coll, "original coll:   ");
    
    auto pos = unique(coll.begin(), coll.end());

    // 使用unique后，应该
    // 使用新的逻辑终点
    // 因为unique不会改变
    // 元素个数
    //PrintElements(coll, "after unique:   ");
    cout << "after unique" << endl;
    copy(coll.begin(), pos, ostream_iterator<int>(cout, " "));
    cout << "\n\n";

    copy(begin(source), end(source), coll.begin());
    PrintElements(coll, "original coll:   ");
    // 删除所有比重复元素小的元素
    coll.erase(unique(coll.begin(), coll.end(), greater<int>()), coll.end());
    PrintElements(coll, "after unique:   ");
    return 0;
}
