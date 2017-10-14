// Copyright 2017.刘珅珅
// author：刘珅珅
// 阻止拷贝
#include <iostream>
#include "../include/print.hpp"
using namespace std;

class NoCopy
{
public:
    NoCopy() = default;  // 使用合成的默认构造函数
    NoCopy(const NoCopy&) = delete;  // 阻止拷贝
    NoCopy& operator = (const NoCopy&) = delete;  // 阻止赋值
    ~NoCopy() = default;  // 使用合成的析构函数
};

int main(int argc, char* argv[])
{
    return 0;
}
