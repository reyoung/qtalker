#-------------------------------------------------
#
# Project created by QtCreator 2011-01-12T14:22:06
#
#-------------------------------------------------

QT       -= gui
include(../plugin.pri)
TARGET = Message
TEMPLATE = lib

DEFINES += MESSAGEMANAGER_LIBRARY

HEADERS +=\
        MessageManager_global.h \
    plugin.h \
    imessage.h

SOURCES += \
    plugin.cpp \
    imessage.cpp
