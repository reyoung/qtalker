#ifndef TESTHELLOMESSAGE_H
#define TESTHELLOMESSAGE_H
#include <Message/imessage.h>
#include <QtCore>
#include "HelloWorldPlugin_global.h"
namespace HelloPlugin
{
class HELLOWORLDPLUGINSHARED_EXPORT TestHelloMessage:public Message::IMessage
{
public:
    TestHelloMessage();
    virtual void parse(const QByteArray& array);
    virtual QByteArray toByteArray();
    virtual QString getID()const;
};
}
#endif // TESTHELLOMESSAGE_H
