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

HelloWorldPlugin::HelloWorldPlugin() :
        ExtensionSystem::IPlugin() {
}


bool HelloWorldPlugin::Initialize(const QStringList& cmdArgs) {
    Q_UNUSED(cmdArgs);

    using namespace CorePlugin;
    static HelloPage hp;
    WidgetFactory::instance()->getMainSideWidget()->addSidePage(&hp);

    this->m_udpthread = new Network::UdpThread(this);

    this->connect(this->m_udpthread
                  ,SIGNAL(recieved(Network::RawData)),this,SLOT(RawRecv(Network::RawData)));
    this->m_udpthread->start();
    this->m_udpthread->listen(4000);
    QTimer* timer = new QTimer(this);
    this->connect(timer,SIGNAL(timeout()),this,SLOT(send()));
    timer->start(1000);
    return true;
}



void HelloWorldPlugin::RawRecv(Network::RawData data)
{
    HelloPlugin::TestHelloMessage* ptr = Message::parse<HelloPlugin::TestHelloMessage>(data.Data);
    qDebug()<<ptr->getRequestID();
    delete ptr;
}

void HelloWorldPlugin::send()
{
    HelloPlugin::TestHelloMessage msg;
    this->m_udpthread->broadcast(msg.toByteArray(),4000);
}

Q_EXPORT_PLUGIN2(HelloWorldPlugin, HelloWorldPlugin)



