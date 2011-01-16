#include "audioinput.h"
#include "audioemitter.h"
#include "iaudiofilter.h"
using namespace AudioDevice;
AudioInput::AudioInput(const QAudioFormat &format,
                       const QAudioDeviceInfo &audioDeviceInfo
                       ,QObject *parent) :
    QAudioInput(audioDeviceInfo,format,parent),m_emitter(new AudioEmitter(format,this))
{
    this->m_emitter->open(QIODevice::WriteOnly);
    this->connect(this->m_emitter,SIGNAL(dataRecieved(QByteArray))
                  ,this,SLOT(dataRecv(QByteArray)));
}

void AudioInput::start()
{
    QAudioInput::start(this->m_emitter);
}

void AudioDevice::AudioInput::addFilter(AudioDevice::IAudioFilter* filter)
{
    this->m_filters.push_back(filter);
}

void AudioDevice::AudioInput::dataRecv(QByteArray data)
{
    foreach(const IAudioFilter* fptr,this->m_filters)
    {
        const IAudioFilter& filter = *fptr;
        if(filter.isSetted())
            data = (filter.getFilterFunction())(data);
    }
    emit dataRecieved(data);
}

QList<AudioDevice::IAudioFilter *> AudioDevice::AudioInput::getFilters()
{
    return this->m_filters;
}
