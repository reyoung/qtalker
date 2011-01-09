#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H

#include <QtCore>
#include <QObject>
#include "../CorePlugin_global.h"
namespace CorePlugin
{
    class Action;
    class ID;
    class COREPLUGINSHARED_EXPORT ActionManager
    {
        Q_DISABLE_COPY(ActionManager)
    public:
        ActionManager();
        static ActionManager* instance(){return 0;}
        Action* getAction(const ID& id){return 0;}

    };
}
#endif // ACTIONMANAGER_H
