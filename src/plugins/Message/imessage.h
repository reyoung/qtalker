#ifndef IMESSAGE_H
#define IMESSAGE_H
#include "MessageManager_global.h"
#include <QtCore>
namespace Message
{
enum MsgType
{
    Default=0,
    Request=1,
    Response = 2,
};
class MESSAGEMANAGERSHARED_EXPORT IMessage
{
    union AuxParse
    {
        quint32 Int;
        char Char[4];
    };
public:


    IMessage(MsgType type= Default):m_ror_type(type)
    {

    }

    MsgType getType()const;

    virtual QString getID()const  = 0;
    virtual QString getRequestID()const
    {
        return getID()+".Request";
    }
    virtual QString getResponseID()const
    {
        return getID()+".Response";
    }
    virtual quint32 getRequestIDHash()const
    {
        return qHash(getRequestID());
    }
    virtual quint32 getResponseIDHash()const
    {
        return qHash(getResponseID());
    }

    virtual void parse(const QByteArray& array) =0;
    virtual QByteArray toByteArray() = 0;


    virtual QByteArray appendHeader(const QByteArray& data)
    {
        QByteArray retv;
        int id;
        MsgType t = this->getType();
        if(t==Request)
        {
            id = getRequestIDHash();
        }
        else if(t==Response)
        {
            id = getResponseIDHash();
        }
        else
        {
            qWarning()<<"Bad ROR";
            return QByteArray();
        }
        retv.append((const char* )(&id),sizeof(id));
        id = data.size();
        retv.append((const char*)(&id),sizeof(int));
        retv.append(data);
        return retv;
    }

    virtual bool canParse(const QByteArray& barray)
    {
        if(barray.size()<4)return false;
        AuxParse p;
        for(int i=0;i<4;++i)
        {
            p.Char[i] = barray.at(i);
        }
        if(p.Int==getRequestIDHash()||
                p.Int == getResponseIDHash())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

protected:
    MsgType m_ror_type;
};

template <class T>
T* parse(const QByteArray& array)
{
    T* retv = new T;
    if(retv->canParse(array))
    {
        retv->parse(array);
        return retv;
    }
    else
    {
        delete retv;
        return 0;
    }
}

}
#endif // IMESSAGE_H
