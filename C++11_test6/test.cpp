// Copyright 2017.���|�|
// author�����|�|
// lambda���ʽ
#include <iostream>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    int size = 5;
    string str("abcd");

    // ����size
    auto l = [size](const string& a) {
        return a.size() > size;
    };
    return 0;
}
