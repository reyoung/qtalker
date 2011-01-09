#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H

#include <QtCore>
#include <QObject>
#include "../CorePlugin_global.h"
#include "iactioncontainer.h"
#include <QHash>
namespace CorePlugin
{
    class Action;
    class ID;
    class COREPLUGINSHARED_EXPORT ActionManager
    {
        ActionManager();
        Q_DISABLE_COPY(ActionManager)
    public:
        static ActionManager* instance(){return m_instance;}
        Action* getAction(const ID& id){return 0;}
        IActionContainer* getContainer(const ID&) {return 0;}
        static void init();
        IActionContainer* createMenu(const ID& id);
        IActionContainer* createMenuBar(const ID& id);
        Action* createAction(const ID& id);
    private:
        static ActionManager* m_instance;
        QHash<int,Action*> m_actions;
        QHash<int,IActionContainer*> m_containers;

    };
}
#endif // ACTIONMANAGER_H
