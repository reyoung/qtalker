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
HelloWorldPlugin::HelloWorldPlugin() :
        ExtensionSystem::IPlugin() {
}


bool HelloWorldPlugin::Initialize(const QStringList& cmdArgs) {
    Q_UNUSED(cmdArgs);
    using namespace CorePlugin;
    MainForm* mf = CorePlugin::WidgetFactory::instance()->getMainForm();
    ActionManager* am = ActionManager::instance();

    MenuBarActionContainer* mb = am->createMenuBar(ID("Hello.MenuBar"));
    mf->addWidgetToHeader1(new QPushButton(tr("Hello"),mf));
    mf->addWidgetToHeader2(mb);
    mf->addWidgetToBody(new QTextEdit(mf));
    mf->addWidgetToHeader1(new QLabel(tr("Hello world"),mf));
    return true;
}


Q_EXPORT_PLUGIN2(HelloWorldPlugin,HelloWorldPlugin)
