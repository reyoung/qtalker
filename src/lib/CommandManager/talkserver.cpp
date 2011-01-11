#include "talkserver.h"
#include "const.h"
using namespace MessageManager;
TalkServer::TalkServer(QObject *parent) :
    QTcpServer(parent)
{
    int i;
    for( i=0;i<Const::PosiblePortSize;++i)
    {
        if(this->listen(QHostAddress::LocalHost,Const::PosiblePorts[i]))
            break;
    }
    if(i == Const::PosiblePortSize)
    {
        qWarning()<<"No Port Could Be Listen";
        exit(1);
    }
    this->connect(this,SIGNAL(newConnection()),this,SLOT(peerConnected()));
}
TalkServer::~TalkServer()
{
    foreach(TalkPeer* p , this->m_peers)
        p->terminate();
}




MessageManager::TalkServer * MessageManager::TalkServer::instance()
{
    static TalkServer ts;
    return &ts;
}

void MessageManager::TalkServer::peerConnected()
{
    QTcpSocket* sock = this->nextPendingConnection();
    this->createPeerBySocket(sock);
}

void MessageManager::TalkServer::writeRawData(const MessageManager::RawTalkData &data)
{
    for(QList<TalkPeer* >::iterator it = this->m_peers.begin();it!=this->m_peers.end();++it)
    {
        TalkPeer*& pptr = *it;
        pptr->writeData(data);
    }
}

void MessageManager::TalkServer::addPeerSocket(QTcpSocket *socket)
{
    socket->setParent(this);
    this->createPeerBySocket(socket);
}

void MessageManager::TalkServer::createPeerBySocket(QTcpSocket *sock)
{
    Q_ASSERT(sock);
    TalkPeer* peer = new TalkPeer(sock,this);
    this->connect(peer,SIGNAL(messageRecieved(RawTalkData)),this,SIGNAL(messageRecieved(RawTalkData)));
    peer->start(QThread::HighPriority);
    this->m_peers.append(peer);
}
