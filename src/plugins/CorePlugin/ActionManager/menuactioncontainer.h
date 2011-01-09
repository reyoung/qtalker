#ifndef MENUACTIONCONTAINER_H
#define MENUACTIONCONTAINER_H

#include <QMenu>
#include "iactioncontainer.h"
namespace CorePlugin
{
class MenuActionContainer : public QMenu,public IActionContainer
{
    Q_OBJECT
    Q_DISABLE_COPY(MenuActionContainer)
public:
    explicit MenuActionContainer(const ID& id,QWidget *parent = 0);
    virtual QMenu* menu();
    virtual void insertAction(Action* act,const ID& before = ID());
    virtual void insertContainer(IActionContainer* menu
                                      ,const ID& before = ID());
signals:

public slots:

};
}
#endif // MENUACTIONCONTAINER_H
