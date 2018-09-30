// Copyright 2018.刘珅珅
// author：刘珅珅
// 字符串比较
// B中所有字符都要在A中且每个字符个数<=A中对应字符个数
#include <iostream>
#include <unordered_map>
#include "../../include/print.hpp"
using namespace std;

bool compareStrings(string &A, string &B) {
    // write your code here
    if (B.length() > A.length())
    {
        return false;
    }

    if (B.length() == 0)
    {
        return true;
    }

    unordered_map<char, int> map_B;
    unordered_map<char, int> map_A;
    for (int i = 0; i < B.length(); ++i)
    {
        if (map_B.find(B[i]) != map_B.end())
        {
            map_B[B[i]] = map_B[B[i]] + 1;
        }
        else
        {
            map_B[B[i]] = 1;
        }
    }

    for (int i = 0;i < A.length(); ++i)
    {
        if (map_A.find(A[i]) != map_A.end())
        {
            map_A[A[i]] = map_A[A[i]] + 1;
        }
        else
        {
            map_A[A[i]] = 1;
        }
    }

    if (map_B.size() > map_A.size())
    {
        return false;
    }

    for (auto itor : map_B)
    {
        if (map_A.find(itor.first) == map_A.end() || map_A[itor.first] < map_B[itor.first])
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char* argv[])
{
    string A = "ABC";
    string B = "A";
    compareStrings(A, B);
    return 0;
}
