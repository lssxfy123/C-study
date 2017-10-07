// Copyright 2017.刘珅珅
// author：刘珅珅
// lambda表达式
#include <iostream>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    int size = 5;
    string str("abcd");

    // 捕获size
    auto l = [size](const string& a) {
        return a.size() > size;
    };
    return 0;
}
