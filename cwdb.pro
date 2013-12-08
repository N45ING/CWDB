#-------------------------------------------------
#
# Project created by QtCreator 2013-12-08T21:40:12
#
#-------------------------------------------------

QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cwdb
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    connection.h

FORMS    += mainwindow.ui
