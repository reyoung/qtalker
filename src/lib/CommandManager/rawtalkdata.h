#ifndef RAWTALKDATA_H
#define RAWTALKDATA_H
#include <QtCore>
#include <QtNetwork>

namespace MessageManager
{
struct RawTalkData
{
    QHostAddress Source;
    quint16     Port;
    QByteArray  Data;
};
const static int RawTalkDataID = qRegisterMetaType<RawTalkData>("RawTalkData");
}



#endif // RAWTALKDATA_H
