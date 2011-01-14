#ifndef AUDIOOUTPUT_H
#define AUDIOOUTPUT_H

#include <QAudioOutput>
#include "AudioDevice_global.h"
namespace AudioDevice
{
class AUDIODEVICESHARED_EXPORT AudioOutput : public QAudioOutput
{
    Q_OBJECT
public:
    explicit AudioOutput(  const QAudioFormat & format = QAudioFormat(),const QAudioDeviceInfo & audioDevice= QAudioDeviceInfo::defaultOutputDevice()
                         ,QObject *parent = 0);

signals:

public slots:
    void dataRecieved(QByteArray data);
private:
    QIODevice* m_outDevice;
};
}
#endif // AUDIOOUTPUT_H
