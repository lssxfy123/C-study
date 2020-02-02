/********************************************************************************
** Form generated from reading UI file 'fft_dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FFT_DIALOG_H
#define UI_FFT_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_fft_dialog
{
public:
    QPushButton *button_zoom_out;
    QPushButton *button_zoom_in;

    void setupUi(QDialog *fft_dialog)
    {
        if (fft_dialog->objectName().isEmpty())
            fft_dialog->setObjectName(QString::fromUtf8("fft_dialog"));
        fft_dialog->resize(400, 300);
        button_zoom_out = new QPushButton(fft_dialog);
        button_zoom_out->setObjectName(QString::fromUtf8("button_zoom_out"));
        button_zoom_out->setGeometry(QRect(190, 10, 30, 30));
        button_zoom_in = new QPushButton(fft_dialog);
        button_zoom_in->setObjectName(QString::fromUtf8("button_zoom_in"));
        button_zoom_in->setGeometry(QRect(130, 10, 30, 30));
        button_zoom_in->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(fft_dialog);

        QMetaObject::connectSlotsByName(fft_dialog);
    } // setupUi

    void retranslateUi(QDialog *fft_dialog)
    {
        fft_dialog->setWindowTitle(QApplication::translate("fft_dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        button_zoom_out->setText(QString());
        button_zoom_in->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class fft_dialog: public Ui_fft_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FFT_DIALOG_H
