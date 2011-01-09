//! Action File Class.
/*!
 \author   : reyoung
 \date     : 2011/01/09
\version  :
\filepath : F:\MyOpenSource\qtalker\src\plugins\CorePlugin\ActionManager
\filename : action.h
\note     :

\attention:

\remark   : 1.2011/01/09 21:39 created by reyoung version 0.1
\History:
<author>      <time>      <version>         <desc>
*/
#ifndef ACTION_H
#define ACTION_H

#include <QAction>
#include "../uniqueidmanager.h"
namespace CorePlugin {
/// Action Used In QTalker Must Use this Class!!
class Action : public QAction {
    Q_OBJECT
    Q_DISABLE_COPY(Action)                //Disable The Copy
    friend class ActionManager;
private:
    explicit Action(const ID& id,QWidget *parent = 0);
public:

    ID getID()const {
        return m_id;
    }

public slots:
private:
    ID m_id;

};
}
#endif                                            // ACTION_H
