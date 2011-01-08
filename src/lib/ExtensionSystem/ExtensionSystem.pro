#-------------------------------------------------
#
# Project created by QtCreator 2011-01-08T20:02:38
#
#-------------------------------------------------

include(../../library.pri)
QT       += xml

TARGET = ExtensionSystem
TEMPLATE = lib

DEFINES += EXTENSIONSYSTEM_LIBRARY

SOURCES += \
    pluginspec.cpp \
    pluginmanager.cpp \
    iplugin.cpp

HEADERS +=\
        ExtensionSystem_global.h \
    pluginspec.h \
    pluginmanager.h \
    iplugin.h
