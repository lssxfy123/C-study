/********************************************************************************
** Form generated from reading UI file 'demarcate_dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMARCATE_DIALOG_H
#define UI_DEMARCATE_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_demarcate_dialog
{
public:
    QLabel *label_x_3;
    QLabel *label_x_2;
    QLabel *label_x_1;
    QLabel *label_const;
    QLineEdit *line_edit_x_3;
    QLineEdit *line_edit_x_2;
    QLineEdit *line_edit_x_1;
    QLineEdit *line_edit_const;
    QPushButton *button_sure;
    QPushButton *button_cancel;

    void setupUi(QDialog *demarcate_dialog)
    {
        if (demarcate_dialog->objectName().isEmpty())
            demarcate_dialog->setObjectName(QString::fromUtf8("demarcate_dialog"));
        demarcate_dialog->resize(490, 210);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon/logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        demarcate_dialog->setWindowIcon(icon);
        label_x_3 = new QLabel(demarcate_dialog);
        label_x_3->setObjectName(QString::fromUtf8("label_x_3"));
        label_x_3->setGeometry(QRect(20, 30, 50, 15));
        label_x_2 = new QLabel(demarcate_dialog);
        label_x_2->setObjectName(QString::fromUtf8("label_x_2"));
        label_x_2->setGeometry(QRect(140, 30, 50, 15));
        label_x_1 = new QLabel(demarcate_dialog);
        label_x_1->setObjectName(QString::fromUtf8("label_x_1"));
        label_x_1->setGeometry(QRect(260, 30, 50, 15));
        label_const = new QLabel(demarcate_dialog);
        label_const->setObjectName(QString::fromUtf8("label_const"));
        label_const->setGeometry(QRect(380, 30, 50, 15));
        line_edit_x_3 = new QLineEdit(demarcate_dialog);
        line_edit_x_3->setObjectName(QString::fromUtf8("line_edit_x_3"));
        line_edit_x_3->setGeometry(QRect(20, 60, 100, 20));
        line_edit_x_2 = new QLineEdit(demarcate_dialog);
        line_edit_x_2->setObjectName(QString::fromUtf8("line_edit_x_2"));
        line_edit_x_2->setGeometry(QRect(140, 60, 100, 20));
        line_edit_x_1 = new QLineEdit(demarcate_dialog);
        line_edit_x_1->setObjectName(QString::fromUtf8("line_edit_x_1"));
        line_edit_x_1->setGeometry(QRect(260, 60, 100, 20));
        line_edit_const = new QLineEdit(demarcate_dialog);
        line_edit_const->setObjectName(QString::fromUtf8("line_edit_const"));
        line_edit_const->setGeometry(QRect(380, 60, 100, 20));
        button_sure = new QPushButton(demarcate_dialog);
        button_sure->setObjectName(QString::fromUtf8("button_sure"));
        button_sure->setGeometry(QRect(50, 110, 80, 30));
        button_cancel = new QPushButton(demarcate_dialog);
        button_cancel->setObjectName(QString::fromUtf8("button_cancel"));
        button_cancel->setGeometry(QRect(350, 110, 80, 30));

        retranslateUi(demarcate_dialog);

        QMetaObject::connectSlotsByName(demarcate_dialog);
    } // setupUi

    void retranslateUi(QDialog *demarcate_dialog)
    {
        demarcate_dialog->setWindowTitle(QApplication::translate("demarcate_dialog", "\344\274\240\346\204\237\345\231\250\346\240\207\345\256\232", 0, QApplication::UnicodeUTF8));
        label_x_3->setText(QApplication::translate("demarcate_dialog", "\344\270\211\346\254\241\351\241\271", 0, QApplication::UnicodeUTF8));
        label_x_2->setText(QApplication::translate("demarcate_dialog", "\344\272\214\346\254\241\351\241\271", 0, QApplication::UnicodeUTF8));
        label_x_1->setText(QApplication::translate("demarcate_dialog", "\344\270\200\346\254\241\351\241\271", 0, QApplication::UnicodeUTF8));
        label_const->setText(QApplication::translate("demarcate_dialog", "\345\270\270\346\225\260\351\241\271", 0, QApplication::UnicodeUTF8));
        button_sure->setText(QApplication::translate("demarcate_dialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        button_cancel->setText(QApplication::translate("demarcate_dialog", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class demarcate_dialog: public Ui_demarcate_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMARCATE_DIALOG_H
