#ifndef TALKSERVER_H
#define TALKSERVER_H

#include <QTcpServer>
#include "MessageManager_global.h"
#include "talkpeer.h"
#include <QtCore>

namespace MessageManager
{
class MESSAGEMANAGERSHARED_EXPORT TalkServer : public QTcpServer
{
    Q_OBJECT
    explicit TalkServer(QObject *parent = 0);

public:
    static TalkServer* instance();
    virtual ~TalkServer();
signals:
    void messageRecieved(RawTalkData d);
public slots:
    void writeRawData(const RawTalkData& data);
private slots:
    void peerConnected();
    void addPeerSocket(QTcpSocket* socket);
private:
    QList<TalkPeer* > m_peers;

    void createPeerBySocket(QTcpSocket* sock);
};
}
#endif // TALKSERVER_H
