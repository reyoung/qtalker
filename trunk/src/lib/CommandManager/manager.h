#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QtCore>
#include <QtNetwork>
#include "MessageManager_global.h"
#include "const.h"
#include "messages/localuserbroadcast.h"

namespace MessageManager
{
class TalkServer;
class LocalUserBroadCast;
class MESSAGEMANAGERSHARED_EXPORT Manager : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Manager)
    explicit Manager(QObject *parent = 0);

public:
    static Manager* instance();
    static TalkServer* getServer();

    static void init();
signals:
    void localOnline(LocalUserBroadCast bm);
public slots:
    void refreshLocalOnline();
private slots:
    void udpDataRecieved();
private:
    static Manager* m_instance;
    QTimer* m_queryTimer;
    QUdpSocket* m_udp;
};
}
#endif // MANAGER_H
