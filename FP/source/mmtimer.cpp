#include "../include/mmtimer.h"

#pragma comment(lib,"Winmm.lib")

void WINAPI CALLBACK mmtimer_proc(uint timerId, uint, DWORD_PTR user, DWORD_PTR, DWORD_PTR)
{
    MMTimer *t = reinterpret_cast<MMTimer*>(user);
    emit t->timeout();
}

MMTimer::MMTimer(int interval, QObject *parent) :
QObject(parent), timer_interval_(interval), timer_id_(0)
{
}

MMTimer::~MMTimer()
{
    stop();
}

void MMTimer::start()
{
    timer_id_ = timeSetEvent(timer_interval_, 1, mmtimer_proc, (DWORD_PTR)this,
        TIME_CALLBACK_FUNCTION | TIME_PERIODIC | TIME_KILL_SYNCHRONOUS);
}

void MMTimer::stop()
{
    if (timer_id_){
        timeKillEvent(timer_id_);
        timer_id_ = 0;
    }
}
