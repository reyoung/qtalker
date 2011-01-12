include(../globalconst.pri)
include(../../qtalker.pri)
PluginDest = $$ProjectRoot/bin/plugin
DESTDIR = $$PluginDest
INCLUDEPATH += $$ProjectRoot/src/lib
INCLUDEPATH += $$ProjectRoot/src/plugins
LIBS += -L$$ProjectRoot/bin
LIBS += -lExtensionSystem
PLUGINSPEC = $$_PRO_FILE_PWD_/$${TARGET}.pluginspec
pluginspec.files += $${TARGET}.pluginspec
pluginspec.path = /$$ProjectRoot/qtcreator/plugins
INSTALLS += target pluginspec
