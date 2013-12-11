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
        mainwindow.cpp \
    addstudentdialog.cpp \
    addvisitdialog.cpp \
    adddiagnosisdialog.cpp \
    adddoctordialog.cpp \
    addfacultydialog.cpp \
    addgroupdialog.cpp

HEADERS  += mainwindow.h \
    connection.h \
    addstudentdialog.h \
    addvisitdialog.h \
    adddiagnosisdialog.h \
    adddoctordialog.h \
    addfacultydialog.h \
    addgroupdialog.h

FORMS    += mainwindow.ui \
    addstudentdialog.ui \
    addvisitdialog.ui \
    adddiagnosisdialog.ui \
    adddoctordialog.ui \
    addfacultydialog.ui \
    addgroupdialog.ui
