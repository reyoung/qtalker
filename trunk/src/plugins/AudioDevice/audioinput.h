#ifndef AUDIOINPUT_H
#define AUDIOINPUT_H

#include <QAudioInput>
//#include "audioemitter.h"
#include "AudioDevice_global.h"

namespace AudioDevice
{
class AudioEmitter;
class IAudioFilter;
class AUDIODEVICESHARED_EXPORT AudioInput : public QAudioInput
{
    Q_OBJECT
public:
    explicit AudioInput(const QAudioFormat &format = QAudioFormat(),const QAudioDeviceInfo &audioDeviceInfo
                        = QAudioDeviceInfo::defaultInputDevice(),QObject *parent = 0);
    void start();
    void addFilter(IAudioFilter* filter);
    QList<IAudioFilter* > getFilters();
signals:
    void dataRecieved(QByteArray );
public slots:
private:
    AudioEmitter* m_emitter;
    QList<IAudioFilter* > m_filters;
private slots:
    void dataRecv(QByteArray data);
};
}
#endif // AUDIOINPUT_H
