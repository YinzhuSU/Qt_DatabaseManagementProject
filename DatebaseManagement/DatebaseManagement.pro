#-------------------------------------------------
#
# Project created by QtCreator 2018-06-26T17:31:43
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DatebaseManagement
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mywidget.cpp \
    loginwidget.cpp \
    signupwidget.cpp \
    mainviewwidget.cpp

HEADERS += \
        mywidget.h \
    loginwidget.h \
    signupwidget.h \
    mainviewwidget.h

FORMS += \
        mywidget.ui \
    loginwidget.ui \
    signupwidget.ui \
    mainviewwidget.ui

DISTFILES += \
    Instructions.java \
    Bugs_and_problems.java \
    Achieved Functions.txt \
    Achieved Functions.txt

CONFIG += C++11
