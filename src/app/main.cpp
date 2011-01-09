#include <QApplication>
#include <QtCore>
#include <pluginmanager.h>
int main(int argc,char** argv) {
    QApplication app(argc,argv);

    ExtensionSystem::PluginManager* pluginManager
    =ExtensionSystem::PluginManager::instance();

    return app.exec();
}
