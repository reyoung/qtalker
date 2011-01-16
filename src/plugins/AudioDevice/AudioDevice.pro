#-------------------------------------------------
#
# Project created by QtCreator 2011-01-14T18:04:56
#
#-------------------------------------------------

QT       += multimedia
include(../plugin.pri)
QT       -= gui

TARGET = AudioDevice
TEMPLATE = lib

DEFINES += AUDIODEVICE_LIBRARY

SOURCES += \
    plugin.cpp \
    audiooutput.cpp \
    audioinput.cpp \
    audioemitter.cpp

HEADERS +=\
        AudioDevice_global.h \
    plugin.h \
    audiooutput.h \
    audioinput.h \
    audioemitter.h \
    iaudiofilter.h

symbian {
    #Symbian specific definitions
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEF2CE627
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = AudioDevice.dll
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
