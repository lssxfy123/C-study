// Copyright 2017.刘珅珅
// author：刘珅珅
// 删除字符串头部和尾部空格
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

void EndTrim(char* str);
void HeadTrim(char* str);

int main(int argc, char* argv[])
{
    char str[1024] = {0};
    string temp;

    getline(cin, temp);

    if (temp.length() > 1024)
    {
        temp.resize(1024);
    }

    for (int i = 0; i != temp.length(); ++i)
    {
        str[i] = temp[i];
    }

    EndTrim(str);
    HeadTrim(str);

    cout << str << endl;


    return 0;
}

// 删除尾部空格
void EndTrim(char* str)
{
    int n = strlen(str) - 1;

    while (*(str + n) == ' ')
    {
        *(str + n) = '\0';
        --n;
    }
}

// 删除头部空格
void HeadTrim(char* str)
{
    _strrev(str);
    EndTrim(str);
    _strrev(str);
}
