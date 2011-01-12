#include "pluginspec.h"
#include <QtXml>
#include <QtCore>

using namespace ExtensionSystem;

PluginSpec::~PluginSpec() {
//    delete this;
}


PluginSpec::PluginSpec(const QString& fn) {
    qDebug() << "Loading " << fn<<" Spec";
    QDomDocument document;
    QFile file(fn);
    file.open(QFile::ReadOnly);
    int errorColumn, errorLine;
    QString errorStr;

    if (!document.setContent(&file, true, &errorStr, &errorLine,
                             &errorColumn)) {
        qDebug() << QObject::tr("Parse error at line %1, column %2:\n%3")
        .arg(errorLine)
        .arg(errorColumn)
        .arg(errorStr);
        return;
    }

    QDomNode n = document.firstChild();

    QDomElement root = n.toElement();
    n = root.firstChild();

    while (!n.isNull()) {
        QDomElement e = n.toElement();
        QString tn = e.tagName();

        if (tn == "Name") {
            this->Name = e.firstChild().toText().data();
        }

        else
            if (tn == "Version") {
                this->Version = e.firstChild().toText().data();
            }

            else
                if (tn == "Author") {
                    this->Author = e.firstChild().toText().data();
                }

                else
                    if (tn == "License") {
                        this->License = e.firstChild().toText().data();
                    }

                    else
                        if (tn == "Category") {
                            this->Category = e.firstChild().toText().data();
                        }

                        else
                            if (tn == "CopyRight") {
                                this->CopyRight = e.firstChild().toText().data();
                            }

                            else
                                if (tn == "Description") {
                                    this->Description = e.firstChild().toText().data();
                                }

                                else
                                    if (tn == "Bug_Report_E-mail") {
                                        this->BugReportEMail = e.firstChild().toText().data();
                                    }

                                    else
                                        if (tn == "Dependency_List") {
                                            QDomNode de = e.firstChild();

                                            while (!de.isNull()) {
                                                QDomElement el = de.toElement();
                                                SpecDependencyData temp;
                                                temp.Name = el.attribute("Name");
                                                temp.Version = el.attribute("Version");
                                                this->DependencyList.append(temp);
                                                de = de.nextSibling();
                                            }
                                        }

        n = n.nextSibling();
    }

    file.close();

    this->m_state = NotLoad;
}


QString PluginSpec::name() const {
    return this->Name;
}


QString PluginSpec::version() const {
    return this->Version;
}


QString PluginSpec::author() const {
    return this->Author;
}


QString PluginSpec::bugReportEmail() const {
    return this->BugReportEMail;
}


QList<SpecDependencyData> PluginSpec::dependencyList() const {
    return this->DependencyList;
}


QString PluginSpec::license() const {
    return this->License;
}


QString PluginSpec::category() const {
    return this->Category;
}


QString PluginSpec::copyRight() const {
    return this->CopyRight;
}


QString PluginSpec::description() const {
    return this->Description;
}


int PluginSpec::getState() const {
    return m_state;
}


void PluginSpec::setState(int st) {
    m_state = st;
}


bool PluginSpec::operator == (const QString& name) {
    return this->Name == name;
}


bool PluginSpec::operator == (const PluginSpec& other) {
    return this->Name == other.Name;
}
