#-------------------------------------------------
#
# Project created by QtCreator 2011-01-12T16:38:34
#
#-------------------------------------------------

include(../plugin.pri)
QT       += network

QT       -= gui

TARGET = Network
TEMPLATE = lib

DEFINES += NETWORK_LIBRARY

SOURCES += \
    plugin.cpp \
    sendthread.cpp \
    rawdata.cpp \
    udpthread.cpp

HEADERS +=\
        Network_global.h \
    plugin.h \
    sendthread.h \
    rawdata.h \
    udpthread.h

symbian {
    #Symbian specific definitions
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE9F34785
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = Network.dll
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
