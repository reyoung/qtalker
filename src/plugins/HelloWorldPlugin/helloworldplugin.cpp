#include "helloworldplugin.h"
#include <QDebug>
#include <QtPlugin>

HelloWorldPlugin::HelloWorldPlugin() :
    ExtensionSystem::IPlugin()
{
}
bool HelloWorldPlugin::Initialize(QStringList& cmdArgs)
{
    Q_UNUSED(cmdArgs);
    qDebug()<<"Hello world";
    return true;
}
Q_EXPORT_PLUGIN2(HelloWorldPlugin,HelloWorldPlugin)
