// Copyright 2017.刘珅珅
// author：刘珅珅
// 迭代器适配器：串流适配器
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> coll;

    cout << "输入：" << endl;
    // 串流输入迭代器istream_iterator
    // 第1个istream_iterator产生从“标准输入串流cin”
    // 读取数据的iterator, 通过>>读取int型数据, cin >> int
    // 第2个istream_iterator产生一个串流结束符，同cin读取
    // 结束操作类似
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(coll));

    sort(coll.begin(), coll.end());

    cout << "输出：" << endl;
    // 串流输出迭代器ostream_iterator
    // unique_copy消除毗邻的重复值并复制到cout
    // "\n"为元素间的分隔符
    unique_copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, "\n"));
    return 0; 
}
