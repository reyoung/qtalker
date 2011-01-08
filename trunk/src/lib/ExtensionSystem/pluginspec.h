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
    class EXTENSIONSYSTEMSHARED_EXPORT PluginSpec //: public QObject
    {
        //Q_OBJECT

    public:
        enum State{
            NotLoad = 0,
            Loaded = 1,
            BeforeInit = 2,
            Inited = 4,
            Completed = 8,
            Error = -1
        };


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
        explicit PluginSpec(const QString& fn);
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
        int getState()const;
        void setState(int st);
//    signals:
        bool operator == (const QString& name);
    private:
        PluginSpecInnerData* m_data;
    };

}
#endif // PLUGINSPEC_H
