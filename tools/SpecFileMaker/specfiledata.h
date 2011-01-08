#ifndef SPECFILEDATA_H
#define SPECFILEDATA_H
#include <QString>
#include <QStringList>
#include <QList>
#include <QPair>

struct SpecFileData
{
public:
    QString Version;
    QString Name;
    QString Author;
    QString CopyRight;
    QString License;
    QString Url;
    QString BugReportEMail;
    QString Description;
    QString Category;
    QList<QPair<QString,QString> > DependencyList;
};

#endif // SPECFILEDATA_H
