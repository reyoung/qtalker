#ifndef HELLOWORLDPLUGIN_H
#define HELLOWORLDPLUGIN_H
#include <ExtensionSystem/iplugin.h>
#include <QObject>
#include <Network/udpthread.h>
#include <Network/tcpthread.h>
#include <AudioDevice/audioinput.h>
#include <AudioDevice/audiooutput.h>

class HelloWorldPlugin : public ExtensionSystem::IPlugin {
    Q_OBJECT
public:
    explicit HelloWorldPlugin();
    virtual bool Initialize(const QStringList& cmdArgs);
signals:

public slots:
    void RawRecv(Network::RawData data);
    void send();
    void outputSize(QByteArray barray);
private:
    Network::UdpThread* m_udpthread;
    Network::TcpThread* m_tcpthread;
    AudioDevice::AudioInput* m_input;
    AudioDevice::AudioOutput* m_output;

};

#endif                                            // HELLOWORLDPLUGIN_H
