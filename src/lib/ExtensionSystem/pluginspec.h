#ifndef PLUGINSPEC_H
#define PLUGINSPEC_H

#include <QObject>
#include <QtCore>
#include "ExtensionSystem_global.h"
namespace ExtensionSystem
{
    struct PluginSpecInnerData;
    struct SpecDependencyData
    {
        QString Name;
        QString Version;
    };

    class EXTENSIONSYSTEMSHARED_EXPORT PluginSpec : public QObject
    {
        Q_OBJECT
    public:

        explicit PluginSpec(const QString& fn,QObject *parent = 0);
        virtual ~PluginSpec();
    signals:

    private:
        PluginSpecInnerData* m_data;
    };
}
#endif // PLUGINSPEC_H
