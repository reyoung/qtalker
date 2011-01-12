#ifndef HELLOWORLDPLUGIN_H
#define HELLOWORLDPLUGIN_H
#include <ExtensionSystem/iplugin.h>
#include <QObject>
#include <Network/udpthread.h>
class HelloWorldPlugin : public ExtensionSystem::IPlugin {
    Q_OBJECT
public:
    explicit HelloWorldPlugin();
    virtual bool Initialize(const QStringList& cmdArgs);
signals:

public slots:
    void RawRecv(Network::RawData data);
    void send();
private:
    Network::UdpThread* m_udpthread;
};

#endif                                            // HELLOWORLDPLUGIN_H
