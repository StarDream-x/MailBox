QT       += core gui sql core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

include(3rdparty/qtmail/src/mail/qtmail.pri)

TEMPLATE = app
TARGET = pop3
INCLUDEPATH += .

TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp
HEADERS += mainwindow.h
FORMS += mainwindow.ui
