// Copyright 2018.Áõ«|«|
// author£ºÁõ«|«|
// ºÏ²¢¼ä¸ô
#include <iostream>
#include <vector>
#include <algorithm>
#include "../../include/print.hpp"
using namespace std;

class Interval
{
public:
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }

public:
    int start, end;
};

vector<Interval> merge(vector<Interval> &intervals) {
    // write your code here
    vector<Interval> result;
    if (intervals.size() <= 1)
    {
        result = intervals;
        return result;
    }

    auto Compare = [](Interval i1, Interval i2) {
        return i1.start < i2.start;
    };

    sort(intervals.begin(), intervals.end(), Compare);

    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i)
    {
        if (result.back().end >= intervals[i].start)
        {
            if (result.back().end < intervals[i].end)
            {
                result.back().end = intervals[i].end;
            }
        }
        else
        {
            result.push_back(intervals[i]);
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    Interval i1(1, 3);
    Interval i2(2, 6);
    Interval i3(8, 10);
    Interval i4(15, 19);
    vector<Interval> vec;
    vec.push_back(i1);
    vec.push_back(i4);
    vec.push_back(i3);
    vec.push_back(i2);
    merge(vec);
    return 0;
}
