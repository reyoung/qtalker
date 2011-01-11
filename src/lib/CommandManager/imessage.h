#ifndef IMESSAGE_H
#define IMESSAGE_H
#include "MessageManager_global.h"
#include "const.h"
#include <QtCore>

namespace MessageManager
{
    namespace Inner{
    union HeaderUnion
    {
        int Int;
        char Chars[4];
    };
    }

    template <class T>
    static T* Parse(const QByteArray& ){return 0;}
    class MESSAGEMANAGERSHARED_EXPORT IMessage
    {
        const Const::MessageType m_type;
        const Const::RequestOrResponse m_reqOrRes;
    public:
        IMessage(const Const::MessageType mt,const Const::RequestOrResponse ror):
            m_type(mt),m_reqOrRes(ror)
        {

        }
        virtual QByteArray toByteArray() =0;




        Const::MessageType getType()const
        {
            return m_type;
        }
        bool isRequest()const
        {
            return this->m_reqOrRes == Const::Request;
        }
        bool isResponse()const
        {
            return this->m_reqOrRes == Const::Response;
        }

    protected:



        template <Const::MessageType cmd,Const::RequestOrResponse re>
        static QByteArray appendHeader(const QByteArray data)
        {
            QByteArray barray;
            int type = Const::getCommandID<cmd,re>();
            barray.append((const char *)&type,sizeof(int));
            type = data.size();
            barray.append((const char *)&type,sizeof(int));
            barray.append(data);
            return barray;
        }

    };
}
#endif // IMESSAGE_H
