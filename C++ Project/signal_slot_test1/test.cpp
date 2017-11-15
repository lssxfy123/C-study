
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

    // �����źź󣬵��õ�����C��SlotTest()�ۺ���
    a.SendSignal();
    return app.exec();
}
