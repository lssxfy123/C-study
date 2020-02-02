/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QAction *open;
    QAction *action_save;
    QAction *exit;
    QAction *com_setting;
    QAction *demacrate;
    QAction *actionVer_01;
    QAction *single;
    QAction *multi;
    QAction *action_sensor_debug;
    QAction *action_collect;
    QAction *action_stop;
    QAction *action_instrument_1;
    QAction *action_instrument_2;
    QAction *action_instrument_3;
    QAction *action_instrument_4;
    QAction *action_instrument_5;
    QAction *action_channel_1;
    QAction *action_channel_2;
    QAction *action_channel_3;
    QAction *action_channel_4;
    QAction *action_channel_5;
    QAction *action_channel_6;
    QAction *action_fft;
    QAction *action_select_all;
    QAction *action_save_depth;
    QAction *action_image_save;
    QAction *action;
    QAction *action_trigger_channel_1;
    QAction *action_trigger_channel_2;
    QAction *action_trigger_channel_3;
    QAction *action_trigger_channel_4;
    QAction *action_trigger_channel_5;
    QAction *action_trigger_channel_6;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *file;
    QMenu *setting;
    QMenu *menu_instrument_select;
    QMenu *menu_channel_select;
    QMenu *menu_trigger_set;
    QMenu *help;
    QMenu *menu_data_deal;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *tool_bar_data_deal;

    void setupUi(QMainWindow *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QString::fromUtf8("main_window"));
        main_window->resize(800, 550);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon/logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        main_window->setWindowIcon(icon);
        open = new QAction(main_window);
        open->setObjectName(QString::fromUtf8("open"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        open->setIcon(icon1);
        action_save = new QAction(main_window);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        action_save->setIcon(icon1);
        exit = new QAction(main_window);
        exit->setObjectName(QString::fromUtf8("exit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exit->setIcon(icon2);
        com_setting = new QAction(main_window);
        com_setting->setObjectName(QString::fromUtf8("com_setting"));
        demacrate = new QAction(main_window);
        demacrate->setObjectName(QString::fromUtf8("demacrate"));
        demacrate->setCheckable(false);
        actionVer_01 = new QAction(main_window);
        actionVer_01->setObjectName(QString::fromUtf8("actionVer_01"));
        single = new QAction(main_window);
        single->setObjectName(QString::fromUtf8("single"));
        single->setCheckable(true);
        multi = new QAction(main_window);
        multi->setObjectName(QString::fromUtf8("multi"));
        multi->setCheckable(true);
        action_sensor_debug = new QAction(main_window);
        action_sensor_debug->setObjectName(QString::fromUtf8("action_sensor_debug"));
        action_collect = new QAction(main_window);
        action_collect->setObjectName(QString::fromUtf8("action_collect"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/collect.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_collect->setIcon(icon3);
        action_stop = new QAction(main_window);
        action_stop->setObjectName(QString::fromUtf8("action_stop"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_stop->setIcon(icon4);
        action_instrument_1 = new QAction(main_window);
        action_instrument_1->setObjectName(QString::fromUtf8("action_instrument_1"));
        action_instrument_1->setCheckable(true);
        action_instrument_2 = new QAction(main_window);
        action_instrument_2->setObjectName(QString::fromUtf8("action_instrument_2"));
        action_instrument_2->setCheckable(true);
        action_instrument_3 = new QAction(main_window);
        action_instrument_3->setObjectName(QString::fromUtf8("action_instrument_3"));
        action_instrument_3->setCheckable(true);
        action_instrument_4 = new QAction(main_window);
        action_instrument_4->setObjectName(QString::fromUtf8("action_instrument_4"));
        action_instrument_4->setCheckable(true);
        action_instrument_5 = new QAction(main_window);
        action_instrument_5->setObjectName(QString::fromUtf8("action_instrument_5"));
        action_instrument_5->setCheckable(true);
        action_channel_1 = new QAction(main_window);
        action_channel_1->setObjectName(QString::fromUtf8("action_channel_1"));
        action_channel_1->setCheckable(true);
        action_channel_2 = new QAction(main_window);
        action_channel_2->setObjectName(QString::fromUtf8("action_channel_2"));
        action_channel_2->setCheckable(true);
        action_channel_3 = new QAction(main_window);
        action_channel_3->setObjectName(QString::fromUtf8("action_channel_3"));
        action_channel_3->setCheckable(true);
        action_channel_4 = new QAction(main_window);
        action_channel_4->setObjectName(QString::fromUtf8("action_channel_4"));
        action_channel_4->setCheckable(true);
        action_channel_5 = new QAction(main_window);
        action_channel_5->setObjectName(QString::fromUtf8("action_channel_5"));
        action_channel_5->setCheckable(true);
        action_channel_6 = new QAction(main_window);
        action_channel_6->setObjectName(QString::fromUtf8("action_channel_6"));
        action_channel_6->setCheckable(true);
        action_fft = new QAction(main_window);
        action_fft->setObjectName(QString::fromUtf8("action_fft"));
        action_fft->setCheckable(true);
        action_select_all = new QAction(main_window);
        action_select_all->setObjectName(QString::fromUtf8("action_select_all"));
        action_select_all->setCheckable(true);
        action_save_depth = new QAction(main_window);
        action_save_depth->setObjectName(QString::fromUtf8("action_save_depth"));
        action_image_save = new QAction(main_window);
        action_image_save->setObjectName(QString::fromUtf8("action_image_save"));
        action = new QAction(main_window);
        action->setObjectName(QString::fromUtf8("action"));
        action_trigger_channel_1 = new QAction(main_window);
        action_trigger_channel_1->setObjectName(QString::fromUtf8("action_trigger_channel_1"));
        action_trigger_channel_2 = new QAction(main_window);
        action_trigger_channel_2->setObjectName(QString::fromUtf8("action_trigger_channel_2"));
        action_trigger_channel_3 = new QAction(main_window);
        action_trigger_channel_3->setObjectName(QString::fromUtf8("action_trigger_channel_3"));
        action_trigger_channel_4 = new QAction(main_window);
        action_trigger_channel_4->setObjectName(QString::fromUtf8("action_trigger_channel_4"));
        action_trigger_channel_5 = new QAction(main_window);
        action_trigger_channel_5->setObjectName(QString::fromUtf8("action_trigger_channel_5"));
        action_trigger_channel_6 = new QAction(main_window);
        action_trigger_channel_6->setObjectName(QString::fromUtf8("action_trigger_channel_6"));
        centralWidget = new QWidget(main_window);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        main_window->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(main_window);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        file = new QMenu(menuBar);
        file->setObjectName(QString::fromUtf8("file"));
        setting = new QMenu(menuBar);
        setting->setObjectName(QString::fromUtf8("setting"));
        menu_instrument_select = new QMenu(setting);
        menu_instrument_select->setObjectName(QString::fromUtf8("menu_instrument_select"));
        menu_channel_select = new QMenu(setting);
        menu_channel_select->setObjectName(QString::fromUtf8("menu_channel_select"));
        menu_trigger_set = new QMenu(setting);
        menu_trigger_set->setObjectName(QString::fromUtf8("menu_trigger_set"));
        help = new QMenu(menuBar);
        help->setObjectName(QString::fromUtf8("help"));
        menu_data_deal = new QMenu(menuBar);
        menu_data_deal->setObjectName(QString::fromUtf8("menu_data_deal"));
        main_window->setMenuBar(menuBar);
        statusBar = new QStatusBar(main_window);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        main_window->setStatusBar(statusBar);
        toolBar = new QToolBar(main_window);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        main_window->addToolBar(Qt::TopToolBarArea, toolBar);
        tool_bar_data_deal = new QToolBar(main_window);
        tool_bar_data_deal->setObjectName(QString::fromUtf8("tool_bar_data_deal"));
        main_window->addToolBar(Qt::TopToolBarArea, tool_bar_data_deal);

        menuBar->addAction(file->menuAction());
        menuBar->addAction(setting->menuAction());
        menuBar->addAction(menu_data_deal->menuAction());
        menuBar->addAction(help->menuAction());
        file->addAction(action_save);
        file->addAction(action_image_save);
        file->addSeparator();
        file->addAction(exit);
        setting->addAction(action_sensor_debug);
        setting->addAction(menu_trigger_set->menuAction());
        setting->addAction(menu_instrument_select->menuAction());
        setting->addAction(menu_channel_select->menuAction());
        setting->addAction(action_save_depth);
        menu_instrument_select->addAction(action_instrument_1);
        menu_instrument_select->addAction(action_instrument_2);
        menu_instrument_select->addAction(action_instrument_3);
        menu_instrument_select->addAction(action_instrument_4);
        menu_instrument_select->addAction(action_instrument_5);
        menu_channel_select->addAction(action_select_all);
        menu_channel_select->addAction(action_channel_1);
        menu_channel_select->addAction(action_channel_2);
        menu_channel_select->addAction(action_channel_3);
        menu_channel_select->addAction(action_channel_4);
        menu_channel_select->addAction(action_channel_5);
        menu_channel_select->addAction(action_channel_6);
        menu_trigger_set->addAction(action_trigger_channel_1);
        menu_trigger_set->addAction(action_trigger_channel_2);
        menu_trigger_set->addAction(action_trigger_channel_3);
        menu_trigger_set->addAction(action_trigger_channel_4);
        menu_trigger_set->addAction(action_trigger_channel_5);
        menu_trigger_set->addAction(action_trigger_channel_6);
        menu_data_deal->addAction(action_fft);
        toolBar->addAction(action_collect);
        toolBar->addAction(action_stop);
        toolBar->addSeparator();
        toolBar->addAction(action_save);
        toolBar->addAction(exit);
        toolBar->addSeparator();

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QMainWindow *main_window)
    {
        main_window->setWindowTitle(QApplication::translate("main_window", "MainWindow", 0, QApplication::UnicodeUTF8));
        open->setText(QApplication::translate("main_window", "\346\267\273\345\212\240\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        open->setToolTip(QApplication::translate("main_window", "\346\267\273\345\212\240\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        open->setStatusTip(QApplication::translate("main_window", "\346\211\223\345\274\200", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_save->setText(QApplication::translate("main_window", "\344\277\235\345\255\230\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_save->setToolTip(QApplication::translate("main_window", "\344\277\235\345\255\230\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        exit->setText(QApplication::translate("main_window", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        com_setting->setText(QApplication::translate("main_window", "\351\200\232\344\277\241\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        demacrate->setText(QApplication::translate("main_window", "\346\240\207\345\256\232", 0, QApplication::UnicodeUTF8));
        actionVer_01->setText(QApplication::translate("main_window", "Ver_01", 0, QApplication::UnicodeUTF8));
        single->setText(QApplication::translate("main_window", "\345\215\225\346\254\241", 0, QApplication::UnicodeUTF8));
        multi->setText(QApplication::translate("main_window", "\350\277\236\347\273\255", 0, QApplication::UnicodeUTF8));
        action_sensor_debug->setText(QApplication::translate("main_window", "\344\274\240\346\204\237\345\231\250\350\260\203\350\257\225", 0, QApplication::UnicodeUTF8));
        action_collect->setText(QApplication::translate("main_window", "\351\207\207\351\233\206", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_collect->setToolTip(QApplication::translate("main_window", "\351\207\207\351\233\206", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_stop->setText(QApplication::translate("main_window", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_stop->setToolTip(QApplication::translate("main_window", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_instrument_1->setText(QApplication::translate("main_window", "\344\273\252\345\231\2501", 0, QApplication::UnicodeUTF8));
        action_instrument_2->setText(QApplication::translate("main_window", "\344\273\252\345\231\2502", 0, QApplication::UnicodeUTF8));
        action_instrument_3->setText(QApplication::translate("main_window", "\344\273\252\345\231\2503", 0, QApplication::UnicodeUTF8));
        action_instrument_4->setText(QApplication::translate("main_window", "\344\273\252\345\231\2504", 0, QApplication::UnicodeUTF8));
        action_instrument_5->setText(QApplication::translate("main_window", "\344\273\252\345\231\2505", 0, QApplication::UnicodeUTF8));
        action_channel_1->setText(QApplication::translate("main_window", "\351\200\232\351\201\2231", 0, QApplication::UnicodeUTF8));
        action_channel_2->setText(QApplication::translate("main_window", "\351\200\232\351\201\2232", 0, QApplication::UnicodeUTF8));
        action_channel_3->setText(QApplication::translate("main_window", "\351\200\232\351\201\2233", 0, QApplication::UnicodeUTF8));
        action_channel_4->setText(QApplication::translate("main_window", "\351\200\232\351\201\2234", 0, QApplication::UnicodeUTF8));
        action_channel_5->setText(QApplication::translate("main_window", "\351\200\232\351\201\2235", 0, QApplication::UnicodeUTF8));
        action_channel_6->setText(QApplication::translate("main_window", "\351\200\232\351\201\2236", 0, QApplication::UnicodeUTF8));
        action_fft->setText(QApplication::translate("main_window", "FFT", 0, QApplication::UnicodeUTF8));
        action_select_all->setText(QApplication::translate("main_window", "\351\200\211\346\213\251\345\205\250\351\203\250", 0, QApplication::UnicodeUTF8));
        action_save_depth->setText(QApplication::translate("main_window", "\345\255\230\345\202\250\346\267\261\345\272\246", 0, QApplication::UnicodeUTF8));
        action_image_save->setText(QApplication::translate("main_window", "\344\277\235\345\255\230\345\233\276\347\211\207", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("main_window", "\350\247\246\345\217\221\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        action_trigger_channel_1->setText(QApplication::translate("main_window", "\351\200\232\351\201\2231", 0, QApplication::UnicodeUTF8));
        action_trigger_channel_2->setText(QApplication::translate("main_window", "\351\200\232\351\201\2232", 0, QApplication::UnicodeUTF8));
        action_trigger_channel_3->setText(QApplication::translate("main_window", "\351\200\232\351\201\2233", 0, QApplication::UnicodeUTF8));
        action_trigger_channel_4->setText(QApplication::translate("main_window", "\351\200\232\351\201\2234", 0, QApplication::UnicodeUTF8));
        action_trigger_channel_5->setText(QApplication::translate("main_window", "\351\200\232\351\201\2235", 0, QApplication::UnicodeUTF8));
        action_trigger_channel_6->setText(QApplication::translate("main_window", "\351\200\232\351\201\2236", 0, QApplication::UnicodeUTF8));
        file->setTitle(QApplication::translate("main_window", "\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        setting->setTitle(QApplication::translate("main_window", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        menu_instrument_select->setTitle(QApplication::translate("main_window", "\344\273\252\345\231\250\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        menu_channel_select->setTitle(QApplication::translate("main_window", "\351\200\232\351\201\223\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        menu_trigger_set->setTitle(QApplication::translate("main_window", "\350\247\246\345\217\221\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        help->setTitle(QApplication::translate("main_window", "\345\270\256\345\212\251", 0, QApplication::UnicodeUTF8));
        menu_data_deal->setTitle(QApplication::translate("main_window", "\346\225\260\346\215\256\345\244\204\347\220\206", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("main_window", "toolBar", 0, QApplication::UnicodeUTF8));
        tool_bar_data_deal->setWindowTitle(QApplication::translate("main_window", "toolBar_2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
