#ifndef ACTION_H
#define ACTION_H

#include <QAction>
namespace CorePlugin
{
    class Action : public QAction
    {
        Q_OBJECT
    public:
        explicit Action(QWidget *parent = 0);

    signals:

    public slots:

    };
}
#endif // ACTION_H
