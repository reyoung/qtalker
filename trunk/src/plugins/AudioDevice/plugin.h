#ifndef PLUGIN_H
#define PLUGIN_H

#include <QObject>
#include <ExtensionSystem/iplugin.h>
namespace AudioDevice
{
class Plugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
public:
    virtual bool Initialize(const QStringList& cmdArgs);
signals:

public slots:

};
}
#endif // PLUGIN_H
