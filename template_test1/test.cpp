// Copyright 2015.Áõ«|«|
// author£ºÁõ«|«|
// º¯ÊıÄ£°åµÄ²âÊÔ

#include <iostream>
#include <vector>
using namespace std;


template<class T>
const T& FindMax(const vector<T>& array)
{
    int max_index = 0;
    for (int i = 0; i != array.size(); ++i)
    {
        if (array[max_index] < array[i])
        {
            max_index = i;
        }
    }

    return array[max_index];
}

int main(int argc, char* argv[])
{
    vector<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);

    cout << FindMax(array) << endl;
    return 0;
}
