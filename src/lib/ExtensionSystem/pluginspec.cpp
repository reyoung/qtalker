#include "pluginspec.h"
#include <QtXml>
#include <QtCore>
namespace ExtensionSystem{
struct PluginSpecInnerData
{
    QString Version;
    QString Name;
    QString Author;
    QString CopyRight;
    QString License;
    QString Url;
    QString BugReportEMail;
    QString Description;
    QString Category;
    QList<SpecDependencyData > DependencyList;
};
}

using namespace ExtensionSystem;



PluginSpec::~PluginSpec()
{
    delete this->m_data;
}

PluginSpec::PluginSpec(const QString& fn,QObject *parent) :
    QObject(parent),m_data(new PluginSpecInnerData())
{
    qDebug()<<"OKOK";

}

