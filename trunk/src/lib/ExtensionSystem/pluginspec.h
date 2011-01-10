#ifndef PLUGINSPEC_H
#define PLUGINSPEC_H

#include <QObject>
#include <QtCore>
#include "ExtensionSystem_global.h"

namespace ExtensionSystem {
//struct PluginSpecInnerData;/// Plugin Spec Inner Data. Plugin的成员变量
/**
 * 表示Plugin 依赖关系的Data
 *       有依赖于的Name和相应的Version
 *
 */

struct SpecDependencyData {
    QString Name;
    QString Version;
};

/**
 * Plugin Spec
 *       Plugin描述文件的抽象。通过描述文件，来加载Plugin
 *
 */

class EXTENSIONSYSTEMSHARED_EXPORT PluginSpec { //: public QObject
//Q_OBJECT

public:
    enum State {
        NotLoad = 0,
        Loaded = 1,
        BeforeInit = 2,
        Inited = 4,
        Completed = 8,
        Error = -1
    };

//! 默认构造函数 ,以Spec文件名为参数.
    /*!
     \author Reyoung
     \date 2011.01.08
    \version ver 0.0.1
    -
    \exception
    \test
    \note
    \attention
    \sa
    \remark 1.2011.01.08 21:13 created by Reyoung
    \return
    */
    explicit PluginSpec(const QString& fn);
    virtual ~PluginSpec();
//! 返回Spec Name.
    /*!
     \author Reyoung
     \date 2011.01.08
    \version ver 0.0.1
    -
    \exception
    \test
    \note
    \attention
    \sa
    \remark 1.2011.01.08 21:14 created by Reyoung
    \return QString
    */
    QString name() const;
//! 返回Plugin的版本.
    /*!
     \author Reyoung
     \date 2011.01.08
    \version ver 0.0.1
    -
    \exception
    \test
    \note
    \attention
    \sa
    \remark 1.2011.01.08 21:14 created by Reyoung
    \return QString
    */
    QString version() const;
//! 返回Plugin的作者.
    /*!
     \author Reyoung
     \date 2011.01.08
    \version ver 0.0.1
    -
    \exception
    \test
    \note
    \attention
    \sa
    \remark 1.2011.01.08 21:15 created by Reyoung
    \return QString
    */
    QString author() const;
//! 返回Plugin的Bug Report E-mail.
    /*!
     \author Reyoung
     \date 2011.01.08
    \version ver 0.0.1
    -
    \exception
    \test
    \note
    \attention
    \sa
    \remark 1.2011.01.08 21:14 created by Reyoung
    \return QString
    */
    QString bugReportEmail() const;

//! 返回该Plugin依赖的Plugin.
    /*!
     \author Reyoung
     \date 2011.01.08
    \version ver 0.0.1
    -
    \exception
    \test
    \note
    \attention
    \sa
    \remark 1.2011.01.08 21:15 created by Reyoung
    \return QList
    */
    QList<SpecDependencyData> dependencyList() const;

    QString description() const;
    QString category() const;
    QString copyRight() const;
    QString license() const;
    int getState() const;
    void setState(int st);
//    signals:
    bool operator == (const QString& name);
    bool operator == (const PluginSpec& other);
private:
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

#endif                                            // PLUGINSPEC_H
