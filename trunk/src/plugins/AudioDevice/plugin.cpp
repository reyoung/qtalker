#include "plugin.h"
#include <QtPlugin>
using namespace AudioDevice;
bool Plugin::Initialize(const QStringList &cmdArgs)
{
    Q_UNUSED(cmdArgs);
    return true;
}
Q_EXPORT_PLUGIN2(AudioDevice,Plugin)
