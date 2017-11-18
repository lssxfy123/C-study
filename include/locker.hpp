#ifndef LOCKER_H
#define LOCKER_H

#include <iostream>
#ifdef _MSC_VER
#include <process.h>
#endif

using namespace std;

class Locker
{
public:
    Locker()
    {
#ifdef _MSC_VER
        InitializeCriticalSection(&critical_section_);
#endif
    }

    ~Locker()
    {
#ifdef _MSC_VER
        DeleteCriticalSection(&critical_section_);
#endif
    }

    void lock()
    {
#ifdef _MSC_VER
        EnterCriticalSection(&critical_section_);
#endif
    }

    void unlock()
    {
#ifdef _MSC_VER
        LeaveCriticalSection(&critical_section_);
#endif
    }

private:
#ifdef _MSC_VER
    CRITICAL_SECTION critical_section_;
#endif
};

#endif  // LOCKER_H
