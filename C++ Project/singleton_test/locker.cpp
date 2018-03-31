#include "locker.h"

Locker::Locker()
{
#ifdef _WIN32
    InitializeCriticalSection(&locker_);
#else
    pthread_mutex_init(&locker_,NULL);
#endif
}

Locker::~Locker()
{
#ifdef _WIN32
    DeleteCriticalSection(&locker_);
#else
    pthread_mutex_destroy(&locker_);
#endif
}

void Locker::lock()
{
#ifdef _WIN32
    EnterCriticalSection(&locker_);
#else
    pthread_mutex_lock(&locker_);
#endif
}

void Locker::unlock()
{
#ifdef _WIN32
    LeaveCriticalSection(&locker_);
#else
    pthread_mutex_unlock(&locker_);
#endif
}
