#include "plugin.h"
#include <QtPlugin>
using namespace Network;


bool Network::Plugin::Initialize(const QStringList &cmdArgs)
{
    Q_UNUSED(cmdArgs);
    return true;
}
Q_EXPORT_PLUGIN2(NetworkPlugin,Plugin)
