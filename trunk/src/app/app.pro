include(../globalconst.pri)
include(../../qtalker.pri)

INCLUDEPATH += $$ProjectRoot/src/lib
LIBS += -L$$ProjectRoot/bin
LIBS += -lExtensionSystem

#CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
BinDest= $$ProjectRoot/bin
DESTDIR = $$BinDest


QT += gui core xml network

SOURCES += \
    main.cpp
