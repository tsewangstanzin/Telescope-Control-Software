#-------------------------------------------------
#
# Project created by QtCreator 2020-01-28T09:59:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = threadingex
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    infinitecountworker.cpp \
    countworker.cpp

HEADERS += \
        mainwindow.h \
    infinitecountworker.h \
    countworker.h \
    portablesleep.h \
    ../TCS -test/slamac.h \
    ../TCS -test/slamac.h \
    slalib.h \
    slamac.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


DISTFILES +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../lib/release/ -lsla
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../lib/debug/ -lsla
else:unix: LIBS += -L$$PWD/../../../../../lib/ -lsla

INCLUDEPATH += $$PWD/../../../../../
DEPENDPATH += $$PWD/../../../../../

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../lib/release/libsla.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../lib/debug/libsla.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../lib/release/sla.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../lib/debug/sla.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../lib/libsla.a

