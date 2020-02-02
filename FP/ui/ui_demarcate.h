/********************************************************************************
** Form generated from reading UI file 'demarcate.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMARCATE_H
#define UI_DEMARCATE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_demarcate
{
public:
    QPushButton *button_add;
    QLabel *label_pixel;
    QLineEdit *edit_pixel;
    QLabel *label_cavtiy;
    QLineEdit *edit_cavity;
    QPushButton *button_demarcate;
    QPushButton *button_save;
    QTableWidget *table_pixel_cavity;
    QPushButton *button_delete;
    QLabel *label_x_axis;
    QLabel *label_y_axis;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_fitting_count;
    QComboBox *combox_fitting_count;

    void setupUi(QDialog *demarcate)
    {
        if (demarcate->objectName().isEmpty())
            demarcate->setObjectName(QString::fromUtf8("demarcate"));
        demarcate->resize(800, 420);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon/logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        demarcate->setWindowIcon(icon);
        button_add = new QPushButton(demarcate);
        button_add->setObjectName(QString::fromUtf8("button_add"));
        button_add->setGeometry(QRect(30, 110, 80, 30));
        QFont font;
        font.setPointSize(12);
        button_add->setFont(font);
        label_pixel = new QLabel(demarcate);
        label_pixel->setObjectName(QString::fromUtf8("label_pixel"));
        label_pixel->setGeometry(QRect(150, 22, 41, 20));
        label_pixel->setFont(font);
        edit_pixel = new QLineEdit(demarcate);
        edit_pixel->setObjectName(QString::fromUtf8("edit_pixel"));
        edit_pixel->setGeometry(QRect(30, 20, 100, 25));
        label_cavtiy = new QLabel(demarcate);
        label_cavtiy->setObjectName(QString::fromUtf8("label_cavtiy"));
        label_cavtiy->setGeometry(QRect(150, 65, 41, 17));
        label_cavtiy->setFont(font);
        edit_cavity = new QLineEdit(demarcate);
        edit_cavity->setObjectName(QString::fromUtf8("edit_cavity"));
        edit_cavity->setGeometry(QRect(30, 60, 100, 25));
        button_demarcate = new QPushButton(demarcate);
        button_demarcate->setObjectName(QString::fromUtf8("button_demarcate"));
        button_demarcate->setGeometry(QRect(390, 350, 100, 50));
        button_demarcate->setFont(font);
        button_save = new QPushButton(demarcate);
        button_save->setObjectName(QString::fromUtf8("button_save"));
        button_save->setGeometry(QRect(630, 350, 100, 50));
        button_save->setFont(font);
        table_pixel_cavity = new QTableWidget(demarcate);
        if (table_pixel_cavity->columnCount() < 2)
            table_pixel_cavity->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_pixel_cavity->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_pixel_cavity->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        table_pixel_cavity->setObjectName(QString::fromUtf8("table_pixel_cavity"));
        table_pixel_cavity->setGeometry(QRect(20, 150, 210, 181));
        table_pixel_cavity->setFont(font);
        table_pixel_cavity->setRowCount(0);
        table_pixel_cavity->setColumnCount(2);
        button_delete = new QPushButton(demarcate);
        button_delete->setObjectName(QString::fromUtf8("button_delete"));
        button_delete->setGeometry(QRect(130, 110, 80, 30));
        button_delete->setFont(font);
        label_x_axis = new QLabel(demarcate);
        label_x_axis->setObjectName(QString::fromUtf8("label_x_axis"));
        label_x_axis->setGeometry(QRect(490, 310, 71, 21));
        label_x_axis->setFont(font);
        label_y_axis = new QLabel(demarcate);
        label_y_axis->setObjectName(QString::fromUtf8("label_y_axis"));
        label_y_axis->setGeometry(QRect(240, 110, 41, 91));
        label_y_axis->setFont(font);
        label_y_axis->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(demarcate);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 360, 151, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_fitting_count = new QLabel(layoutWidget);
        label_fitting_count->setObjectName(QString::fromUtf8("label_fitting_count"));
        label_fitting_count->setFont(font);

        horizontalLayout->addWidget(label_fitting_count);

        combox_fitting_count = new QComboBox(layoutWidget);
        combox_fitting_count->setObjectName(QString::fromUtf8("combox_fitting_count"));
        combox_fitting_count->setFont(font);

        horizontalLayout->addWidget(combox_fitting_count);


        retranslateUi(demarcate);

        QMetaObject::connectSlotsByName(demarcate);
    } // setupUi

    void retranslateUi(QDialog *demarcate)
    {
        demarcate->setWindowTitle(QApplication::translate("demarcate", "\347\263\273\347\273\237\346\240\207\345\256\232", 0, QApplication::UnicodeUTF8));
        button_add->setText(QApplication::translate("demarcate", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        label_pixel->setText(QApplication::translate("demarcate", "\345\203\217\345\205\203", 0, QApplication::UnicodeUTF8));
        label_cavtiy->setText(QApplication::translate("demarcate", "\350\205\224\351\225\277", 0, QApplication::UnicodeUTF8));
        button_demarcate->setText(QApplication::translate("demarcate", "\346\240\207\345\256\232", 0, QApplication::UnicodeUTF8));
        button_save->setText(QApplication::translate("demarcate", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = table_pixel_cavity->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("demarcate", "\345\203\217\345\205\203\346\225\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = table_pixel_cavity->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("demarcate", "\350\205\224\351\225\277/um", 0, QApplication::UnicodeUTF8));
        button_delete->setText(QApplication::translate("demarcate", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        label_x_axis->setText(QApplication::translate("demarcate", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\205\224\351\225\277/um</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_y_axis->setText(QApplication::translate("demarcate", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\203\217</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\205\203</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_fitting_count->setText(QApplication::translate("demarcate", "\346\213\237\345\220\210\346\254\241\346\225\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class demarcate: public Ui_demarcate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMARCATE_H
