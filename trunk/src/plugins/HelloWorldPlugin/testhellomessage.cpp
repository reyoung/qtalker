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


QString HelloPlugin::TestHelloMessage::getID() const
{
    return "Hello.Msg";
}

QByteArray HelloPlugin::TestHelloMessage::serialize() const
{
    return "";
}
