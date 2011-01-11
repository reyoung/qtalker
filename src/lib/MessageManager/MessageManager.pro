#-------------------------------------------------
#
# Project created by QtCreator 2011-01-11T17:05:46
#
#-------------------------------------------------
include(../../library.pri)
QT       += network

QT       -= gui

TARGET = MessageManager
TEMPLATE = lib

DEFINES += COMMANDMANAGER_LIBRARY

SOURCES += \
    talkserver.cpp \
    talkpeer.cpp \
    manager.cpp

HEADERS +=\
        MessageManager_global.h \
    const.h \
    talkserver.h \
    talkpeer.h \
    rawtalkdata.h \
    manager.h \
    imessage.h \
    messages/localuserbroadcast.h

symbian {
    #Symbian specific definitions
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEEAC793C
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = CommandManager.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/local/lib
    }
    INSTALLS += target
}
