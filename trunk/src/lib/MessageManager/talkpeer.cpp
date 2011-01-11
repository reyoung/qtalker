#include "talkpeer.h"
#include "rawtalkdata.h"
using namespace MessageManager;
TalkPeer::TalkPeer(QTcpSocket* sock,QObject *parent) :
    QThread(parent),m_socket(sock)
{
}

void MessageManager::TalkPeer::run()
{
    this->connect(this->m_socket,SIGNAL(readyRead()),this,SLOT(peerReadyRead()));
    this->connect(this->m_socket,SIGNAL(aboutToClose()),this,SLOT(quit()));
    this->exec();
}

void MessageManager::TalkPeer::peerReadyRead()
{
    RawTalkData data;
    data.Data = this->m_socket->readAll();
    data.Source = this->m_socket->peerAddress();
    data.Port = this->m_socket->peerPort();
    emit messageRecieved(data);
}

bool TalkPeer::isAddressMatched(const QHostAddress &addr,quint16 port) const
{
    return this->m_socket->peerAddress() == addr&& this->m_socket->peerPort() == port;
}

void MessageManager::TalkPeer::writeData(const MessageManager::RawTalkData &data)
{
    if(this->isAddressMatched(data.Source,data.Port))
    {
        this->m_socket->write(data.Data);
    }
}
