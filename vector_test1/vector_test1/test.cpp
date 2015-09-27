// Copyright 2015.Áõ«|«|
// author£ºÁõ«|«|
// ×Ô¶¨ÒåvectorÈİÆ÷

#include <iostream>
#include <vector>
using namespace std;

#include "Vector.hpp"

//int a[5];
//
//int func(int index)
//{
//    if ((index < 0) || (index >= 5))
//    {
//        throw range_error("index is not between 0 and 4");
//    }
//    return a[index];
//}

int main(int argc, char* argv[])
{
    //for (int i = 0; i != 5; ++i)
    //{
    //    a[i] = i;
    //}

    //try
    //{
    //    cout << func(5) << endl;
    //}
    //catch (runtime_error& e)
    //{
    //    cout << e.what() << endl;
    //}

    Vector<int> array;
    array.push_back(0);
    array.push_back(1);
    array.push_back(2);

    for (Vector<int>::const_iterator it = array.begin(); it != array.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
