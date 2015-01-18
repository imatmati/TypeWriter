#-------------------------------------------------
#
# Project created by QtCreator 2015-01-18T15:20:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TypeWriter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pageeditor.cpp

HEADERS  += mainwindow.h \
    pageeditor.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11

RESOURCES += \
    background.qrc
