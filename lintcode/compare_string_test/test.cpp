// Copyright 2018.���|�|
// author�����|�|
// �ַ����Ƚ�
// B�������ַ���Ҫ��A����ÿ���ַ�����<=A�ж�Ӧ�ַ�����
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
