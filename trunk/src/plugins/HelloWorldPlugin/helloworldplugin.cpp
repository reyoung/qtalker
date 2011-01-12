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
    HelloPlugin::TestHelloMessage msg;
    QByteArray barray = msg.toByteArray();
    HelloPlugin::TestHelloMessage* ptr = Message::parse<HelloPlugin::TestHelloMessage> (barray);
    qDebug()<<ptr->getRequestID();
    delete ptr;
    return true;
}

Q_EXPORT_PLUGIN2(HelloWorldPlugin, HelloWorldPlugin)





