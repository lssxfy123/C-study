#ifndef CLOCK_H
#define CLOCK_H

#include <chrono>
#include <iostream>
using namespace std;
using namespace chrono;

enum ClockUnit
{
    Second = 0,
    MillSecond = 1,
    MicroSecond = 2
};

class Clock
{
public:
    Clock(ClockUnit unit) : unit_(unit), duration_(0)
    {
        is_start_ = false;
    }

    ~Clock()
    {

    }

    void Start()
    {
        start_ = system_clock::now();
        is_start_ = true;
    }

    void End()
    {
        if (!is_start_)
        {
            return;
        }

        end_ = system_clock::now();
        if (unit_ == Second)
        {
            duration_ = (double)duration_cast<microseconds>(end_ - start_).count()
                / microseconds::period::den;
        }
        else if (unit_ == MillSecond)
        {
            duration_ = (double)duration_cast<microseconds>(end_ - start_).count() / milliseconds::period::den;
        }
        else if (unit_ == MicroSecond)
        {
            duration_ = (double)duration_cast<microseconds>(end_ - start_).count();
        }
    }

    double Duration() const
    {
        return duration_;
    }

private:
    ClockUnit unit_;
    system_clock::time_point start_;
    system_clock::time_point end_;
    double duration_;
    bool is_start_;
};



#endif