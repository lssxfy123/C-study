// Copyright 2017.刘珅珅
// author：刘珅珅
// 更易型算法2
#include "../include/algostuff.hpp"
#include <cstdlib>
using namespace std::placeholders;

int main(int argc, char* argv[])
{
    vector<int> coll1;
    list<int> coll2;

    InsertElements(coll1, 1, 9);
    PrintElements(coll1, "coll1:   ");

    // negate all elements in coll1
    transform(coll1.cbegin(), coll1.cend(),  // source range
                     coll1.begin(),                         // destination range
                     negate<int>());                      // operation
    PrintElements(coll1, "negated:   ");

    transform(coll1.cbegin(), coll1.cend(),  // source range
                     back_inserter(coll2),             // destination range
                     bind(multiplies<int>(), _1, 10));  // operation
    PrintElements(coll2, "coll2:   ");
    cout << endl;

    vector<int> coll3;
    list<int> coll4;
    InsertElements(coll3, 1, 9);
    PrintElements(coll3, "coll3:   ");

    // square each element
    transform(coll3.cbegin(), coll3.cend(),  // first source range
        coll3.cbegin(),  // second source range
        coll3.begin(),  // destination range
        multiplies<int>());  // operation
    PrintElements(coll3, "squared:   ");

    // add each element traversed forward
    //with each element traversed backward
    transform(coll3.cbegin(), coll3.cend(),
        coll3.crbegin(),
        back_inserter(coll4),
        plus<int>());
    PrintElements(coll4, "coll4:  ");
    cout << endl;

    // swap_ranges
    vector<int> coll5;
    deque<int> coll6;
    InsertElements(coll5, 1, 9);
    InsertElements(coll6, 11, 23);
    PrintElements(coll5, "coll5:   ");
    PrintElements(coll6, "coll6:   ");
    cout << endl;
    cout << "after swap:" << endl;

    deque<int>::iterator pos
        = swap_ranges(coll5.begin(), coll5.end(), coll6.begin());
    PrintElements(coll5, "coll5:   ");
    PrintElements(coll6, "coll6:   ");
    cout << endl;

    // fill
    fill_n(ostream_iterator<float>(cout, " "), 10, 7.7);
    cout << endl;
    list<string> coll7;
    fill_n(back_inserter(coll7), 9, "hello");
    PrintElements(coll7, "coll7:   ");

    // overwrite all elements with "again"
    fill(coll7.begin(), coll7.end(), "again");
    PrintElements(coll7, "coll7:   ");

    // replace the second and up to the last
    // element but one with "hmmm"
    list<string>::iterator pos1 = coll7.begin();
    list<string>::iterator pos2 = coll7.end();
    fill(++pos1, --pos2, "hmmm");
    PrintElements(coll7, "coll7:   ");
    cout << endl;

    // generate
    list<int> coll8;
    generate_n(back_inserter(coll8), 5, rand);
    PrintElements(coll8, "coll8:   ");

    // overwrite with five new random numbers
    generate(coll8.begin(), coll8.end(), rand);
    PrintElements(coll8, "coll8:   ");
    cout << endl;

    //iota
    array<int, 10> coll9;
    iota(coll9.begin(), coll9.end(), 42);
    PrintElements(coll9, "coll9:   ");
    return 0;
}
