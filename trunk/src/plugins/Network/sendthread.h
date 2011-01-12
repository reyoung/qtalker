#ifndef SENDTHREAD_H
#define SENDTHREAD_H

#include <QThread>
#include "Network_global.h"
#include "rawdata.h"
namespace Network
{
class NETWORKSHARED_EXPORT SendThread : public QThread
{
    Q_OBJECT
public:
    enum SendReturned
    {
        SuccessWithoutConnect=0,
        SuccessWithConnect=1,
    };

    explicit SendThread(QObject *parent = 0);
    virtual SendReturned send(const RawData& barray) = 0;
    virtual bool listen(quint16 port)= 0;
signals:
    void recieved(Network::RawData barray);
public slots:

};
}
#endif // SENDTHREAD_H
