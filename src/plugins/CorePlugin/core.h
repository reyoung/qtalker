#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <QtCore>
#include <QSystemTrayIcon>
#include "CorePlugin_global.h"

namespace CorePlugin
{
    class UniqueIDManager;
    class COREPLUGINSHARED_EXPORT Core : public QObject
    {
        Q_OBJECT
        Q_DISABLE_COPY(Core)
        explicit Core(QObject *parent = 0);
        enum{
            DebugFlag = 1
        };
    public:

        static Core* instance();
        static UniqueIDManager* uidManager();
        static bool init(const QStringList& cmdArgs);
    signals:

    public slots:
    private:
        static Core* m_instance;
    };
}
#endif // CORE_H
