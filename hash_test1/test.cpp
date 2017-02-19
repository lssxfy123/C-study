// Copyright 2016.刘珅珅
// author：刘珅珅
// 分离链表法-hash表

#include <iostream>
using namespace std;

#include "hashtable.hpp"

int main(int argc, char* argv[])
{
    HashTable<int> hash_table;
    hash_table.Insert(4371);
    hash_table.Insert(1323);
    hash_table.Insert(6173);
    hash_table.Insert(4199);
    hash_table.Insert(4344);
    hash_table.Insert(9679);
    hash_table.Insert(1989);

    //hash_table.PrintTable();

    hash_table.Remove(4371);

    HashTable<string> hash_table1;
    hash_table1.Insert("asd");
    hash_table1.Insert("qwe");
    hash_table1.Insert("tyu");

    //hash_table1.PrintTable();

    hash_table1.Remove("asd");
    //hash_table1.PrintTable();
    hash_table1.MakeEmpty();

    HashTable<int> hash_table2;
    hash_table2.Insert(32);
    hash_table2.Insert(75);
    hash_table2.Insert(29);
    hash_table2.Insert(63);
    hash_table2.Insert(48);
    hash_table2.Insert(94);
    hash_table2.Insert(25);
    hash_table2.Insert(36);
    hash_table2.Insert(18);
    hash_table2.Insert(70);
    hash_table2.Insert(49);
    hash_table2.Insert(80);

    //hash_table2.CalculateSuccessAverageSearchLength();
    //hash_table2.CalculateUnSuccessAverageSearchLength();

    HashTable<int> hash_table3(5);
    hash_table3.Insert(4371);
    hash_table3.Insert(1323);
    hash_table3.Insert(6173);
    hash_table3.Insert(4199);
    hash_table3.Insert(4344);
    hash_table3.Insert(9679);
    hash_table3.Insert(1989);
    hash_table3.PrintTable();

    return 0;
}
