#ifndef PLUGIN_H
#define PLUGIN_H

#include <QObject>
#include <iplugin.h>
#include "CorePlugin_global.h"
namespace CorePlugin {
class COREPLUGINSHARED_EXPORT Plugin : public ExtensionSystem::IPlugin {
    Q_OBJECT
public:
    explicit Plugin();
    virtual bool Initialize(const QStringList& cmdArgs);
    virtual void Initialized();
signals:

public slots:

};
}
#endif                                            // PLUGIN_H
