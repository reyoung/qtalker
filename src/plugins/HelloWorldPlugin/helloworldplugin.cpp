#include "helloworldplugin.h"
#include <QDebug>
#include <QtPlugin>
#include <QtGui>
#include <widgetfactory.h>
#include <mainform.h>
#include <menubar.h>
#include <sidewidget.h>
#include "hellopage.h"
#include "testhellomessage.h"
#include <Network/tcpthread.h>

const quint16 port[] = {5555,6666,7777,8888};

HelloWorldPlugin::HelloWorldPlugin() :
        ExtensionSystem::IPlugin() {
}


bool HelloWorldPlugin::Initialize(const QStringList& cmdArgs) {
    Q_UNUSED(cmdArgs);

    using namespace CorePlugin;
    static HelloPage hp;
    WidgetFactory::instance()->getMainSideWidget()->addSidePage(&hp);

    this->m_udpthread = new Network::UdpThread(this);
    this->m_tcpthread = new Network::TcpThread(this);
//    this->connect(this->m_udpthread
//                  ,SIGNAL(recieved(Network::RawData)),this,SLOT(RawRecv(Network::RawData)));
    this->connect(this->m_tcpthread,SIGNAL(recieved(Network::RawData)),this,SLOT(RawRecv(Network::RawData)));

    this->m_tcpthread->start();
    this->m_udpthread->start();
    this->m_udpthread->listen(4000);

    for(int i=0;i<4;++i)
    {
        if(this->m_tcpthread->listen(port[i]))
        {
            qDebug()<<"Listen to "<<port[i];
            break;
        }
    }

    QTimer* timer = new QTimer(this);
    this->connect(timer,SIGNAL(timeout()),this,SLOT(send()));
    timer->start(1000);
    return true;
}



void HelloWorldPlugin::RawRecv(Network::RawData data)
{
    qDebug()<<"Tcp Recv";
//    HelloPlugin::TestHelloMessage* ptr = Message::parse<HelloPlugin::TestHelloMessage>(data.Data);
//    qDebug()<<ptr->getRequestID();
//    delete ptr;
}

void HelloWorldPlugin::send()
{
    HelloPlugin::TestHelloMessage msg;
    this->m_udpthread->broadcast(msg.toByteArray(),4000);
    for(int i=0;i<4;++i)
    {
        Network::RawData d(QHostAddress::LocalHost,port[i],"Hello world");
        this->m_tcpthread->send(d);
    }
}

Q_EXPORT_PLUGIN2(HelloWorldPlugin, HelloWorldPlugin)



