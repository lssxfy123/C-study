/********************************************************************************
** Form generated from reading UI file 'channel_tab.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANNEL_TAB_H
#define UI_CHANNEL_TAB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_channel_tab
{
public:
    QWidget *tab;

    void setupUi(QTabWidget *channel_tab)
    {
        if (channel_tab->objectName().isEmpty())
            channel_tab->setObjectName(QString::fromUtf8("channel_tab"));
        channel_tab->resize(600, 480);
        channel_tab->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon/\345\233\276\346\240\207.png"), QSize(), QIcon::Normal, QIcon::Off);
        channel_tab->setWindowIcon(icon);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        channel_tab->addTab(tab, QString());

        retranslateUi(channel_tab);

        channel_tab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(channel_tab);
    } // setupUi

    void retranslateUi(QTabWidget *channel_tab)
    {
        channel_tab->setWindowTitle(QApplication::translate("channel_tab", "Form", 0, QApplication::UnicodeUTF8));
        channel_tab->setTabText(channel_tab->indexOf(tab), QApplication::translate("channel_tab", "Tab 1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class channel_tab: public Ui_channel_tab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNEL_TAB_H
