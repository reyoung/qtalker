#include "rawdata.h"


Network::RawData::RawData(const QHostAddress &addr, quint16 port, const QByteArray &barray)
    :Data(barray),m_port(port),m_addr(addr)
{
}

quint16 Network::RawData::getPort() const
{
    return this->m_port;
}

QHostAddress Network::RawData::getAddress() const
{
    return this->m_addr;
}
