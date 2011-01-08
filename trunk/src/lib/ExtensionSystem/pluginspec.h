#ifndef PLUGINSPEC_H
#define PLUGINSPEC_H

#include <QObject>
#include <QtCore>
#include "ExtensionSystem_global.h"
namespace ExtensionSystem
{
    struct PluginSpecInnerData;/// Plugin Spec Inner Data. Plugin�ĳ�Ա����
/**
*	��ʾPlugin ������ϵ��Data
*       �������ڵ�Name����Ӧ��Version
*
*/
    struct SpecDependencyData
    {
        QString Name;
        QString Version;
    };

/**
*	Plugin Spec
*       Plugin�����ļ��ĳ���ͨ�������ļ���������Plugin
*
*/
    class EXTENSIONSYSTEMSHARED_EXPORT PluginSpec : public QObject
    {
        Q_OBJECT
    public:

//! Ĭ�Ϲ��캯�� ,��Spec�ļ���Ϊ����.
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
        explicit PluginSpec(const QString& fn,QObject *parent = 0);
        virtual ~PluginSpec();
//! ����Spec Name.
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
        QString name()const;
//! ����Plugin�İ汾.
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
        QString version()const;
//! ����Plugin������.
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
        QString author()const;
//! ����Plugin��Bug Report E-mail.
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
        QString bugReportEmail()const;

//! ���ظ�Plugin������Plugin.
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
        QList<SpecDependencyData> dependencyList()const;

        QString description()const;
        QString category()const;
        QString copyRight()const;
        QString license()const;
    signals:

    private:
        PluginSpecInnerData* m_data;
    };
}
#endif // PLUGINSPEC_H
