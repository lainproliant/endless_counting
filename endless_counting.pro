#-------------------------------------------------
#
# Project created by QtCreator 2015-02-12T21:28:58
#
#-------------------------------------------------

QT       += core gui

CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = endless_counting
TEMPLATE = app


SOURCES += main.cpp\
        endlessmainwindow.cpp

HEADERS  += endlessmainwindow.h \
    hexgridwidget.h \
    hex.h \
    hexgridscrollarea.h \
    counting_hex.h \
    counting_hexgridwidget.h

FORMS    += endlessmainwindow.ui

RESOURCES += \
    endless.qrc
