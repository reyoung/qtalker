#include "menuactioncontainer.h"
#include "actionmanager.h"
#include "action.h"
#include <QtCore>
#include <QtDebug>

using namespace CorePlugin;

MenuActionContainer::MenuActionContainer(const ID& id, QWidget *parent) :
        QMenu(parent), IActionContainer(id) {
}


QMenu* MenuActionContainer::menu() {
    return qobject_cast<QMenu* > (this);
}


void MenuActionContainer::insertAction(Action *act, const ID &before) {
    if (before.isValid()) {
        QMenu* menu = qobject_cast<QMenu* > (this);
        Action * bact = ActionManager::instance()->getAction(before);

        if (bact == 0) {
            qWarning() << tr("%1 not exist").arg(before);
        }

        else {
            menu->insertAction(bact
                               , qobject_cast<QAction*> (act));
        }
    }

    else {
        this->addAction(qobject_cast<QAction*> (act));
    }
}


void MenuActionContainer::insertContainer(IActionContainer *menu, const ID &before) {
    if (menu->isMenu()) {
        if (before.isValid()) {
            Action* act = ActionManager::instance()->getAction(before);

            if (act == 0) {
                qWarning() << tr("%1 Not exist").arg(before);
            }

            else {
                this->insertMenu(act, menu->menu());
            }
        }

        else {
            qWarning() << tr("%1 : Try Insert a menubar").arg(menu->getID());
        }
    }
}
