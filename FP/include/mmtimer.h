#ifndef MMTIMER_H
#define MMTIMER_H

#include <QObject>
#include <Windows.h>

class MMTimer : public QObject
{
    friend void WINAPI CALLBACK mmtimer_proc(uint, uint, DWORD_PTR, DWORD_PTR, DWORD_PTR);

    Q_OBJECT

  public:
    explicit MMTimer(int interval, QObject *parent = 0);
    ~MMTimer();

signals:
    void timeout();

  public slots:
    void start();
    void stop();

  private:
    int timer_interval_;
    int timer_id_;
};
#endif // MMTIMER_H
