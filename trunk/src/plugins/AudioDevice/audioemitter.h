#ifndef AUDIOEMITTER_H
#define AUDIOEMITTER_H

#include <QIODevice>
#include <QtMultimedia>
#include "AudioDevice_global.h"
namespace AudioDevice
{
class AUDIODEVICESHARED_EXPORT AudioEmitter : public QIODevice
{
    Q_OBJECT
public:
    explicit AudioEmitter(const QAudioFormat &format, QObject *parent = 0);
    qint64 readData(char *data, qint64 maxlen);
    qint64 writeData(const char *data, qint64 len);
    QAudioFormat getFormat()const;
signals:
    void dataRecieved(QByteArray data);
    void levelChanged(qreal level);
public slots:
private:
    QAudioFormat m_format;
    int        m_max_level;
};
}
#endif // AUDIOEMITTER_H
