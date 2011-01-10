#ifndef IDABLE_H
#define IDABLE_H
#include "CorePlugin_global.h"
#include "uniqueidmanager.h"
#include <QtCore>

namespace CorePlugin {

class COREPLUGINSHARED_EXPORT IDAble {
public:
    IDAble(const ID& id) {
        UniqueIDManager* man = UniqueIDManager::instance();

        if (man->hasUID(id)) {
            qWarning() << QString("%1 ID Already Have").arg(id);
            return;
        }

        else {
            this->m_id = id;
            man->insertUID(id);
        }
    }

    bool isIdValid() const {
        return m_id.isValid();
    }

    int getIdNumber() const {
        UniqueIDManager* man = UniqueIDManager::instance();
        return man->getUID(m_id);
    }

    ID getID() const {
        return m_id;
    }

private:
    ID m_id;
};
}

#endif // IDABLE_H
