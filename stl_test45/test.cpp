// Copyright 2017.���|�|
// author�����|�|
// ������deque
#include <algorithm>
#include <functional>
#include <deque>
#include <iostream>
#include <iterator>
#include "../include/print.hpp"
using namespace std;

// ���vs��<<�޷�ֱ�����string���͵�����
namespace std
{
    ostream& operator <<(ostream& os, const string& src)
    {
        return os << src.c_str() << endl;
    }
}

int main(int argc, char* argv[])
{
    deque<string> coll;
    coll.assign(3, "string");
    coll.push_back("last string");
    coll.push_front("first string");
    cout << "original: " << endl;
    copy(coll.cbegin(), coll.cend(), ostream_iterator<string>(cout, "\n"));
    cout << endl;

    cout << "remove first and last: " << endl;
    coll.pop_front();
    coll.pop_back();

    for (deque<string>::size_type i = 1; i < coll.size(); ++i)
    {
        coll[i] = "another " + coll[i];
    }

    copy(coll.cbegin(), coll.cend(), ostream_iterator<string>(cout, "\n"));
    cout << endl;

    cout << "resize: " << endl;
    // ��ĩ�˲���"resize string"��ɾ��ĩ��Ԫ��
    // ʹsize() = 4
    coll.resize(4, "resize string");
    copy(coll.cbegin(), coll.cend(), ostream_iterator<string>(cout, "\n"));
    return 0;
}
