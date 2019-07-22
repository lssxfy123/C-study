// Copyright 2019.Áõ«|«|
// author£ºÁõ«|«|
// »áÒéÊÒ
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../include/print.hpp"
using namespace std;

struct Interval{
int start, end;
Interval(int start, int end) {
this->start = start;
this->end = end;

     }
};


bool canAttendMeetings(vector<Interval> &intervals) {
    // Write your code here
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b)->bool
    {
        return a.start < b.start;
    });

    for (int i = 1; i < intervals.size(); ++i)
    {
        if (intervals[i].start < intervals[i - 1].end)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    return 0;
}
