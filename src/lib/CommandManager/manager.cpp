#include "manager.h"
#include "talkserver.h"
#include "messages/localuserbroadcast.h"
using namespace MessageManager;

Manager* Manager::m_instance = 0;



Manager::Manager(QObject *parent) :
    QObject(parent)
{
    this->m_queryTimer = new QTimer(this);
    this->connect(this->m_queryTimer,SIGNAL(timeout()),this,SLOT(refreshLocalOnline()));
    this->m_queryTimer->start(Const::getLocalRefreshSec()*1000);
    this->m_udp = new QUdpSocket(this);
    this->m_udp->bind(Const::UDPPort,QUdpSocket::DefaultForPlatform);
    this->connect(this->m_udp,SIGNAL(readyRead()),this,SLOT(udpDataRecieved()));
}

MessageManager::Manager * MessageManager::Manager::instance()
{
    return m_instance;
}

void MessageManager::Manager::init()
{
    static Manager manager;
    m_instance=&manager;
    TalkServer::instance();
}

void MessageManager::Manager::refreshLocalOnline()
{
    QUdpSocket socket(this);
    LocalUserBroadCast msg;
    socket.writeDatagram(msg.toByteArray(),QHostAddress::Broadcast,Const::UDPPort);
}

MessageManager::TalkServer * MessageManager::Manager::getServer()
{
    return TalkServer::instance();
}

void MessageManager::Manager::udpDataRecieved()
{
    char buffer[32];
    int size = this->m_udp->readDatagram(buffer,32);
    QByteArray barray(buffer,size);
    LocalUserBroadCast* bm = Parse<LocalUserBroadCast>(barray);
    TalkServer* tserv = TalkServer::instance();
    if(tserv->serverAddress()!=bm->getPeerAddress()&&tserv->serverPort()!=bm->getPort())
    {
        emit localOnline(*bm);
    }
    delete bm;
}

