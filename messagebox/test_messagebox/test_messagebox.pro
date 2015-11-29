#-------------------------------------------------
#
# Project created by QtCreator 2015-11-29T18:12:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_messagebox
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-messagebox-Desktop_Qt_5_5_0_MinGW_32bit-Debug/release/ -lmessagebox
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-messagebox-Desktop_Qt_5_5_0_MinGW_32bit-Debug/debug/ -lmessagebox
else:unix: LIBS += -L$$PWD/../build-messagebox-Desktop_Qt_5_5_0_MinGW_32bit-Debug/ -lmessagebox

INCLUDEPATH += $$PWD/../messagebox
DEPENDPATH += $$PWD/../build-messagebox-Desktop_Qt_5_5_0_MinGW_32bit-Debug/debug
