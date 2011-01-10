#include "helloworldplugin.h"
#include <QDebug>
#include <QtPlugin>
#include <QtGui>
#include <ActionManager/actionmanager.h>
#include <ActionManager/menuactioncontainer.h>
#include <ActionManager/menubaractioncontainer.h>
#include <ActionManager/actionmanager.h>
#include <ActionManager/action.h>
#include <widgetfactory.h>
#include <mainform.h>
#include <menubar.h>
#include <sidewidget.h>
#include "hellopage.h"
HelloWorldPlugin::HelloWorldPlugin() :
        ExtensionSystem::IPlugin() {
}


bool HelloWorldPlugin::Initialize(const QStringList& cmdArgs) {
    Q_UNUSED(cmdArgs);

    using namespace CorePlugin;
    static HelloPage hp;
    WidgetFactory::instance()->getMainSideWidget()->addSidePage(&hp);

    return true;
}


Q_EXPORT_PLUGIN2(HelloWorldPlugin, HelloWorldPlugin)
