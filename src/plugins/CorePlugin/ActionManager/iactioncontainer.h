#ifndef IACTIONCONTAINER_H
#define IACTIONCONTAINER_H
#include <QtCore>
#include <QtGui>
#include "../uniqueidmanager.h"

namespace CorePlugin
{
    class Action;
    class ID;
    class ActionManager;
    class MenuActionContainer;
    class IActionContainer
    {
        Q_DISABLE_COPY(IActionContainer)
        friend class ActionManager;
        friend class MenuActionContainer;
        IActionContainer(const ID& id):m_id(id){}
    public:
        virtual QMenu* menu(){return 0;}
        virtual QMenuBar* menubar(){return 0;}
        virtual bool isMenu(){return this->menu()!=0;}
        virtual bool isMenuBar(){return this->menubar()!=0;}
        virtual void insertAction(Action* act,const ID& before = ID()) =0;
        virtual void insertContainer(IActionContainer* menu
                                          ,const ID& before = ID()) =0;
        virtual ID getID()const{return m_id;}
    protected:
        ID m_id;
    };
}
#endif // IACTIONCONTAINER_H
