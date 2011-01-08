#include "pluginmanager.h"
#include "pluginspec.h"
#include <QList>
#include <global_const.h>
#include <QtCore>




using namespace ExtensionSystem;




PluginManager::PluginManager() :
        QObject(0)
{
    QDir dir(Global::Const::PluginPath);
    this->LoadPluginSpec(dir);
}
PluginManager* PluginManager::instance()
{
    static PluginManager* ins = new PluginManager() ;
    return ins;
}
PluginManager::~PluginManager()
{

}
void PluginManager::LoadPluginSpec(const QDir &dir)
{
    QFileInfoList flist = dir.entryInfoList();

    foreach(const QFileInfo& inf,flist)
    {
        if(inf.isDir()
            &&!inf.isSymLink()
            &&inf.fileName()!="."
            &&inf.fileName()!="..")
        {
            this->LoadPluginSpec(inf.dir());
        }
        else if(inf.completeSuffix()=="pluginspec")
        {
            m_specs.append(PluginSpec(inf.filePath()));
        }
    }

}
