#include "pluginmanager.h"
#include "pluginspec.h"
#include <QList>
#include <global_const.h>
#include <QtCore>
#include <QSettings>
#include <QPluginLoader>
#include "iplugin.h"

using namespace ExtensionSystem;




PluginManager::PluginManager() :
        QObject(0)
{
    QDir dir(Global::Const::PluginPath);
    this->LoadPluginSpec(dir);
    this->LoadAllPlugin();
}
PluginManager* PluginManager::instance()
{
    static PluginManager* ins = new PluginManager() ;
    return ins;
}
PluginManager::~PluginManager()
{
    for(QList<QObject* >::iterator it = this->m_objList.begin();
    it!=this->m_objList.end();++it)
    {
        delete *it;
    }
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
namespace Inner
{
    struct AuxLoadStruct
    {
        SpecDependencyData key;
        QList<SpecDependencyData> depends;
        AuxLoadStruct(const PluginSpec& spec)
        {
            key.Name = spec.name();
            key.Version = spec.version();
            foreach(const SpecDependencyData& dep , spec.dependencyList())
            {
                depends.push_back(dep);
            }
        }
        bool operator == (const AuxLoadStruct& other)
        {
            return this->key.Name==other.key.Name&&this->key.Version==other.key.Version;
        }
    };
}
void PluginManager::LoadAllPlugin()
{

    QList<Inner::AuxLoadStruct> specList;
    foreach(const PluginSpec& spec, this->m_specs)
    {
        specList.push_back(Inner::AuxLoadStruct(spec));
    }

    for(;;)
    {
        bool conti = false;
        foreach(const Inner::AuxLoadStruct& spec,specList)
        {
            if(spec.depends.size()==0)
            {
                /// Load
                conti = true;
                QString fn("plugin/%1.%2");
#ifdef Q_OS_WIN32
                fn = fn.arg(spec.key.Name).arg("dll");
#endif
                QPluginLoader loader(fn);
                bool loadSuccess = loader.load();
                if(!loadSuccess)
                {
                    qWarning()<<tr("%1 Plugin Load Error ").arg(fn);
                }
                else
                {
                    QObject* obj = loader.instance();
                    this->addObject(obj);
                    IPlugin* plugin = qobject_cast<IPlugin*>(obj);
                    plugin->Initialize(QCoreApplication::arguments());
                }


                /// Sovole Depend
                for(QList<Inner::AuxLoadStruct>::iterator it = specList.begin()
                    ;it!=specList.end();++it)
                {
                    for(QList<SpecDependencyData>::iterator dit = it->depends.begin();
                    dit != it->depends.end();++it)
                    {
                        if(dit->Name == spec.key.Name
                           &&dit->Version == spec.key.Version)
                        {
                            it->depends.erase(dit);
                        }
                    }
                }
                specList.removeOne(spec);
            }
        }
        if(!conti)
            break;
    }
}
void PluginManager::addObject(QObject *object)
{
    this->m_objList.push_back(object);
}
