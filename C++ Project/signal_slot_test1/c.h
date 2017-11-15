#ifndef C_H
#define C_H

#include "b.h"

class C : public B
{
    Q_OBJECT

  public slots:
    void SlotTest();
};

#endif
