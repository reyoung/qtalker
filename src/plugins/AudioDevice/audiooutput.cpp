#include "audiooutput.h"
#include <QDebug>
using namespace AudioDevice;
AudioOutput::AudioOutput(const QAudioFormat & format ,const QAudioDeviceInfo & audioDevice,
                         QObject *parent) :
    QAudioOutput(audioDevice,format,parent)
{
    this->m_outDevice= this->start();
}

void AudioOutput::dataRecieved(QByteArray data)
{
    this->m_outDevice->write(data);
}
