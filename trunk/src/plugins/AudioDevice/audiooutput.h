#ifndef AUDIOOUTPUT_H
#define AUDIOOUTPUT_H

#include <QAudioOutput>
#include <QList>
#include "AudioDevice_global.h"
namespace AudioDevice
{
class IAudioFilter;
class AUDIODEVICESHARED_EXPORT AudioOutput : public QAudioOutput
{
    Q_OBJECT
public:
    explicit AudioOutput(  const QAudioFormat & format = QAudioFormat(),const QAudioDeviceInfo & audioDevice= QAudioDeviceInfo::defaultOutputDevice()
                         ,QObject *parent = 0);
    void addFilter(IAudioFilter* filter);

    QList<IAudioFilter* > getFilters();
signals:

public slots:
    void dataRecieved(QByteArray data);
private:
    QIODevice* m_outDevice;
    QList<IAudioFilter* > m_filters;
};
}
#endif // AUDIOOUTPUT_H
