// Copyright 2016.刘珅珅
// author：刘珅珅
// 线性探测法-hash表
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
    //hash_table.PrintTable();

    HashTable<int> hash_table1(16);
    hash_table1.Insert(19);
    hash_table1.Insert(14);
    hash_table1.Insert(23);
    hash_table1.Insert(1);
    hash_table1.Insert(68);
    hash_table1.Insert(20);
    hash_table1.Insert(84);
    hash_table1.Insert(27);
    hash_table1.Insert(55);
    hash_table1.Insert(11);
    hash_table1.Insert(10);
    hash_table1.Insert(79);
    //hash_table1.PrintTable();
    //hash_table1.CalculateSuccessAverageSearchLength();

    HashTable<int> hash_table2(10);
    hash_table2.Insert(4371);
    hash_table2.Insert(1323);
    hash_table2.Insert(6173);
    hash_table2.Insert(4199);
    hash_table2.Insert(4344);
    hash_table2.Insert(9679);
    hash_table2.Insert(1989);
    //hash_table2.PrintTable();

    HashTable<int> hash_table3(10);
    hash_table3.Insert(4371);
    hash_table3.Insert(1323);
    hash_table3.Insert(6173);
    hash_table3.Insert(4199);
    hash_table3.Insert(4344);
    hash_table3.Insert(9679);
    hash_table3.Insert(1989);
    hash_table3.Insert(3259);
    hash_table3.Insert(6744);
    hash_table3.Insert(5879);
    hash_table3.Insert(1094);
    hash_table3.PrintTable();

    return 0;
}

