#include "tcpthread.h"
#include <limits>
using namespace Network;
TcpThread::TcpThread(QObject *parent) :
    SendThread(parent)
{
    this->m_server = new QTcpServer(this);
    this->connect(this->m_server,SIGNAL(newConnection()),this,SLOT(arravedConnection()));
}

Network::SendThread::SendReturned Network::TcpThread::send(const Network::RawData &barray)
{
    int i;
    for( i=0;i<this->m_sock_list.size();++i)
    {
       if(this->m_sock_list[i]->peerAddress()==barray.getAddress()&&
               this->m_sock_list[i]->peerPort()==barray.getPort())
       {
           break;
       }
    }

    if(i==this->m_sock_list.size())
    {
//        qDebug()<<"Need Connect";
        QTcpSocket* tcp_sock = new QTcpSocket(this);
        tcp_sock->connectToHost(barray.getAddress(),barray.getPort());
        this->connect(tcp_sock,SIGNAL(connected()),this,SLOT(auxSend()));
        this->m_wait_send_datas.insert(tcp_sock,barray.Data);
        return Network::SendThread::SuccessWithConnect;
    }
    else
    {
        this->m_sock_list[i]->write(barray.Data);
        return Network::SendThread::SuccessWithoutConnect;
    }
}

void Network::TcpThread::auxSend()
{
//    qDebug()<<"Connected";
    QTcpSocket* sock = qobject_cast<QTcpSocket*>(sender());
    qDebug()<<sock->peerAddress()<<" "<<sock->peerPort();
    Q_ASSERT(sock!=0);
    QByteArray d = this->m_wait_send_datas.value(sock);
    this->m_wait_send_datas.remove(sock);
//    qDebug()<<d;
    sock->write(d);
    this->connect(sock,SIGNAL(readyRead()),this,SLOT(rawMsgRecv()));
    this->m_sock_list.push_back(sock);
}

bool Network::TcpThread::listen(quint16 port)
{
    return this->m_server->listen(QHostAddress::LocalHost,port);
}

void Network::TcpThread::arravedConnection()
{
    QTcpSocket* sock = this->m_server->nextPendingConnection();
    this->connect(sock,SIGNAL(readyRead()),this,SLOT(rawMsgRecv()));
    this->m_sock_list.append(sock);
}

void Network::TcpThread::rawMsgRecv()
{
    QTcpSocket* sock = qobject_cast<QTcpSocket*>(sender());
    Network::RawData data(sock->peerAddress(),sock->peerPort(),sock->read(65536*1024));
    emit recieved(data);
}
