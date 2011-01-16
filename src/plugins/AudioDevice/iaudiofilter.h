#ifndef IAUDIOFILTER_H
#define IAUDIOFILTER_H
#include "AudioDevice_global.h"
#include <QtCore>

namespace AudioDevice
{
class AUDIODEVICESHARED_EXPORT IAudioFilter
{
public:
    typedef QByteArray (*FilterCallBack)(const QByteArray& );
    virtual FilterCallBack getFilterFunction()const = 0;
    bool isSetted()const{return this->m_isSetted;}
    void set(bool setted=true){this->m_isSetted = setted;}
    void unset(){this->set(false);}
    virtual QString getName()const = 0;
    virtual QString getDescription()const = 0;
protected:
    bool m_isSetted;
};
}
#endif // IAUDIOFILTER_H
