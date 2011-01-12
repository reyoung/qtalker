#ifndef TCPTHREAD_H
#define TCPTHREAD_H
#include "sendthread.h"
#include <QtNetwork>
#include <QtCore>
#include "Network_global.h"
namespace Network
{
class NETWORKSHARED_EXPORT TcpThread : public SendThread
{
    Q_OBJECT
public:
    explicit TcpThread(QObject *parent = 0);
    virtual SendReturned send(const RawData& barray);
    virtual bool listen(quint16 port);
signals:

public slots:
private slots:
    void arravedConnection();
    void auxSend();
    void rawMsgRecv();
private:
    QTcpServer* m_server;
    QVector<QTcpSocket*> m_sock_list;
    QHash<QTcpSocket* , QByteArray > m_wait_send_datas;
};
}
#endif // TCPTHREAD_H
