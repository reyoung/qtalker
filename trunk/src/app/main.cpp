#include <QApplication>
#include <QtCore>
#include <ExtensionSystem/pluginmanager.h>
#include <MessageManager/manager.h>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    MessageManager::Manager::init();

    ExtensionSystem::PluginManager* pluginManager
    = ExtensionSystem::PluginManager::instance();

    Q_UNUSED(pluginManager);

    return app.exec();
}
