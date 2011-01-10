#ifndef IPLUGIN_H
#define IPLUGIN_H

#include <QObject>
#include "ExtensionSystem_global.h"
#include "pluginspec.h"
#include <QtCore>

namespace ExtensionSystem {

class EXTENSIONSYSTEMSHARED_EXPORT IPlugin : public QObject {
    Q_OBJECT
public:
    enum ShutdownFlag {
        SynchronousShutdown,
        AsynchronousShutdown
    };

    virtual bool Initialize(const QStringList& cmdArgs) = 0;
    virtual void Initialized() {}

    explicit IPlugin();

    const PluginSpec* getSpec() const;

    void addAutoReleaseObject(QObject* obj);

    virtual ~IPlugin();

    virtual ShutdownFlag aboutShutDown();

signals:
    void asynchronousShutdownFinished();
private:
    void setSpec(const PluginSpec * ptr);
    const PluginSpec * m_spec;
    QList<QObject*> m_objList;

    friend class PluginManager;
};
}

#endif                                            // IPLUGIN_H
