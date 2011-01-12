#include "uniqueidmanager.h"

using namespace CorePlugin;
#include <ExtensionSystem/pluginmanager.h>

UniqueIDManager* UniqueIDManager::m_instance = 0;
void UniqueIDManager::init() {
    static UniqueIDManager manager;
    m_instance = &manager;
}


UniqueIDManager::UniqueIDManager() {
//m_instance = this;
}


UniqueIDManager::~UniqueIDManager() {
    m_instance = 0;
}


bool UniqueIDManager::hasUID(const ID &id) {
    return this->m_uids.contains(id);
}


int UniqueIDManager::getUID(const ID &id) {
    return this->m_uids.value(id);
}


QString UniqueIDManager::uidToString(const int i) {
    return this->m_uids.key(i).m_data;
}


void UniqueIDManager::insertUID(const ID &id) {
    if (this->hasUID(id)) {
        qWarning() << QObject::tr("Already Have ID %1").arg(id);
        return;
    }

    else
        this->m_uids.insert(id, qHash(id));
}
