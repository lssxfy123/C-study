/********************************************************************************
** Form generated from reading UI file 'sensor_dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSOR_DIALOG_H
#define UI_SENSOR_DIALOG_H

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

class Ui_sensor_dialog
{
public:
    QGroupBox *group_box_instrument_select;
    QRadioButton *radio_button_instrument_1;
    QRadioButton *radio_button_instrument_2;
    QRadioButton *radio_button_instrument_3;
    QRadioButton *radio_button_instrument_4;
    QRadioButton *radio_button_instrument_5;
    QGroupBox *group_box_channel_select;
    QRadioButton *radio_button_channel_2;
    QRadioButton *radio_button_channel_3;
    QRadioButton *radio_button_channel_1;
    QRadioButton *radio_button_channel_5;
    QRadioButton *radio_button_channel_4;
    QRadioButton *radio_button_channel_6;
    QPushButton *button_set;
    QPushButton *button_cancel;

    void setupUi(QDialog *sensor_dialog)
    {
        if (sensor_dialog->objectName().isEmpty())
            sensor_dialog->setObjectName(QString::fromUtf8("sensor_dialog"));
        sensor_dialog->resize(500, 360);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon/logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        sensor_dialog->setWindowIcon(icon);
        group_box_instrument_select = new QGroupBox(sensor_dialog);
        group_box_instrument_select->setObjectName(QString::fromUtf8("group_box_instrument_select"));
        group_box_instrument_select->setGeometry(QRect(30, 40, 111, 201));
        radio_button_instrument_1 = new QRadioButton(group_box_instrument_select);
        radio_button_instrument_1->setObjectName(QString::fromUtf8("radio_button_instrument_1"));
        radio_button_instrument_1->setGeometry(QRect(10, 30, 60, 15));
        radio_button_instrument_2 = new QRadioButton(group_box_instrument_select);
        radio_button_instrument_2->setObjectName(QString::fromUtf8("radio_button_instrument_2"));
        radio_button_instrument_2->setGeometry(QRect(10, 60, 61, 16));
        radio_button_instrument_3 = new QRadioButton(group_box_instrument_select);
        radio_button_instrument_3->setObjectName(QString::fromUtf8("radio_button_instrument_3"));
        radio_button_instrument_3->setGeometry(QRect(10, 90, 60, 15));
        radio_button_instrument_4 = new QRadioButton(group_box_instrument_select);
        radio_button_instrument_4->setObjectName(QString::fromUtf8("radio_button_instrument_4"));
        radio_button_instrument_4->setGeometry(QRect(10, 120, 60, 15));
        radio_button_instrument_5 = new QRadioButton(group_box_instrument_select);
        radio_button_instrument_5->setObjectName(QString::fromUtf8("radio_button_instrument_5"));
        radio_button_instrument_5->setGeometry(QRect(10, 150, 60, 15));
        group_box_channel_select = new QGroupBox(sensor_dialog);
        group_box_channel_select->setObjectName(QString::fromUtf8("group_box_channel_select"));
        group_box_channel_select->setGeometry(QRect(300, 40, 91, 201));
        radio_button_channel_2 = new QRadioButton(group_box_channel_select);
        radio_button_channel_2->setObjectName(QString::fromUtf8("radio_button_channel_2"));
        radio_button_channel_2->setGeometry(QRect(10, 60, 61, 16));
        radio_button_channel_3 = new QRadioButton(group_box_channel_select);
        radio_button_channel_3->setObjectName(QString::fromUtf8("radio_button_channel_3"));
        radio_button_channel_3->setGeometry(QRect(10, 90, 60, 15));
        radio_button_channel_1 = new QRadioButton(group_box_channel_select);
        radio_button_channel_1->setObjectName(QString::fromUtf8("radio_button_channel_1"));
        radio_button_channel_1->setGeometry(QRect(10, 30, 60, 15));
        radio_button_channel_5 = new QRadioButton(group_box_channel_select);
        radio_button_channel_5->setObjectName(QString::fromUtf8("radio_button_channel_5"));
        radio_button_channel_5->setGeometry(QRect(10, 150, 60, 15));
        radio_button_channel_4 = new QRadioButton(group_box_channel_select);
        radio_button_channel_4->setObjectName(QString::fromUtf8("radio_button_channel_4"));
        radio_button_channel_4->setGeometry(QRect(10, 120, 60, 15));
        radio_button_channel_6 = new QRadioButton(group_box_channel_select);
        radio_button_channel_6->setObjectName(QString::fromUtf8("radio_button_channel_6"));
        radio_button_channel_6->setGeometry(QRect(10, 180, 60, 15));
        button_set = new QPushButton(sensor_dialog);
        button_set->setObjectName(QString::fromUtf8("button_set"));
        button_set->setGeometry(QRect(80, 290, 80, 30));
        button_cancel = new QPushButton(sensor_dialog);
        button_cancel->setObjectName(QString::fromUtf8("button_cancel"));
        button_cancel->setGeometry(QRect(290, 290, 80, 30));

        retranslateUi(sensor_dialog);

        QMetaObject::connectSlotsByName(sensor_dialog);
    } // setupUi

    void retranslateUi(QDialog *sensor_dialog)
    {
        sensor_dialog->setWindowTitle(QApplication::translate("sensor_dialog", "\344\274\240\346\204\237\345\231\250\350\260\203\350\257\225", 0, QApplication::UnicodeUTF8));
        group_box_instrument_select->setTitle(QApplication::translate("sensor_dialog", "\351\200\211\346\213\251\344\273\252\345\231\250", 0, QApplication::UnicodeUTF8));
        radio_button_instrument_1->setText(QApplication::translate("sensor_dialog", "\344\273\252\345\231\2501", 0, QApplication::UnicodeUTF8));
        radio_button_instrument_2->setText(QApplication::translate("sensor_dialog", "\344\273\252\345\231\2502", 0, QApplication::UnicodeUTF8));
        radio_button_instrument_3->setText(QApplication::translate("sensor_dialog", "\344\273\252\345\231\2503", 0, QApplication::UnicodeUTF8));
        radio_button_instrument_4->setText(QApplication::translate("sensor_dialog", "\344\273\252\345\231\2504", 0, QApplication::UnicodeUTF8));
        radio_button_instrument_5->setText(QApplication::translate("sensor_dialog", "\344\273\252\345\231\2505", 0, QApplication::UnicodeUTF8));
        group_box_channel_select->setTitle(QApplication::translate("sensor_dialog", "\351\200\211\346\213\251\351\200\232\351\201\223", 0, QApplication::UnicodeUTF8));
        radio_button_channel_2->setText(QApplication::translate("sensor_dialog", "\351\200\232\351\201\2232", 0, QApplication::UnicodeUTF8));
        radio_button_channel_3->setText(QApplication::translate("sensor_dialog", "\351\200\232\351\201\2233", 0, QApplication::UnicodeUTF8));
        radio_button_channel_1->setText(QApplication::translate("sensor_dialog", "\351\200\232\351\201\2231", 0, QApplication::UnicodeUTF8));
        radio_button_channel_5->setText(QApplication::translate("sensor_dialog", "\351\200\232\351\201\2235", 0, QApplication::UnicodeUTF8));
        radio_button_channel_4->setText(QApplication::translate("sensor_dialog", "\351\200\232\351\201\2234", 0, QApplication::UnicodeUTF8));
        radio_button_channel_6->setText(QApplication::translate("sensor_dialog", "\351\200\232\351\201\2236", 0, QApplication::UnicodeUTF8));
        button_set->setText(QApplication::translate("sensor_dialog", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        button_cancel->setText(QApplication::translate("sensor_dialog", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sensor_dialog: public Ui_sensor_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSOR_DIALOG_H
