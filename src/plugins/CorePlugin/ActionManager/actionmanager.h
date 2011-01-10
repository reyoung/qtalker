//! Action Manager, It Can Manage QActions, QMenus QMenubars.
/*!
 \author   : Reyoung
 \date     : 2011/01/09
\version  :
\filepath : F:\MyOpenSource\qtalker\src\plugins\CorePlugin\ActionManager
\filename : actionmanager.h
\note     :

\attention:

\remark   : 1.2011/01/09 21:40 created by Reyoung version 0.1
\History:
<author>      <time>      <version>         <desc>
*/
#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H

#include <QtCore>
#include <QObject>
#include "../CorePlugin_global.h"
#include "iactioncontainer.h"
#include <QHash>

namespace CorePlugin {

class Action;

class ID;

class MenuActionContainer;

class MenuBarActionContainer;

class COREPLUGINSHARED_EXPORT ActionManager {
    ActionManager();
    Q_DISABLE_COPY(ActionManager)
public:
    static ActionManager* instance() {
        return m_instance;
    }

    Action* getAction(const ID& id);
    IActionContainer* getContainer(const ID&);

//! Before Use It, Must Init!.
    /*!
     \author reyoung
     \date 2011/01/09
    \version ver1.0
    \exception
    \test
    \note
    \attention
    \sa
    \remark 1.2011/01/09 21:42 created by reyoung version
    \return
    */
    static void init();

//! The Only way U Create Menu, Use this.
    /*!
     \author reyoung
     \date 2011/01/09
    \version ver1.0
    \param id -
    \exception
    \test
    \note
    \attention
    \sa
    \remark 1.2011/01/09 21:43 created by reyoung version
    \return
    */
    MenuActionContainer* createMenu(const ID& id);

    MenuBarActionContainer* createMenuBar(const ID& id);
    Action* createAction(const ID& id);
private:
    static ActionManager* m_instance;
    QHash<int, Action*> m_actions;
    QHash<int, IActionContainer*> m_containers;

};
}

#endif                                            // ACTIONMANAGER_H
