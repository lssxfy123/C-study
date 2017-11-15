
#include <QApplication>


#include "a.h"
#include "b.h"
#include "c.h"

int main(int argc, char* argv[])
{
    QApplication app(argc,argv);
    A a;
    B* b = new C;

    QObject::connect(&a, SIGNAL(signalTest()), b, SLOT(SlotTest()));

    // 发射信号后，调用的是类C的SlotTest()槽函数
    a.SendSignal();
    return app.exec();
}
