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
    ActionManager/action.cpp \
    ActionManager/menubaractioncontainer.cpp \
    widgetfactory.cpp \
    mainform.cpp \
    menubar.cpp \
    sidepage.cpp \
    sidewidget.cpp

HEADERS +=\
        CorePlugin_global.h \
    plugin.h \
    core.h \
    uniqueidmanager.h \
    ActionManager/iactioncontainer.h \
    ActionManager/menuactioncontainer.h \
    ActionManager/actionmanager.h \
    ActionManager/action.h \
    ActionManager/menubaractioncontainer.h \
    idable.h \
    widgetfactory.h \
    mainform.h \
    coreconst.h \
    menubar.h \
    sidepage.h \
    sidewidget.h

FORMS += \
    MainForm.ui \
    SideWidget.ui

OTHER_FILES +=

RESOURCES += \
    icons.qrc
