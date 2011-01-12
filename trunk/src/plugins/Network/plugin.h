#ifndef PLUGIN_H
#define PLUGIN_H

#include <QObject>
#include <ExtensionSystem/iplugin.h>
#include "Network_global.h"

namespace Network
{
class NETWORKSHARED_EXPORT Plugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
public:
    bool Initialize(const QStringList& cmdArgs);
signals:

public slots:

};
}
#endif // PLUGIN_H
