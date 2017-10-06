// Copyright 2017.���|�|
// author�����|�|
// ��Χfor���
#include <cctype>
#include <iostream>
#include "../include/print.hpp"
using namespace std;

void Func(int(& arr)[5])
{
    // ��������������ò���ʹ��begin��end
    for (auto p = begin(arr); p != end(arr); ++p)
    {
        cout << *p << " ";
    }
}

int main(int argc, char* argv[])
{
    string str{"some string!!!"};
    decltype(str.size()) punct_count = 0;

    // ��Χfor���
    // ͳ�Ʊ�����
    for (auto c : str)
    {
        if (ispunct(c))
        {
            ++punct_count;
        }
    }
    cout << punct_count
        << " punctuation characters in " << str << endl;

    // ��Χfor������޸��ַ�
    // ��������
    for (auto& c : str)
    {
        c = toupper(c);
    }
    cout << "Upper characters " << str << endl;

    // for���ʹ���±��޸��ַ�
    for (decltype(str.size()) index = 0; index != str.size(); ++index)
    {
        str[index] = tolower(str[index]);
    }

    for (decltype(str.size()) index = str.size() - 1; index >= 0 && index < str.size(); --index)
    {
        str[index] = tolower(str[index]);
    }
    cout << "Lower characters " << str << endl;

    // ������ͨ������
    int arr[5] = {1, 2, 3, 4, 5};

    // begin��end�޷��ж�ͨ��new����������
    for (auto p = begin(arr); p != end(arr); ++p)
    {
        cout << *p << " ";
    }
    cout << endl;

    return 0;
}
