#include "plugin.h"
#include <QtPlugin>
#include "core.h"
using namespace CorePlugin;
Plugin::Plugin()

{
}


bool Plugin::Initialize(const QStringList& cmdArgs) {
    Q_UNUSED(cmdArgs);
    Core::init(cmdArgs);
    return true;
}


Q_EXPORT_PLUGIN2(CorePlugin,Plugin)
