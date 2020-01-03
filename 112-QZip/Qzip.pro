QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

#Set variables
QUAZIP_SRCDIR = $$PWD/quazip-0.8.1/quazip
ZLIBDIR = $$PWD/Libs

unix {
    LIBS += -L$${ZLIBDIR} -lz
}
win32 {
    CONFIG(release, debug|release): LIBS += -L$${ZLIBDIR} -lquazip
    CONFIG(debug, debug|release): LIBS += -L$${ZLIBDIR} -lquazipd
    DEFINES += NOMINMAX
}

#include files
INCLUDEPATH += $${QUAZIP_SRCDIR}
HEADERS += $${QUAZIP_SRCDIR}/JlCompress.h
SOURCES += \
        main.cpp

# target:
#         |_/build
#           |_/release
#           |_/debug
#
#    CONFIG(debug, debug|release) {
#        DESTDIR = $$PWD/build/debug
#    }
#    CONFIG(release, debug|release) {
#        DESTDIR = $$PWD/build/release
#    }
#    OBJECTS_DIR = $$DESTDIR/.obj
#    MOC_DIR = $$DESTDIR/.moc
#    RCC_DIR = $$DESTDIR/.qrc
#    UI_DIR = $$DESTDIR/.u


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
