// Copyright 2018.刘珅珅
// author：刘珅珅
// 字符串比较
// B中所有字符都要在A中且每个字符个数<=A中对应字符个数
#include <iostream>
#include <map>
#include "../../include/print.hpp"
using namespace std;

bool compareStrings(string &A, string &B) {
    // write your code here
    if (B.length() > A.length())
    {
        return false;
    }
    map<char, int> map_B;
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
    return false;
}

int main(int argc, char* argv[])
{
    string A = "ABCD";
    string B = "AABC";
    compareStrings(A, B);
    return 0;
}
