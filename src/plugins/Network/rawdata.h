#ifndef RAWDATA_H
#define RAWDATA_H
#include "Network_global.h"
#include <QtNetwork>
namespace Network
{
class NETWORKSHARED_EXPORT RawData
{
    friend class SendThread;
    friend class UdpThread;
    RawData(){}
public:
    RawData(const QHostAddress& addr,quint16 port,const QByteArray& barray);
    quint16 getPort()const;
    QHostAddress getAddress()const;
    QByteArray Data;
private:
    quint16 m_port;
    QHostAddress m_addr;

};
}
#endif // RAWDATA_H
