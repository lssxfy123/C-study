#include <QtGui/QApplication>
#include <QFile>
#include<QTextCodec>
#include <QTextStream>

#include "../include/mainwindow.h"
#include "../include/object.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Object object("object");

    //QApplication::addLibraryPath("../plugins");
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

    return a.exec();
}
