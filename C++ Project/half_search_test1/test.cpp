// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// ÕÛ°ë²éÕÒ
#include <iostream>
using std::endl;
using std::cout;

// ÕÛ°ë²éÕÒ:ÓĞĞòĞòÁĞ
int halfSearch(int* a, int begin, int end, const int key);

int main(int argc, char* argv[])
{
    return 0;
}

int halfSearch(int* a, int begin, int end, const int key)
{
    int middle = (begin + end) / 2;

    if (a[middle] > key)
    {
        halfSearch(a, begin, middle - 1, key);
    } else if (a[middle] < key)
    {
        a = a + middle;
        halfSearch(a, middle + 1, end, key);
    }

    return middle;
}
