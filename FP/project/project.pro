#-------------------------------------------------
#
# Project created by QtCreator 2014-04-24T19:44:15
#
#-------------------------------------------------

QT       += core gui

CONFIG += debug release
#CONFIG += console

TEMPLATE = app


release {  
    TARGET = FP
    DESTDIR     = ../bin
    UI_DIR      = ../ui
    OBJECTS_DIR = ../release/FP
    MOC_DIR     = ../release/FP
    RCC_DIR     = ../release/FP
}

debug {
    TARGET = FP
    DESTDIR     = ../bin
    UI_DIR      = ../ui
    OBJECTS_DIR = ../debug/FP
    RCC_DIR     = ../debug/FP
    MOC_DIR     = ../debug/FP
}

HEADERS += ../include/channeldialog.h \        
           ../include/channeltabbar.h \
           ../include/channeltabwidget.h \
           ../include/CyAPI.h \
           ../include/object.h \
           ../include/DataFit.h \
#           ../include/DataFit_emxAPI.h \
#           ../include/DataFit_emxutil.h \
           ../include/DataFit_initialize.h \
           ../include/DataFit_terminate.h \
           ../include/DataFit_types.h \
           ../include/demarcate.h \
           ../include/demarcatedialog.h \
           ../include/fftdialog.h \
           ../include/global.h \
           ../include/mainwindow.h\
           ../include/mmtimer.h  \
           ../include/MT_emxAPI.h \
           ../include/MT_emxutil.h \
           ../include/myfft_N.h \
           ../include/myfft_N_initialize.h \
           ../include/myfft_N_terminate.h \
           ../include/polyfit.h \
           ../include/plotset.h \
           ../include/rt_nonfinite.h \
           ../include/rtGetInf.h \
           ../include/rtGetNaN.h \
           ../include/rtwtypes.h \
           ../include/sensordialog.h \
           ../include/triggermodedialog.h \

SOURCES += ../source/channeldialog.cpp \
           ../source/channeltabbar.cpp \                  
           ../source/channeltabwidget.cpp \
           ../source/DataFit.cpp \
           ../source/object.cpp \
#           ../source/DataFit_emxAPI.cpp \
#           ../source/DataFit_emxutil.cpp \
           ../source/DataFit_initialize.cpp \
           ../source/DataFit_terminate.cpp \
           ../source/demarcate.cpp \
           ../source/demarcatedialog.cpp \
           ../source/fftdialog.cpp \
           ../source/main.cpp\
           ../source/mainwindow.cpp\
           ../source/mmtimer.cpp \
           ../source/MT_emxAPI.cpp \
           ../source/MT_emxutil.cpp \
           ../source/myfft_N.cpp \
           ../source/myfft_N_initialize.cpp \
           ../source/myfft_N_terminate.cpp \
           ../source/polyfit.cpp \
           ../source/plotset.cpp \
           ../source/rt_nonfinite.cpp \
           ../source/rtGetInf.cpp \
           ../source/rtGetNaN.cpp \
           ../source/sensordialog.cpp \
           ../source/triggermodedialog.cpp \
       

FORMS    += ../ui/channel_dialog.ui \
            ../ui/channel_tab.ui \
            ../ui/demarcate.ui \
            ../ui/demarcate_dialog.ui \
            ../ui/fft_dialog.ui \
            ../ui/mainwindow.ui \
            ../ui/sensor_dialog.ui \ 
            ../ui/trigger_mode.ui \        

LIBS +=  ../lib/CyAPI.lib

RESOURCES += \
    ../icon/main.qrc
