// Copyright 2017.���|�|
// author�����|�|
// ɾ���ַ���ͷ����β���ո�
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

// ɾ��β���ո�
void EndTrim(char* str)
{
    int n = strlen(str) - 1;

    while (*(str + n) == ' ')
    {
        *(str + n) = '\0';
        --n;
    }
}

// ɾ��ͷ���ո�
void HeadTrim(char* str)
{
    _strrev(str);
    EndTrim(str);
    _strrev(str);
}
