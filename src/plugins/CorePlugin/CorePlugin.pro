#-------------------------------------------------
#
# Project created by QtCreator 2011-01-09T11:48:59
#
#-------------------------------------------------

QT       += xml
include(../plugin.pri)
TARGET = CorePlugin
TEMPLATE = lib

DEFINES += COREPLUGIN_LIBRARY

SOURCES += \
    plugin.cpp \
    core.cpp \
    uniqueidmanager.cpp \
    ActionManager/menuactioncontainer.cpp \
    ActionManager/actionmanager.cpp \
    ActionManager/action.cpp

HEADERS +=\
        CorePlugin_global.h \
    plugin.h \
    core.h \
    uniqueidmanager.h \
    ActionManager/iactioncontainer.h \
    ActionManager/menuactioncontainer.h \
    ActionManager/actionmanager.h \
    ActionManager/action.h
