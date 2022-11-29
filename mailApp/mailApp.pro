QT       += core gui sql core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

UI_DIR = ./UI

include(3rdparty/qtmail/src/mail/qtmail.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
#    home.cpp \
    MySmtp.cpp \
    login.cpp \
    mail.cpp \
    main.cpp \
    qhome.cpp \
    qsend.cpp \
    user.cpp

HEADERS += \
#    home.h \
    MySmtp.h \
    login.h \
    mail.h \
    qhome.h \
    qsend.h \
    user.h

FORMS += \
#    home.ui \
    failLogin.ui \
    login.ui \
    qhome.ui \
    qsend.ui \
    successLogin.ui \
    receiving.ui
#    sending.ui

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc
