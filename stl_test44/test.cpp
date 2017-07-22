// Copyright 2017.���|�|
// author�����|�|
// ������vector
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include "../include/print.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2;
    v2.assign(v1.begin(), v1.end());
    PrintElements(v2, "assign:    ");

    // ʹ��[],front(), back(), at����vector
    // ��Ҫ�Ƚ����ж�ȷ��������Ч
    if (v2.size() > 5)
    {
        v2[5] = 3;
        v2.at(5) = 4;
    }

    if (!v2.empty())
    {
        cout << "front " << v2.front() << endl;
    }

    v2.push_back(3);
    v2.push_back(3);
    PrintElements(v2, "Add:    ");

    // ɾ��ֵΪ3��Ԫ��
    v2.erase(remove_if(v2.begin(), v2.end(), 
        bind(equal_to<int>(), std::placeholders::_1, 3)), v2.end());
    PrintElements(v2, "Delete:    ");

    // vector����C-style����
    vector<char> v3;
    v3.resize(41);
    strcpy(v3.data(), "hello, world");
    cout << v3.data() << endl;

    vector<string> sentence;
    sentence.reserve(5);
    sentence.push_back("Hello, ");
    sentence.insert(sentence.end(), {"how", "are", "you", "?"});
    cout << "original: " << endl;
    for (const auto& elem : sentence)
    {
        cout << elem.c_str() << " ";
    }
    cout << endl;
    if (sentence.size() > 3)
    {
        (sentence[1], sentence[3]);
    }
    sentence.insert(find(sentence.begin(), sentence.end(), "?"), "always");
    sentence.back() = "!";

    cout << "modify: " << endl;
    for (const auto& elem : sentence)
    {
        cout << elem.c_str() << " ";
    }
    cout << endl;

    return 0;
}
