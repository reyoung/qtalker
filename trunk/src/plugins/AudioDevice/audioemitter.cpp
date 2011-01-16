#include "audioemitter.h"
using namespace AudioDevice;
AudioEmitter::AudioEmitter(const QAudioFormat &format,QObject *parent) :
    QIODevice(parent),m_format(format),m_max_level(0)
{
    switch(this->m_format.sampleSize())
    {
    case 8:
        this->m_max_level = this->m_format.sampleType()==QAudioFormat::SignedInt?127:255;
        break;
    case 16:
        this->m_max_level = this->m_format.sampleType()==QAudioFormat::SignedInt?32767:65535;
        break;
    default:
        break;
    }
}

qint64 AudioEmitter::readData(char *data, qint64 maxlen)
{
    Q_UNUSED(data);
    Q_UNUSED(maxlen);
    return 0;
}

qint64 AudioEmitter::writeData(const char *data, qint64 len)
{
    QByteArray dat = qCompress((const uchar* )data,len,9);
    emit dataRecieved(dat);
    if(this->m_max_level)
    {
        qreal m_level;
        Q_ASSERT(this->m_format.sampleSize()%8==0);
        const int channelBytes = this->m_format.sampleSize()/8;
        const int sampleBytes = this->m_format.channelCount()*channelBytes;
        Q_ASSERT(len%sampleBytes==0);
        const int numSamples = len/sampleBytes;

        int maxValue = 0;
        const unsigned char *ptr = reinterpret_cast<const unsigned char *>(data);
        for (int i = 0; i < numSamples; ++i) {
            for(int j = 0; j < m_format.channels(); ++j) {
                int value = 0;

                if (m_format.sampleSize() == 8 && m_format.sampleType() == QAudioFormat::UnSignedInt) {
                    value = *reinterpret_cast<const quint8*>(ptr);
                } else if (m_format.sampleSize() == 8 && m_format.sampleType() == QAudioFormat::SignedInt) {
                    value = qAbs(*reinterpret_cast<const qint8*>(ptr));
                } else if (m_format.sampleSize() == 16 && m_format.sampleType() == QAudioFormat::UnSignedInt) {
                    if (m_format.byteOrder() == QAudioFormat::LittleEndian)
                        value = qFromLittleEndian<quint16>(ptr);
                    else
                        value = qFromBigEndian<quint16>(ptr);
                } else if (m_format.sampleSize() == 16 && m_format.sampleType() == QAudioFormat::SignedInt) {
                    if (m_format.byteOrder() == QAudioFormat::LittleEndian)
                        value = qAbs(qFromLittleEndian<qint16>(ptr));
                    else
                        value = qAbs(qFromBigEndian<qint16>(ptr));
                }

                maxValue = qMax(value, maxValue);
                ptr += channelBytes;
            }
        }
        maxValue = qMin(maxValue, this->m_max_level);
        m_level = qreal(maxValue) / this->m_max_level;
        emit levelChanged(m_level);
    }

    return len;
}

QAudioFormat AudioEmitter::getFormat() const
{
    return this->m_format;
}
