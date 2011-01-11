#ifndef LOCALUSERBROADCAST_H
#define LOCALUSERBROADCAST_H
#include "../imessage.h"
#include "../const.h"
#include "../talkserver.h"
#include <QtNetwork>
#include <QtCore>


namespace MessageManager
{


class MESSAGEMANAGERSHARED_EXPORT LocalUserBroadCast : public IMessage
{
private:
    QHostAddress m_addr;
    quint16 m_port;
public:
    LocalUserBroadCast():IMessage(Const::LocalUserBroadCast,Const::Response)
    {
    }
    LocalUserBroadCast(const QHostAddress& h, const quint16 port )
    :IMessage(Const::LocalUserBroadCast,Const::Response),m_addr(h),m_port(port)
    {

    }

    QHostAddress getPeerAddress()const {return m_addr;}
    quint16 getPort()const {return m_port;}



    virtual QByteArray toByteArray()
    {
        TalkServer* serv = TalkServer::instance();
        QByteArray array;
        QDataStream dout(&array,QIODevice::WriteOnly);
        dout<<serv->serverAddress()<<serv->serverPort();

        QByteArray barray =  this->appendHeader<Const::LocalUserBroadCast,Const::Response>(array);
        return barray;
    }
};
using namespace Inner;
template <>
static LocalUserBroadCast* Parse<LocalUserBroadCast>(const QByteArray& data)
{
    HeaderUnion  u;
    for(int i=0;i<4;++i)
    {
        u.Chars[i] =data[i];
    }
    u.Int>>=1;
    if(u.Int!= Const::LocalUserBroadCast)
    {
        return 0;
    }
    else
    {
        QByteArray d2 = data;
        d2.remove(0,8);
        QDataStream din(d2);
        QHostAddress addr;
        quint16 port;
        din>>addr>>port;
        qDebug()<<addr<<" "<<port;
        return new LocalUserBroadCast(addr,port);
    }
}
}
#endif // LOCALUSERBROADCAST_H
