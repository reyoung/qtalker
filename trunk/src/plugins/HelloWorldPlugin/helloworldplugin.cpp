#include "helloworldplugin.h"
#include <QDebug>
#include <QtPlugin>
#include <QtGui>
HelloWorldPlugin::HelloWorldPlugin() :
    ExtensionSystem::IPlugin()
{
}
bool HelloWorldPlugin::Initialize(QStringList& cmdArgs)
{
    Q_UNUSED(cmdArgs);
    //qDebug()<<"Hello world";
    QLabel* lab = new QLabel("Hello world");
    this->addAutoReleaseObject(lab);
    lab->show();
    return true;
}
Q_EXPORT_PLUGIN2(HelloWorldPlugin,HelloWorldPlugin)
