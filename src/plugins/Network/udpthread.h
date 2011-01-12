#ifndef UDPTHREAD_H
#define UDPTHREAD_H
#include "sendthread.h"
#include "Network_global.h"
#include <QtNetwork>
namespace Network
{
class NETWORKSHARED_EXPORT UdpThread : public SendThread
{
    Q_OBJECT
public:
    explicit UdpThread(QObject *parent = 0);
    virtual SendReturned send(const RawData& barray);
    virtual bool listen(quint16 port);
    void broadcast(const QByteArray& barray,quint16 port);
protected:
    void run();
private slots:
    void rawDataRecieved();
private:
    QUdpSocket* m_socket;
};
}
#endif // UDPTHREAD_H
