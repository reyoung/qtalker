#ifndef MENUBARACTIONCONTAINER_H
#define MENUBARACTIONCONTAINER_H

#include <QMenuBar>
#include "iactioncontainer.h"
#include "actionmanager.h"

namespace CorePlugin {
class MenuBarActionContainer : public QMenuBar,public IActionContainer {
    Q_OBJECT
    Q_DISABLE_COPY(MenuBarActionContainer);
//    Q_INTERFACES(IActionContainer)
    friend class ActionManager;

public:
    explicit MenuBarActionContainer(const ID& id,QWidget *parent = 0);
    virtual QMenuBar* menubar();
    virtual void insertAction(Action* act,const ID& before = ID()) ;
    virtual void insertContainer(IActionContainer* menu
                                 ,const ID& before = ID()) ;
signals:

public slots:

};
}
#endif                                            // MENUBARACTIONCONTAINER_H
