// Copyright 2018.刘珅珅
// author：刘珅珅
// 插入并合并间隔
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

/**
* @param intervals: Sorted interval list.
* @param newInterval: new interval.
* @return: A new interval list.
*/
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    // write your code here
    vector<Interval> result;
    if (intervals.size() == 0)
    {
        result.push_back(newInterval);
        return result;
    }

    // 查找newInterval.start和 newInterval.end所在区间
    int min = intervals[0].start;
    int max = intervals[intervals.size() - 1].end;
    if (newInterval.start < min && newInterval.end > max)
    {
        result.push_back(newInterval);
        return result;
    }
    else if (newInterval.start > max)
    {
        result.assign(intervals.begin(), intervals.end());
        result.push_back(newInterval);
        return result;
    }
    else if (newInterval.end < min)
    {
        result.push_back(newInterval);
        result.insert(result.end(), intervals.begin(), intervals.end());
        return result;
    }

    int endIndex = -1;
    int startIndex = -1;
    for (int i = 0; i < intervals.size(); ++i)
    {
        if (intervals[i].start <= newInterval.start && intervals[i].end >= newInterval.start && startIndex < 0)
        {
            startIndex = i;
        }

        if (i + 1 < intervals.size())
        {
            if (intervals[i].end < newInterval.start && intervals[i + 1].start > newInterval.start && startIndex < 0)
            {
                startIndex = i;
            }
        }

        if (intervals[i].start <= newInterval.end && intervals[i].end >= newInterval.end && endIndex < 0)
        {
            endIndex = i;
        }

        if (i + 1 < intervals.size())
        {
            if (intervals[i].end < newInterval.end && intervals[i + 1].start > newInterval.end && endIndex < 0)
            {
                endIndex = i + 1;
            }
        }
    }

    if (startIndex < 0)
    {
        if (intervals[endIndex].start > newInterval.end)
        {
            result.push_back(newInterval);
        }
        else
        {
            intervals[endIndex].start = newInterval.start;
        }

        for (int i = endIndex; i < intervals.size(); ++i)
        {
            result.push_back(intervals[i]);
        }
        return result;
    }

    if (endIndex < 0)
    {
        for (int i = 0; i <= startIndex; ++i)
        {
            result.push_back(intervals[i]);
        }

        if (intervals[startIndex].end < newInterval.start)
        {
            result.push_back(newInterval);
        }
        else
        {
            result[startIndex].end = newInterval.end;
        }
        return result;
    }

    for (int i = 0; i <= startIndex; ++i)
    {
        result.push_back(intervals[i]);
    }

    if (intervals[startIndex].end < newInterval.start)
    {
        result.push_back(newInterval);
        ++startIndex;
    }
    else
    {
        result[startIndex].end = newInterval.end;
    }

    if (intervals[endIndex].start <= newInterval.end)
    {
        result[startIndex].end = intervals[endIndex].end;
        for (int i = endIndex + 1; i < intervals.size(); ++i)
        {
            result.push_back(intervals[i]);
        }
    }
    else
    {
        for (int i = endIndex; i < intervals.size(); ++i)
        {
            result.push_back(intervals[i]);
        }
    }



    return result;
}

vector<Interval> insert1(vector<Interval> &intervals, Interval newInterval) {
    // write your code here
    vector<Interval> result;
    if (intervals.size() == 0)
    {
        result.push_back(newInterval);
        return result;
    }

    int index = 0;
    for (index = 0; index < intervals.size()
        && intervals[index].start < newInterval.start; ++index)
    {
        result.push_back(intervals[index]);
    }

    if (!result.empty() && result.back().end >= newInterval.start)
    {
        result.back().end = max(result.back().end, newInterval.end);
    }
    else
    {
        result.push_back(newInterval);
    }

    for (int i = index; i < intervals.size(); ++i)
    {
        if (result.back().end >= intervals[i].start)
        {
            result.back().end = max(result.back().end, intervals[i].end);
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
    Interval i1(1, 5);
    Interval i2(5, 9);
    vector<Interval> v1;
    v1.push_back(i1);
    v1.push_back(i2);
    Interval i3(3, 4);
    vector<Interval> result = insert(v1, i3);

    Interval i4(1, 5);
    vector<Interval> v2;
    v2.push_back(i4);
    Interval i5(0, 0);
    result = insert(v2, i5);
    return 0;
}

