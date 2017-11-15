#ifndef B_H
#define B_H

#include <QObject>
#include <QtDebug>

class B : public QObject
{
    Q_OBJECT

  public slots:
    virtual void SlotTest();
};

#endif
