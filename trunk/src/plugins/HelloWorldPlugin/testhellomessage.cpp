#include "testhellomessage.h"
using namespace HelloPlugin;
TestHelloMessage::TestHelloMessage():
    Message::IMessage(Message::Request)
{
}

void HelloPlugin::TestHelloMessage::parse(const QByteArray &array)
{
    Q_UNUSED(array);
    return ;
}

QByteArray HelloPlugin::TestHelloMessage::toByteArray()
{
    return this->appendHeader("");
}

QString HelloPlugin::TestHelloMessage::getID() const
{
    return "Hello.Msg";
}
