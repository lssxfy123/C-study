/********************************************************************************
** Form generated from reading UI file 'channel_dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANNEL_DIALOG_H
#define UI_CHANNEL_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_channel_dialog
{
public:
    QLabel *label_X;
    QLabel *label_Y;
    QPushButton *button_zoom_out;
    QPushButton *button_zoom_in;

    void setupUi(QDialog *channel_dialog)
    {
        if (channel_dialog->objectName().isEmpty())
            channel_dialog->setObjectName(QString::fromUtf8("channel_dialog"));
        channel_dialog->resize(400, 300);
        channel_dialog->setMinimumSize(QSize(0, 0));
        label_X = new QLabel(channel_dialog);
        label_X->setObjectName(QString::fromUtf8("label_X"));
        label_X->setGeometry(QRect(175, 270, 50, 15));
        label_Y = new QLabel(channel_dialog);
        label_Y->setObjectName(QString::fromUtf8("label_Y"));
        label_Y->setGeometry(QRect(10, 125, 15, 50));
        button_zoom_out = new QPushButton(channel_dialog);
        button_zoom_out->setObjectName(QString::fromUtf8("button_zoom_out"));
        button_zoom_out->setGeometry(QRect(200, 0, 30, 30));
        button_zoom_in = new QPushButton(channel_dialog);
        button_zoom_in->setObjectName(QString::fromUtf8("button_zoom_in"));
        button_zoom_in->setGeometry(QRect(140, 0, 30, 30));
        button_zoom_in->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(channel_dialog);

        QMetaObject::connectSlotsByName(channel_dialog);
    } // setupUi

    void retranslateUi(QDialog *channel_dialog)
    {
        channel_dialog->setWindowTitle(QApplication::translate("channel_dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_X->setText(QApplication::translate("channel_dialog", "\346\227\266\351\227\264/ms", 0, QApplication::UnicodeUTF8));
        label_Y->setText(QApplication::translate("channel_dialog", "\345\212\233\n"
"/\n"
"\347\211\233", 0, QApplication::UnicodeUTF8));
        button_zoom_out->setText(QString());
        button_zoom_in->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class channel_dialog: public Ui_channel_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNEL_DIALOG_H
