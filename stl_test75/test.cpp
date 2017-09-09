// Copyright 2017.Áõ«|«|
// author£ºÁõ«|«|
// ±äÐòÐÍËã·¨
#include "../include/algostuff.hpp"

int main(int argc, char* argv[])
{
    // reverse
    vector<int> coll;
    InsertElements(coll, 1, 9);
    PrintElements(coll, "original coll:   ");

    reverse(coll.begin(), coll.end());
    PrintElements(coll, "reverse coll:   ");

    reverse(coll.begin() + 1, coll.end() - 1);
    PrintElements(coll, "coll:   ");

    reverse_copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << endl;

    // rotate
    vector<int> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    PrintElements(coll1, "coll1:   ");

    // rotate one element to the left
    rotate(coll1.begin(), next(coll1.begin()), coll1.end());
    PrintElements(coll1, "one left:   ");

    //rotate two elements to the right
    vector<int>::iterator pos = coll1.end();
    advance(pos, -2);
    rotate(coll1.begin(), pos, coll1.end());
    PrintElements(coll1, "two right:   ");
    cout << endl;

    // next_permutation, prev_permutation
    vector<int> coll2 = {1, 2, 3};
    PrintElements(coll2, "on entry:   ");

    // permute elements until they ar sorted
    while (next_permutation(coll2.begin(), coll2.end()))
    {
        PrintElements(coll2, "  ");
    }
    PrintElements(coll2, "afterward:   ");

    prev_permutation(coll2.begin(), coll2.end());
    PrintElements(coll2, "now:   ");

    // permute elements until they are 
    // sorted in descending order
    while (prev_permutation(coll2.begin(), coll2.end()))
    {
        PrintElements(coll2, "  ");
    }
    PrintElements(coll2, "afterward:   ");
    cout << endl;

    // partition_copy
    vector<int> coll3 = {1, 6, 33, 7, 22, 4, 11, 33, 2, 7, 0, 42, 5};
    PrintElements(coll3, "coll3:   ");

    // destination collections
    vector<int> evenColl;
    vector<int> oddColl;

    // copy all elements partitioned accordingly
    // into even and odd elements
    partition_copy(coll3.cbegin(), coll3.cend(),  // source range
                             back_inserter(evenColl),  // destination for even elements
                             back_inserter(oddColl),  // destination for odd elements
                             [](int elem)  // predicate: check for even elements
                            {
                                return elem % 2 == 0;
                            });
    PrintElements(evenColl, "even coll:    ");
    PrintElements(oddColl, "odd coll:   ");
    return 0;
}
