#include "menubaractioncontainer.h"
#include "actionmanager.h"
#include <QtDebug>
#include "action.h"
#include "menuactioncontainer.h"
using namespace CorePlugin;
MenuBarActionContainer::MenuBarActionContainer(const ID& id,QWidget *parent) :
    QMenuBar(parent),IActionContainer(id)
{
}
QMenuBar* MenuBarActionContainer::menubar()
{
    return qobject_cast<QMenuBar* >(this);
}
void MenuBarActionContainer::insertAction(Action *act, const ID &before)
{
    QMenuBar* mb = this->menubar();
    if(before.isValid())
    {
        Action* before_act = ActionManager::instance()->getAction(before);
        if(before_act==0)
        {
            qWarning()<<tr("%1 Insert Action Err").arg(before);
            return;
        }
        else
        {
            mb->insertAction( qobject_cast<QAction*>(before_act)
                              ,qobject_cast<QAction*>(act));
        }
    }
    else
    {
        this->addAction(qobject_cast<QAction*>(act));
    }
}

void MenuBarActionContainer::insertContainer(IActionContainer *menu, const ID &before)
{
    bool err = false;
    if(menu->isMenu())
    {
        MenuActionContainer* m = (MenuActionContainer* )menu;
        if(before.isValid())
        {
            Action* act = ActionManager::instance()->getAction(before);
            IActionContainer* cont = ActionManager::instance()->getContainer(before);
            if(act)
            {
               this->insertMenu(act,m);
            }
            else if(cont&&cont->isMenu())
            {
                MenuActionContainer* bm = (MenuActionContainer*)cont;
                this->insertMenu(bm->menuAction(),m);
            }
            else
            {
                err = true;
            }
        }
        else
        {
            this->addMenu(m);
        }

    }
    else
    {
        err = true;
    }
    if(err)
    {
        qWarning()<<"Error";
    }
}
