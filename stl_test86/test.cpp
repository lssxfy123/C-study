// Copyright 2017.���|�|
// author�����|�|
// ������ʽƥ��ϸ��
#include <iomanip>
#include <iostream>
#include <regex>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    string data = "XML tag: <tag-name>the value </tag-name>.";
    cout << "data:        " << data << endl;
    cout << endl;

    smatch m;  // for returned details of the match
    // regex_search������ƥ��
    bool found = regex_search(data, m,
        regex("<(.*)>(.*)</(\\1)>"));

    // print match details
    cout << "m.empty():    " << boolalpha << m.empty() << endl;
    cout << "m.size():   " << m.size() << endl;

    if (found)
    {
        // ƥ��ϸ�������ַ�
        cout << "m.str():   " << m.str() << endl;

        // ƥ��ϸ�������ַ�����
        cout << "m.length():   " << m.length() << endl;

        // ƥ��ϸ�������ַ���λ��
        cout << "m.position():   " << m.position() << endl;

        // ��1��ƥ��ϸ���ַ�ǰ�������ַ�
        cout << "m.prefix().str():   " << m.prefix().str() << endl;

        // ���һ��ƥ��ϸ���ַ���������ַ�
        cout << "m.suffix().str():   " << m.suffix().str() << endl;
        cout << endl;

        // iterating over all matches(using the match index)
        for (int i = 0; i < m.size(); ++i)
        {
            cout << "m[" << i << "].str():   " << m[i].str() << endl;
            cout << "m.str(" << i << "):   " << m.str(i) << endl;
            cout << "m.position(" << i << "):   " << m.position(i)
                << endl;
        }
        cout << endl;

        // iterating over all matches(using iterators)
        cout << "matches:   " << endl;
        for (auto pos = m.begin(); pos != m.end(); ++pos)
        {
            cout << " " << *pos << " ";
            cout << "(length: " << pos->length() << ")" << endl;
        }
    }
    return 0;
}
