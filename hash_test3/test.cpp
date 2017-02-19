// Copyright 2017.刘珅珅
// author：刘珅珅
// 平方探测法-hash表
#include <iostream>
using namespace std;

#include "hashtable.hpp"

int main(int argc, char* argv[])
{
    HashTable<int> hash_table(10);
    hash_table.Insert(89);
    hash_table.Insert(18);
    hash_table.Insert(49);
    hash_table.Insert(58);
    hash_table.Insert(69);
    hash_table.PrintTable();

    HashTable<int> hash_table1(10);
    hash_table1.Insert(4371);
    hash_table1.Insert(1323);
    hash_table1.Insert(6173);
    hash_table1.Insert(4199);
    hash_table1.Insert(4344);
    hash_table1.Insert(9679);
    hash_table1.Insert(1989);
    hash_table1.PrintTable();
    return 0;
}

