// Copyright 2016.���|�|
// author�����|�|
// ��������-hash��

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

    hash_table.PrintTable();

    return 0;
}
