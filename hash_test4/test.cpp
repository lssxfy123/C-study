// Copyright 2017.刘珅珅
// author：刘珅珅
// hash表处理大量数据
// 大量查询字符串，查找前10个热门查询
// 参考：http://kb.cnblogs.com/page/189480/
#include <iostream>
using namespace std;

#include "hashtable.hpp"

int main(int argc, char* argv[])
{
    CreateCryTable();
    HashTable<string> hash_table(101);
    hash_table.Insert("abcd");
    hash_table.Insert("efgh");
    hash_table.Insert("abct");
    hash_table.Insert("efge");
    hash_table.Insert("ayui");
    hash_table.Insert("efop");
    hash_table.Insert("wqrt");
    hash_table.Insert("nmkl");
    hash_table.Insert("rtuy");
    hash_table.Insert("nyui");
    hash_table.Insert("abopi");
    hash_table.Insert("efuyt");
    hash_table.Insert("werq");
    hash_table.Insert("efyu");
    hash_table.Insert("uict");
    hash_table.Insert("efyt");
    hash_table.Insert("ayio");
    hash_table.Insert("efophgf");
    hash_table.Insert("wqrtkl");
    hash_table.Insert("nuimkl");
    hash_table.Insert("rtopuy");
    hash_table.Insert("nbnyui");
    hash_table.Insert("auiycd");
    hash_table.Insert("efgmnbh");
    hash_table.Insert("abcd");
    hash_table.Insert("abcd");
    hash_table.Insert("abcd");
    hash_table.Insert("efgh");
    hash_table.Insert("efgh");
    hash_table.Insert("abct");
    hash_table.PrintTable();
    return 0;
}
