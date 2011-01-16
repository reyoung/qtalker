#-------------------------------------------------
#
# Project created by QtCreator 2011-01-09T10:28:59
#
#-------------------------------------------------

QT       += xml gui network multimedia
include(../plugin.pri)

TARGET = HelloWorldPlugin
TEMPLATE = lib

DEFINES += HELLOWORLDPLUGIN_LIBRARY
INCLUDEPATH += $$ProjectRoot/src/plugins/CorePlugin
LIBS += -L$$PluginDest
LIBS += -lCorePlugin
LIBS += -lMessage
LIBS += -lNetwork
LIBS += -lAudioDevice


SOURCES += \
    helloworldplugin.cpp \
    testhellomessage.cpp

HEADERS +=\
        HelloWorldPlugin_global.h \
    helloworldplugin.h \
    hellopage.h \
    testhellomessage.h
