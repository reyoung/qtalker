#ifndef TALKPEER_H
#define TALKPEER_H

#include <QThread>
#include <QTcpSocket>
#include "rawtalkdata.h"
#include "MessageManager_global.h"
namespace MessageManager
{
class MESSAGEMANAGERSHARED_EXPORT TalkPeer : public QThread
{
    Q_OBJECT
public:
    explicit TalkPeer(QTcpSocket* sock,QObject *parent = 0);
    bool isAddressMatched(const QHostAddress& addr,quint16 port)const ;
    void writeData(const RawTalkData& data);
signals:
    void messageRecieved(RawTalkData data);
protected:
    virtual void run();
private slots:
    void peerReadyRead();
private:
    QTcpSocket* m_socket;
};
}
#endif // TALKPEER_H
