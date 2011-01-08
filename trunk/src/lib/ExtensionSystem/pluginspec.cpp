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
    int m_state;
};
}

using namespace ExtensionSystem;



PluginSpec::~PluginSpec()
{
    delete this->m_data;
}

PluginSpec::PluginSpec(const QString& fn) :
    m_data(new PluginSpecInnerData())
{
    qDebug()<<"Loading "<<fn;
    QDomDocument document;
    QFile file(fn);
    file.open(QFile::ReadOnly);
    int errorColumn,errorLine;
    QString errorStr;
    if (!document.setContent(&file, true, &errorStr, &errorLine,
                                &errorColumn)) {
        qDebug()<<QObject::tr("Parse error at line %1, column %2:\n%3")
                                .arg(errorLine)
                                 .arg(errorColumn)
                                 .arg(errorStr);
        return;
    }

    QDomNode n = document.firstChild();
    QDomElement root = n.toElement();
    n = root.firstChild();
    while(!n.isNull())
    {
        QDomElement e = n.toElement();
        QString tn = e.tagName();
        if(tn == "Name")
        {
            this->m_data->Name = e.firstChild().toText().data();
        }
        else if(tn=="Version")
        {
            this->m_data->Version = e.firstChild().toText().data();
        }
        else if(tn=="Author")
        {
            this->m_data->Author = e.firstChild().toText().data();
        }
        else if(tn=="License")
        {
            this->m_data->License = e.firstChild().toText().data();
        }
        else if(tn == "Category")
        {
            this->m_data->Category = e.firstChild().toText().data();
        }
        else if(tn == "CopyRight")
        {
            this->m_data->CopyRight = e.firstChild().toText().data();
        }
        else if(tn == "Description")
        {
            this->m_data->Description = e.firstChild().toText().data();
        }
        else if(tn=="Bug_Report_E-mail")
        {
            this->m_data->BugReportEMail = e.firstChild().toText().data();
        }
        else if(tn=="Dependency_List")
        {
            QDomNode de = e.firstChild();
            while(!de.isNull())
            {
                QDomElement el = de.toElement();
                SpecDependencyData temp;
                temp.Name = el.attribute("Name");
                temp.Version = el.attribute("Version");
                this->m_data->DependencyList.append(temp);
                de = de.nextSibling();
            }
        }
        n = n.nextSibling();
    }
    file.close();
    this->m_data->m_state = NotLoad;
}

QString PluginSpec::name()const
{
    return this->m_data->Name;
}
QString PluginSpec::version()const
{
    return this->m_data->Version;
}
QString PluginSpec::author()const
{
    return this->m_data->Author;
}
QString PluginSpec::bugReportEmail()const
{
    return this->m_data->BugReportEMail;
}
QList<SpecDependencyData> PluginSpec::dependencyList()const
{
    return this->m_data->DependencyList;
}
QString PluginSpec::license()const
{
    return this->m_data->License;
}
QString PluginSpec::category()const
{
    return this->m_data->Category;
}
QString PluginSpec::copyRight()const
{
    return this->m_data->CopyRight;
}
QString PluginSpec::description()const
{
    return this->m_data->Description;
}
int PluginSpec::getState()const
{
    return m_data->m_state;
}
void PluginSpec::setState(int st)
{
    m_data->m_state = st;
}

bool PluginSpec::operator ==(const QString& name)
{
    return this->m_data->Name==name;
}
