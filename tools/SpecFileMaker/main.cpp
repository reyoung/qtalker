#include <QtCore/QCoreApplication>
#include <iostream>
#include <string>
#include <QtXml>
#include <QtCore>
#include "specfiledata.h"
using namespace std;
#define AppendElementText(doc,title,text) {\
    QDomElement element = doc.createElement(title);\
    element.appendChild(doc.createTextNode(text));\
    doc.appendChild(element);}
#define AuxAppendElementText(title,text) AppendElementText(document,title,text)

int PrintNGetOption()
{
#ifdef Q_OS_UNIX
    system("clear");
#endif
#ifdef Q_OS_WIN32
    system("cls");
#endif
    cout<<"Optional Selection: "<<endl;
    cout<<"1.Add Dependency"<<endl;
    cout<<"2.Add License"<<endl;
    cout<<"3.Add Description"<<endl;
    cout<<"4.Add Project Url"<<endl;
    cout<<"Else: Exit"<<endl;
    cout<<"TODO! 2,3,4 selection not complete."<<endl;
    int i;
    cin>>i;
    return i;
}

void SaveSpecData(const SpecFileData& data)
{
    QDomDocument document("PluginSpec");
    AuxAppendElementText("Name",data.Name);
    AuxAppendElementText("Version",data.Version);
    AuxAppendElementText("Author",data.Author);
    AuxAppendElementText("Bug Report E-mail",data.BugReportEMail);



    if(!data.DependencyList.empty())
    {
        QDomElement droot = document.createElement("Dependency List");
        for(QList<QPair<QString,QString > >::const_iterator it = data.DependencyList.begin();
        it!=data.DependencyList.end();++it)
        {
            const QPair<QString,QString >& d = *it;
            QDomElement ele = document.createElement("Dependency");
            QDomAttr nameAttr = document.createAttribute("Name");
            QDomAttr versionAttr = document.createAttribute("Version");
            nameAttr.setValue(d.first);
            versionAttr.setValue(d.second);
            ele.appendChild(nameAttr);
            ele.appendChild(versionAttr);
            droot.appendChild(ele);
        }
        document.appendChild(droot);
    }

    QFile file(QString("%1.pluginspec").arg(data.Name));
    file.open(QFile::WriteOnly);
    QTextStream tout(&file);
    document.save(tout,1);
    file.close();
}
void AddDependency(SpecFileData* aData)
{
    SpecFileData& data = *aData;
    cout<<"Please Input Dependence Name: ";
    string name;
    getline(cin,name);getline(cin,name);
    cout<<"Please Input Dependence Version: ";
    string version;
    getline(cin,version);

    QPair<QString,QString> depend;
    depend.first = name.c_str();
    depend.second = version.c_str();

    data.DependencyList.append(depend);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string str;
    SpecFileData data;
    cout<<"Please Input Plugin Name: ";
    getline(cin,str);
    data.Name = str.c_str();
    cout<<"Please Input Plugin Version: ";
    getline(cin,str);
    data.Version = str.c_str();
    cout<<"Please Input Your Name: ";
    getline(cin,str);
    data.Author = str.c_str();
    cout<<"Please Input Bug Report E-mail: ";
    getline(cin,str);
    data.BugReportEMail = str.c_str();
    for(;;)
    {
        switch(PrintNGetOption())
        {
        case 1:
            AddDependency(&data);
            break;
        default:
            SaveSpecData(data);
            exit(0);
        }
    }

    return a.exec();
}
