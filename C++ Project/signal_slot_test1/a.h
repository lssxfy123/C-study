#ifndef A_H
#define A_H

#include <QObject>

class A : public QObject
{
    Q_OBJECT

public:
    A(QObject* parent = NULL);

    signals:
        void signalTest();
    
  public:
    void SendSignal();
};

#endif
