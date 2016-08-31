#-------------------------------------------------
#
# Project created by QtCreator 2016-08-17T22:25:54
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QTPLUGIN += qtvirtualkeyboard
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Counteract
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    global.cpp

HEADERS  += mainwindow.h \
    global.h

FORMS    += mainwindow.ui
