include(../globalconst.pri)
include(../../qtalker.pri)
LibDest = $$ProjectRoot/bin/plugin
DESTDIR = $$LibDest
INCLUDEPATH += $$ProjectRoot/src/lib/ExtensionSystem
LIBS += -L$$ProjectRoot/bin
LIBS += -lExtensionSystem
