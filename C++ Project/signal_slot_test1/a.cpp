#include "a.h"

A::A(QObject* parent /* = NULL */)
: QObject(parent)
{

}

void A::SendSignal()
{
    emit signalTest();
}
