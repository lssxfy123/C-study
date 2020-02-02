/********************************************************************************
** Form generated from reading UI file 'trigger_mode.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIGGER_MODE_H
#define UI_TRIGGER_MODE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_trigger_mode_dialog
{
public:
    QPushButton *button_sure;
    QPushButton *button_cancel;
    QGroupBox *groupBox;
    QRadioButton *radio_button_high;
    QRadioButton *radio_button_low;

    void setupUi(QDialog *trigger_mode_dialog)
    {
        if (trigger_mode_dialog->objectName().isEmpty())
            trigger_mode_dialog->setObjectName(QString::fromUtf8("trigger_mode_dialog"));
        trigger_mode_dialog->resize(300, 200);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon/logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        trigger_mode_dialog->setWindowIcon(icon);
        button_sure = new QPushButton(trigger_mode_dialog);
        button_sure->setObjectName(QString::fromUtf8("button_sure"));
        button_sure->setGeometry(QRect(30, 150, 80, 30));
        button_cancel = new QPushButton(trigger_mode_dialog);
        button_cancel->setObjectName(QString::fromUtf8("button_cancel"));
        button_cancel->setGeometry(QRect(190, 150, 80, 30));
        groupBox = new QGroupBox(trigger_mode_dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(50, 10, 200, 120));
        radio_button_high = new QRadioButton(groupBox);
        radio_button_high->setObjectName(QString::fromUtf8("radio_button_high"));
        radio_button_high->setGeometry(QRect(50, 30, 90, 20));
        radio_button_high->setChecked(true);
        radio_button_low = new QRadioButton(groupBox);
        radio_button_low->setObjectName(QString::fromUtf8("radio_button_low"));
        radio_button_low->setGeometry(QRect(50, 80, 90, 20));

        retranslateUi(trigger_mode_dialog);

        QMetaObject::connectSlotsByName(trigger_mode_dialog);
    } // setupUi

    void retranslateUi(QDialog *trigger_mode_dialog)
    {
        trigger_mode_dialog->setWindowTitle(QApplication::translate("trigger_mode_dialog", "\350\247\246\345\217\221\346\250\241\345\274\217\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        button_sure->setText(QApplication::translate("trigger_mode_dialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        button_cancel->setText(QApplication::translate("trigger_mode_dialog", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("trigger_mode_dialog", "\350\247\246\345\217\221\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        radio_button_high->setText(QApplication::translate("trigger_mode_dialog", "\351\253\230\344\272\216\351\231\220\345\200\274\350\247\246\345\217\221", 0, QApplication::UnicodeUTF8));
        radio_button_low->setText(QApplication::translate("trigger_mode_dialog", "\344\275\216\344\272\216\351\231\220\345\200\274\350\247\246\345\217\221", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class trigger_mode_dialog: public Ui_trigger_mode_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIGGER_MODE_H
