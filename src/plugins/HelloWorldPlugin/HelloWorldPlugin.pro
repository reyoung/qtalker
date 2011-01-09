#-------------------------------------------------
#
# Project created by QtCreator 2011-01-09T10:28:59
#
#-------------------------------------------------

QT       += xml
include(../plugin.pri)

TARGET = HelloWorldPlugin
TEMPLATE = lib

DEFINES += HELLOWORLDPLUGIN_LIBRARY

SOURCES += \
    helloworldplugin.cpp

HEADERS +=\
        HelloWorldPlugin_global.h \
    helloworldplugin.h
