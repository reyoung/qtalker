#ifndef PLUGIN_H
#define PLUGIN_H

#include <QObject>
#include <ExtensionSystem/iplugin.h>
#include <QtPlugin>
namespace Message
{
class Plugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
public:
    virtual bool Initialize(const QStringList& cmdArgs){
        Q_UNUSED(cmdArgs);
        return true;
    }

signals:

public slots:

};

}

#endif // PLUGIN_H
