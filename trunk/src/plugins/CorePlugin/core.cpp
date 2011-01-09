#include "core.h"
#include "uniqueidmanager.h"
#include "ActionManager/actionmanager.h"
using namespace CorePlugin;

Core *Core::m_instance = 0;
Core::Core(QObject *parent) :
    QObject(parent)
{

}
Core* Core::instance()
{

    return m_instance;
}

bool Core::init(const QStringList &cmdArgs)
{
    Q_UNUSED(cmdArgs);
    if(DebugFlag)
        qDebug()<<"Initing Core.....";
    m_instance = new Core();
    if(DebugFlag)
        qDebug()<<"Initing UniqueIDManager.....";
    UniqueIDManager::init();
    if(DebugFlag)
        qDebug()<<"Initing ActionManager.....";
    ActionManager::init();
    return true;
}
UniqueIDManager* Core::uidManager()
{
    return UniqueIDManager::instance();
}
