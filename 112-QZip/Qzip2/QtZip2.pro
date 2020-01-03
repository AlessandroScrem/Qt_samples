#-------------------------------------------------
#
# Project created by QtCreator 2014-01-20T11:41:45
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = QtZip2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

LIBDIR += $$PWD/../Libs
INCLUDEPATH += $${LIBDIR}


unix {
    LIBS += -L$${LIBDIR} -lz
}

win32 {
    LIBS += -L$${LIBDIR} -lzlibwapi
}

SOURCES += main.cpp \
    zip.cpp

HEADERS += \
    zipreader.h \
    zipwriter.h \
    zlib.h \
    zconf.h
