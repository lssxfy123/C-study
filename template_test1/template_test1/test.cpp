// Copyright 2015.Áõ«|«|
// author£ºÁõ«|«|
// º¯ÊıÄ£°åµÄ²âÊÔ

#include <iostream>
#include <vector>
using namespace std;


template<class T>
const T& FindMax(const vector<T>& a)
{
    int max_index = 0;
    for (int i = 0; i != a.size(); ++i)
    {
        if (a[max_index] < a[i])
        {
            max_index = i;
        }
    }

    return a[max_index];
}

int main(int argc, char* argv[])
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    cout << FindMax(a) << endl;
    return 0;
}

