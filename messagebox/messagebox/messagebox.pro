#-------------------------------------------------
#
# Project created by QtCreator 2015-11-29T17:30:36
#
#-------------------------------------------------

QT       -= gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += quick

TARGET = messagebox
TEMPLATE = lib

DEFINES += MESSAGEBOX_LIBRARY

SOURCES += messagebox.cpp

HEADERS += messagebox.h\
        messagebox_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

RESOURCES += \
    qrc.qrc
