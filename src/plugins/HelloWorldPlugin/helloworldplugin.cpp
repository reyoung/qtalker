#include "helloworldplugin.h"
#include <QDebug>
#include <QtPlugin>
#include <QtGui>
#include <ActionManager/actionmanager.h>
#include <ActionManager/menuactioncontainer.h>
#include <ActionManager/action.h>
HelloWorldPlugin::HelloWorldPlugin() :
        ExtensionSystem::IPlugin() {
}


bool HelloWorldPlugin::Initialize(const QStringList& cmdArgs) {
    Q_UNUSED(cmdArgs);
//qDebug()<<"Hello world";
    QMainWindow* lab = new QMainWindow();
    lab->setWindowTitle(tr("hello world"));
    CorePlugin::ActionManager* am = CorePlugin::ActionManager::instance();
    using namespace CorePlugin;
    IActionContainer* ac = am->createMenuBar("HelloWorldPlugin.Menu");

    MenuActionContainer* menu = (MenuActionContainer*)am->createMenu("Menu.Hello");

    menu->setTitle(tr("HEllo world?"));

    Action* action = am->createAction("Hello Action");
    action->setText(tr("Action"));

    menu->insertAction(action);

    ac->insertContainer(menu);
    lab->setMenuBar(ac->menubar());

    this->addAutoReleaseObject(lab);
    lab->show();
    return true;
}


Q_EXPORT_PLUGIN2(HelloWorldPlugin,HelloWorldPlugin)
