#include "audiooutput.h"
#include "iaudiofilter.h"
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
    QByteArray outdata = qUncompress(data);
    foreach(const AudioDevice::IAudioFilter* fptr ,this->m_filters)
    {
        const AudioDevice::IAudioFilter& filter = *fptr;
        if(filter.isSetted())
            outdata = (filter.getFilterFunction())(outdata);
    }

    this->m_outDevice->write(outdata);
}

void AudioDevice::AudioOutput::addFilter(AudioDevice::IAudioFilter *filter)
{
    this->m_filters.push_back(filter);
}

QList<AudioDevice::IAudioFilter *> AudioDevice::AudioOutput::getFilters()
{
    return this->m_filters;
}
