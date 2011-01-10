#include "plugin.h"
#include <QtPlugin>
#include "core.h"
#include "widgetfactory.h"
#include "mainform.h"
using namespace CorePlugin;
Plugin::Plugin()

{
}


bool Plugin::Initialize(const QStringList& cmdArgs) {
    Q_UNUSED(cmdArgs);
    Core::init(cmdArgs);
    return true;
}
void Plugin::Initialized() {
    WidgetFactory::instance()->getMainForm()->show();
}

Q_EXPORT_PLUGIN2(CorePlugin,Plugin)
