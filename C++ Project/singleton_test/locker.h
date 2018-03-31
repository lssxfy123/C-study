#ifndef LOCKER_H
#define LOCKER_H

#ifdef _WIN32
#include <process.h>
#include <windows.h>
#else
#include <pthread.h>
#include   <unistd.h>
#endif


#include <string>
using namespace std;

class Locker {
public:
    Locker();
    ~Locker();

    void lock();
    void unlock();

private:
#ifdef _WIN32
    CRITICAL_SECTION locker_;
#else
    pthread_mutex_t locker_;
#endif

};

#endif
