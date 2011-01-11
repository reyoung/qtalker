#ifndef CONST_H
#define CONST_H
#include <QVector>
namespace MessageManager
{
    namespace Const
    {
        const quint16 UDPPort = 4000;
        const int PosiblePortSize = 4;
        const int PosiblePorts[PosiblePortSize]={1111,2222,3333,4444};
        const int inline getLocalRefreshSec()
        {
            return 30;
        }

        enum RequestOrResponse
        {
            Request = 0,
            Response = 1,
        };
        enum MessageType
        {
            LocalUserBroadCast = 0,
        };
        template <MessageType cmd,RequestOrResponse re>
        inline int getCommandID()
        {
            static const int retv = (cmd<<1)|re;
            return retv;
        }
    }
}



#endif // CONST_H
