#include "actionmanager.h"
#include "../uniqueidmanager.h"
#include "menuactioncontainer.h"
#include "menubaractioncontainer.h"
#include "action.h"
using namespace CorePlugin;
ActionManager* ActionManager::m_instance = 0;
ActionManager::ActionManager() {
}


MenuActionContainer* ActionManager::createMenu(const ID &id) {
    if (UniqueIDManager::instance()->hasUID(id)) {
        qWarning()<<QObject::tr("%1 UID Already Have").arg(id);
        return 0;
    }
    UniqueIDManager::instance()->insertUID(id);
    MenuActionContainer* container = new MenuActionContainer(id,0);
    this->m_containers.insert(
        UniqueIDManager::instance()->getUID(id),
        container
    );
    return container;
}


MenuBarActionContainer* ActionManager::createMenuBar(const ID &id) {
    if (UniqueIDManager::instance()->hasUID(id)) {
        qWarning()<<QObject::tr("%1 UID Already Have").arg(id);
        return 0;
    }
    UniqueIDManager::instance()->insertUID(id);
    MenuBarActionContainer* container = new MenuBarActionContainer(id,0);
    this->m_containers.insert(
        UniqueIDManager::instance()->getUID(id),
        container
    );
    return container;
}


void ActionManager::init() {
    static ActionManager man;
    m_instance= &man;
}


Action* ActionManager::createAction(const ID &id) {
    UniqueIDManager* man = UniqueIDManager::instance();
    if (man->hasUID(id)) {
        qWarning()<<QObject::tr("%1 UID Already Have").arg(id);
        return 0;
    }
    man->insertUID(id);
    Action* act = new Action(id);
    this->m_actions.insert(
        man->getUID(id),
        act
    );
    return act;
}


Action* CorePlugin::ActionManager::getAction( const ID& id ) {
    return this->m_actions.value(UniqueIDManager::instance()->getUID(id));

}


IActionContainer* CorePlugin::ActionManager::getContainer( const ID& id) {
    return this->m_containers.value(UniqueIDManager::instance()->getUID(id));
}
