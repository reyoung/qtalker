#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QObject>
#include "ExtensionSystem_global.h"
#include "pluginspec.h"
#include <QtCore>

class QDir;

namespace ExtensionSystem {

class EXTENSIONSYSTEMSHARED_EXPORT PluginManager : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(PluginManager)
    explicit PluginManager();
    virtual ~PluginManager();
public:
    static PluginManager* instance();
    void addObject(QObject* object);

signals:

public slots:
private slots:
    void aboutToClose();
private:
    QList<PluginSpec> m_specs;
    QList<QObject* > m_objList;

    void LoadPluginSpec(const QDir& dir);
    void LoadAllPlugin();
};
}

#endif                                            // PLUGINMANAGER_H
