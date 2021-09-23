#-------------------------------------------------
#
# Project created by QtCreator 2015-04-02T14:11:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EK_Thread_01
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    mythread.cpp

HEADERS  += dialog.h \
    mythread.h \
    readme.h

FORMS    += dialog.ui
