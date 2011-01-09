#ifndef ACTION_H
#define ACTION_H

#include <QAction>
#include "../uniqueidmanager.h"
namespace CorePlugin
{
    class Action : public QAction
    {
        Q_OBJECT
        Q_DISABLE_COPY(Action)
        friend class ActionManager;
    private:
        explicit Action(const ID& id,QWidget *parent = 0);
    public:
        ID getID()const {return m_id;}

    public slots:
    private:
        ID m_id;

    };
}
#endif // ACTION_H
