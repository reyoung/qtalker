#include <QApplication>
#include <QtCore>
#include <pluginmanager.h>
int main(int argc, char** argv) {
    QApplication app(argc, argv);

    ExtensionSystem::PluginManager* pluginManager
    = ExtensionSystem::PluginManager::instance();
    Q_UNUSED(pluginManager);
    return app.exec();
}
