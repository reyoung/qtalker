#include "udpthread.h"
using namespace Network;
UdpThread::UdpThread(QObject *parent) :
    SendThread(parent),m_socket(new QUdpSocket(this))
{
}

void Network::UdpThread::run()
{
    this->connect(this->m_socket,SIGNAL(readyRead()),this,SLOT(rawDataRecieved()));
    this->exec();
}

Network::SendThread::SendReturned Network::UdpThread::send(const Network::RawData &barray)
{
    this->m_socket->writeDatagram(barray.Data,barray.getAddress(),barray.getPort());
    return Network::SendThread::SuccessWithConnect;
}

bool Network::UdpThread::listen(quint16 port)
{
    return this->m_socket->bind(port,QUdpSocket::DefaultForPlatform);
}

void Network::UdpThread::rawDataRecieved()
{
    quint64 dsize = this->m_socket->pendingDatagramSize();
    char* buffer = new char[dsize+1];
    Network::RawData rawdata;
    dsize = this->m_socket->readDatagram(buffer,dsize+1,&rawdata.m_addr,&rawdata.m_port);
    rawdata.Data.append(buffer,dsize);
    delete buffer;
    emit recieved(rawdata);
}

void Network::UdpThread::broadcast(const QByteArray &barray,quint16 port)
{
    this->m_socket->writeDatagram(barray,QHostAddress::Broadcast,port);
}
