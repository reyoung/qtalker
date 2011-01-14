#include "audioinput.h"
#include "audioemitter.h"
using namespace AudioDevice;
AudioInput::AudioInput(const QAudioFormat &format,
                       const QAudioDeviceInfo &audioDeviceInfo
                       ,QObject *parent) :
    QAudioInput(audioDeviceInfo,format,parent),m_emitter(new AudioEmitter(format,this))
{
    this->m_emitter->open(QIODevice::WriteOnly);
    this->connect(this->m_emitter,SIGNAL(dataRecieved(QByteArray)),this,SIGNAL(dataRecieved(QByteArray)));
}

void AudioInput::start()
{
    QAudioInput::start(this->m_emitter);
}
